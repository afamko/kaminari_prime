#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "FolderWidget.h"
#include "NewItemDialog.h"
#include "NewFolderDialog.h"
#include "SketchPage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QScreen>
#include <QGuiApplication>
#include <QFontDatabase>
#include <QScrollArea>
#include <QToolBar>
#include <QWidgetAction>
#include <QPushButton>
#include <QToolButton>
#include <QMessageBox>
#include <QDebug>
#include <QStringList>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      folderNames(new QStringList()), gridLayout(new QGridLayout()),
      sketchPage(new SketchPage(this)), newItemDialog(nullptr) // Initialize newItemDialog to nullptr
{
    ui->setupUi(this);

    qInfo() << "Loading fonts...";
    // Load the Roboto font
    QFontDatabase::addApplicationFont(":/assets/fonts/Roboto-Black.ttf");
    QFontDatabase::addApplicationFont(":/assets/fonts/Roboto-Bold.ttf");
    QFontDatabase::addApplicationFont(":/assets/fonts/Roboto-Italic.ttf");
    QFontDatabase::addApplicationFont(":/assets/fonts/Roboto-Regular.ttf");
    QFontDatabase::addApplicationFont(":/assets/fonts/Roboto-Light.ttf");
    QFontDatabase::addApplicationFont(":/assets/fonts/Roboto-Thin.ttf");

    const int windowWidth = 500;
    const int windowHeight = windowWidth * 4 / 3;
    setFixedSize(windowWidth, windowHeight);

    QWidget *centralWidget = new QWidget(this);
    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    // Admin Bar setup
    QWidget *adminBar = new QWidget();
    adminBar->setObjectName("adminBar");
    adminBar->setStyleSheet("background-color: rgb(239, 239, 239);"
                            "border: 1px solid black;"
                            "border-width: 0px 2px 2px 2px;"
                            "border-color: transparent black black black;"
                            "border-bottom-left-radius: 6px;"
                            "border-bottom-right-radius: 6px;");
    adminBar->setFixedHeight(34);
    adminBar->setFixedWidth(static_cast<int>(windowWidth * 0.56));

    QHBoxLayout *adminLayout = new QHBoxLayout(adminBar);
    adminLayout->setContentsMargins(10, 5, 10, 5);

    // Time label - aligned towards the left
    QLabel *timeLabel = new QLabel("12:21 PM", adminBar);
    timeLabel->setStyleSheet("background-color: transparent; border: none; font-size: 16px;");
    adminLayout->addWidget(timeLabel);

    adminLayout->addStretch(2);

    // WiFi label and icon - centered
    QLabel *wifiLabel = new QLabel(adminBar);
    QPixmap wifiIcon(":/assets/icons/wifi_icon.png");
    const int wifiIconSize = 24;
    wifiIcon = wifiIcon.scaled(wifiIconSize, wifiIconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    wifiLabel->setPixmap(wifiIcon);
    wifiLabel->setFixedSize(wifiIcon.size());
    wifiLabel->setStyleSheet("background-color: transparent; border: none;");
    adminLayout->addWidget(wifiLabel);

    adminLayout->addStretch(1);

    // Battery label and icon - aligned towards the right
    QLabel *batteryLabel = new QLabel("78%", adminBar);
    batteryLabel->setStyleSheet("background-color: transparent; border: none; font-size: 16px;");
    adminLayout->addWidget(batteryLabel);

    QLabel *batteryIconLabel = new QLabel(adminBar);
    QPixmap batteryIcon(":/assets/icons/battery_icon.png");
    const int batteryIconSize = 42;
    batteryIcon = batteryIcon.scaled(batteryIconSize, batteryIconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    batteryIconLabel->setPixmap(batteryIcon);
    batteryIconLabel->setFixedSize(batteryIcon.size());
    batteryIconLabel->setStyleSheet("background-color: transparent; border: none;");
    adminLayout->addWidget(batteryIconLabel);

    // Center the admin bar within the centralWidget
    centeredAdminBarLayout = new QHBoxLayout();
    qInfo() << "centeredAdminBarLayout initialized at" << centeredAdminBarLayout;
    centeredAdminBarLayout->addStretch(1);
    centeredAdminBarLayout->addWidget(adminBar);
    centeredAdminBarLayout->addStretch(1);

    mainLayout->addLayout(centeredAdminBarLayout);

    mainLayout->addSpacing(5);

    // Initialize the toolbar
    toolBar = new QToolBar(this);
    toolBar->setStyleSheet("QToolBar { background-color: rgb(239, 239, 239); border: none; }");
    toolBar->setMovable(false);
    toolBar->setIconSize(QSize(55, 55));

    // Header section setup
    headerWidget = new QWidget();
    QVBoxLayout *headerLayout = new QVBoxLayout(headerWidget);

    // Top Row
    QWidget *topRowWidget = new QWidget();
    QHBoxLayout *topRowLayout = new QHBoxLayout(topRowWidget);

    // Add the sticky note button
    QPushButton *stickyNoteButton = new QPushButton();
    stickyNoteButton->setIcon(QIcon(":/assets/icons/sticky_note_icon.png"));
    stickyNoteButton->setIconSize(QSize(40, 40));
    stickyNoteButton->setStyleSheet("QPushButton { border: none; background-color: transparent; }");
    stickyNoteButton->setCursor(Qt::PointingHandCursor);
    topRowLayout->addWidget(stickyNoteButton);
    topRowLayout->addSpacing(62);

    // SORT BUTTON
    QWidget *sortButtonWidget = new QWidget();
    QHBoxLayout *sortButtonLayout = new QHBoxLayout(sortButtonWidget);
    sortButtonLayout->setContentsMargins(0, 0, 0, 0);
    sortButtonLayout->setSpacing(0);

    // Button for the 'Sort' icon
    QToolButton *sortIconButton = new QToolButton();
    sortIconButton->setIcon(QIcon(":/assets/icons/sort_icon.png"));
    sortIconButton->setIconSize(QSize(40, 40));
    sortIconButton->setStyleSheet("QToolButton { border: none; background-color: transparent; }");
    sortIconButton->setCursor(Qt::ArrowCursor);

    // Label for the 'Sort' text
    QLabel *sortTextLabel = new QLabel("Sort");
    QFont sortFont = sortTextLabel->font();
    sortFont.setPointSize(22);
    sortTextLabel->setFont(sortFont);
    sortTextLabel->setStyleSheet("background-color: transparent;");

    sortButtonLayout->addWidget(sortIconButton, 0, Qt::AlignVCenter | Qt::AlignLeft);
    sortButtonLayout->addWidget(sortTextLabel, 0, Qt::AlignVCenter | Qt::AlignLeft);

    topRowLayout->addWidget(sortButtonWidget);
    topRowLayout->addSpacing(10);

    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setLineWidth(2);
    topRowLayout->addWidget(line);
    line->setContentsMargins(0, 0, 0, 0);

    QWidget *filterButtonWidget = new QWidget();
    QHBoxLayout *filterButtonLayout = new QHBoxLayout(filterButtonWidget);
    filterButtonLayout->setContentsMargins(0, 0, 0, 0);
    filterButtonLayout->setSpacing(0);

    QLabel *filterTextLabel = new QLabel("Filter");
    QFont filterFont = filterTextLabel->font();
    filterFont.setPointSize(22);
    filterTextLabel->setFont(filterFont);
    filterTextLabel->setStyleSheet("background-color: transparent; margin-left: 5px;");

    QToolButton *filterIconButton = new QToolButton();
    filterIconButton->setIcon(QIcon(":/assets/icons/filter_icon.png"));
    filterIconButton->setIconSize(QSize(40, 40));
    filterIconButton->setStyleSheet("QToolButton { border: none; background-color: transparent; }");
    filterIconButton->setCursor(Qt::ArrowCursor);

    filterButtonLayout->addWidget(filterTextLabel, 0, Qt::AlignVCenter | Qt::AlignRight);

    filterButtonLayout->addSpacing(5);

    filterButtonLayout->addWidget(filterIconButton, 0, Qt::AlignVCenter | Qt::AlignLeft);

    topRowLayout->addWidget(filterButtonWidget);
    topRowLayout->addSpacing(50);

    QPushButton *searchButton = new QPushButton();
    searchButton->setIcon(QIcon(":/assets/icons/search_icon.png"));
    searchButton->setIconSize(QSize(34, 34));
    topRowLayout->addWidget(searchButton);
    searchButton->setStyleSheet("QPushButton { border: none; background-color: transparent; }");
    searchButton->setCursor(Qt::PointingHandCursor);
    headerLayout->addWidget(topRowWidget);

    QWidget *bottomRowWidget = new QWidget();
    QHBoxLayout *bottomRowLayout = new QHBoxLayout(bottomRowWidget);

    QLabel *pageTitle = new QLabel("Local Home");
    QFont defaultFont = QApplication::font();
    defaultFont.setPointSize(30);
    pageTitle->setFont(defaultFont);
    bottomRowLayout->addWidget(pageTitle);

    bottomRowLayout->addStretch(1);

    QPushButton *actionButtonD = new QPushButton();
    actionButtonD->setIcon(QIcon(":/assets/icons/d_icon.png"));
    actionButtonD->setIconSize(QSize(24, 24));
    actionButtonD->setStyleSheet("QPushButton { border: none; background-color: transparent; }");
    actionButtonD->setCursor(Qt::PointingHandCursor);
    bottomRowLayout->addWidget(actionButtonD);

    QPushButton *actionButtonG = new QPushButton();
    actionButtonG->setIcon(QIcon(":/assets/icons/g_icon.png"));
    actionButtonG->setIconSize(QSize(24, 24));
    actionButtonG->setStyleSheet("QPushButton { border: none; background-color: transparent; }");
    actionButtonG->setCursor(Qt::PointingHandCursor);
    bottomRowLayout->addWidget(actionButtonG);

    QPushButton *actionButtonO = new QPushButton();
    actionButtonO->setIcon(QIcon(":/assets/icons/o_icon.png"));
    actionButtonO->setIconSize(QSize(24, 24));
    actionButtonO->setStyleSheet("QPushButton { border: none; background-color: transparent; }");
    actionButtonO->setCursor(Qt::PointingHandCursor);
    bottomRowLayout->addWidget(actionButtonO);

    QPushButton *actionButtonTrash = new QPushButton();
    actionButtonTrash->setIcon(QIcon(":/assets/icons/trashcan_icon.png"));
    actionButtonTrash->setIconSize(QSize(30, 30));
    actionButtonTrash->setStyleSheet("QPushButton { border: none; background-color: transparent; }");
    actionButtonTrash->setCursor(Qt::PointingHandCursor);
    bottomRowLayout->addWidget(actionButtonTrash);

    headerLayout->addWidget(bottomRowWidget);

    mainLayout->addWidget(headerWidget);

    gridLayout = new QGridLayout();
    gridLayout->setSpacing(10);

    QStringList initialFolderNames = {"My Personal", "Work", "wustl", "OME", "LW",
                                      "scribble dibble", "Fathie/Sekai", "Shutter", "Mode", "Fathie/Sekai", "Shutter", "Mode", "Fathie/Sekai", "Shutter", "Mode"};

    for (int i = 0; i < initialFolderNames.size(); ++i)
    {
        FolderWidget *folder = new FolderWidget(initialFolderNames[i]);
        int row = i / 3;
        int column = i % 3;
        gridLayout->addWidget(folder, row, column);
        folderNames->append(initialFolderNames[i]);
    }

    QWidget *gridWidget = new QWidget();
    gridWidget->setLayout(gridLayout);

    scrollArea = new QScrollArea();
    scrollArea->setWidget(gridWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->viewport()->setStyleSheet("background-color: rgb(239, 239, 239);");
    scrollArea->setStyleSheet("QScrollArea { border: none; }");

    mainLayout->addWidget(scrollArea, 1);

    createNewSection = new QWidget(this);
    createNewSection->setObjectName("createNewSection");
    createNewSection->setVisible(false);

    toolBar = new QToolBar(this);
    toolBar->setStyleSheet("QToolBar { background-color: rgb(239, 239, 239); border: none; }");
    toolBar->setMovable(false);

    toolBar->setIconSize(QSize(55, 55));

    spacerLeft = new QWidget();
    spacerLeft->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spacerLeft);

    customWidgetOne = new QWidget();
    QVBoxLayout *customLayoutOne = new QVBoxLayout(customWidgetOne);
    customLayoutOne->setContentsMargins(0, 25, 0, 25);
    QLabel *iconLabelOne = new QLabel(customWidgetOne);
    iconLabelOne->setPixmap(QPixmap(":/assets/icons/action_icon.png").scaled(55, 55, Qt::KeepAspectRatio));
    customLayoutOne->addWidget(iconLabelOne, 0, Qt::AlignCenter);
    widgetActionOne = new QWidgetAction(toolBar);
    widgetActionOne->setDefaultWidget(customWidgetOne);
    toolBar->addAction(widgetActionOne);

    spacer1 = new QWidget();
    spacer1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    spacer1->setFixedWidth(26);
    toolBar->addWidget(spacer1);

    customWidgetTwo = new QWidget();
    QVBoxLayout *customLayoutTwo = new QVBoxLayout(customWidgetTwo);
    customLayoutTwo->setContentsMargins(0, 25, 0, 25);
    QToolButton *actionButtonSketch = new QToolButton();
    actionButtonSketch->setIcon(QIcon(":/assets/icons/sketch_icon.png"));
    actionButtonSketch->setIconSize(QSize(55, 55));
    actionButtonSketch->setStyleSheet("QToolButton { border: none; background-color: transparent; }");
    customLayoutTwo->addWidget(actionButtonSketch, 0, Qt::AlignCenter);

    widgetActionTwo = new QWidgetAction(toolBar);
    widgetActionTwo->setDefaultWidget(customWidgetTwo);
    toolBar->addAction(widgetActionTwo);

    spacer2 = new QWidget();
    spacer2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    spacer2->setFixedWidth(26);
    toolBar->addWidget(spacer2);

    customWidgetThree = new QWidget();
    QVBoxLayout *customLayoutThree = new QVBoxLayout(customWidgetThree);
    customLayoutThree->setContentsMargins(0, 25, 0, 25);
    QLabel *iconLabelThree = new QLabel(customWidgetThree);
    iconLabelThree->setPixmap(QPixmap(":/assets/icons/settings_icon.png").scaled(55, 55, Qt::KeepAspectRatio));
    customLayoutThree->addWidget(iconLabelThree, 0, Qt::AlignCenter);
    widgetActionThree = new QWidgetAction(toolBar);
    widgetActionThree->setDefaultWidget(customWidgetThree);
    toolBar->addAction(widgetActionThree);

    spacerRight = new QWidget();
    spacerRight->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spacerRight);

    int rightSpacerWidth = 1;
    QWidget *additionalSpacerRight = new QWidget();
    additionalSpacerRight->setFixedWidth(rightSpacerWidth);
    toolBar->addWidget(additionalSpacerRight);

    this->addToolBar(Qt::BottomToolBarArea, toolBar);

    connect(actionButtonSketch, &QToolButton::clicked, this, &MainWindow::showNewItemDialog);

    createNewSection->setGeometry(0, height() - createNewSection->height(), width(), createNewSection->height());
    createNewSection->setVisible(false);

    connect(actionButtonSketch, &QToolButton::clicked, this, &MainWindow::showNewItemDialog);

    setCentralWidget(centralWidget);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    createNewSection->setGeometry(0, height() - createNewSection->height(), width(), createNewSection->height());
    if (createNewSection->isVisible())
    {
        createNewSection->raise();
    }
}

void MainWindow::showNewItemDialog()
{
    if (sketchPageActive)
    {
        showSketchPage();
    }
    else
    {
        if (newItemDialog == nullptr || !newItemDialog->isVisible())
        {
            newItemDialog = new NewItemDialog(this);
            newItemDialog->setAttribute(Qt::WA_DeleteOnClose);

            connect(newItemDialog, &NewItemDialog::newFolderRequested, this, &MainWindow::createNewFolder);

            connect(newItemDialog, &NewItemDialog::newSheetRequested, this, [this]()
                    {
                        if (newItemDialog)
                        {
                            newItemDialog->close();
                            newItemDialog = nullptr;
                        }
                        QTimer::singleShot(0, this, &MainWindow::showSketchPage); });

            newItemDialog->show();
        }
    }
}

void MainWindow::toggleCreateNewSection()
{
    bool isVisible = createNewSection->isVisible();
    createNewSection->setVisible(!isVisible);

    if (!isVisible)
    {
        createNewSection->raise();
    }
    else
    {
        toolBar->raise();
    }
}

void MainWindow::createNewFolder(const QString &folderName)
{
    if (!gridLayout)
    {
        return;
    }

    if (!folderNames)
    {
        return;
    }

    folderNames->append(folderName);

    FolderWidget *newFolderWidget = new FolderWidget(folderName, this);
    int row = (folderNames->size() - 1) / 3;
    int column = (folderNames->size() - 1) % 3;
    gridLayout->addWidget(newFolderWidget, row, column);
}

void MainWindow::createNewSheet()
{
    QMessageBox::information(this, "Action", "Create New Sheet action triggered");
}

void MainWindow::showSketchPage()
{
    // Hide the current central widget
    QWidget *currentCentralWidget = centralWidget();
    if (currentCentralWidget)
    {
        currentCentralWidget->hide();
    }

    // Set the sketch page as the new central widget
    setCentralWidget(sketchPage);
    sketchPage->show();

    // Change the toolbar to show the home button instead of the sketch button
    toolBar->clear();

    // Add stretchable spacers to center the icons
    QWidget *spacerLeft = new QWidget();
    spacerLeft->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spacerLeft);

    // Custom widget for the first icon with increased padding
    QWidget *customWidgetOne = new QWidget();
    QVBoxLayout *customLayoutOne = new QVBoxLayout(customWidgetOne);
    customLayoutOne->setContentsMargins(0, 25, 0, 25); // Adjust the top and bottom margin as needed
    QLabel *iconLabelOne = new QLabel(customWidgetOne);
    iconLabelOne->setPixmap(QPixmap(":/assets/icons/action_icon.png").scaled(55, 55, Qt::KeepAspectRatio));
    customLayoutOne->addWidget(iconLabelOne, 0, Qt::AlignCenter);
    QWidgetAction *widgetActionOne = new QWidgetAction(toolBar);
    widgetActionOne->setDefaultWidget(customWidgetOne);
    toolBar->addAction(widgetActionOne);

    // Spacer between the icons
    QWidget *spacer1 = new QWidget();
    spacer1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    spacer1->setFixedWidth(26); // Set your desired width
    toolBar->addWidget(spacer1);

    // Custom widget for the home button with increased padding and elevation
    QWidget *customWidgetHome = new QWidget();
    QVBoxLayout *customLayoutHome = new QVBoxLayout(customWidgetHome);
    customLayoutHome->setContentsMargins(0, 10, 0, 25); // Adjust the top margin for elevation
    QPushButton *homeButton = new QPushButton();
    homeButton->setIcon(QIcon(":/assets/icons/homescreen_icon.png"));
    homeButton->setIconSize(QSize(55, 55));
    homeButton->setStyleSheet("QPushButton { border: none; background-color: transparent; }");
    customLayoutHome->addWidget(homeButton, 0, Qt::AlignCenter);
    QWidgetAction *widgetActionHome = new QWidgetAction(toolBar);
    widgetActionHome->setDefaultWidget(customWidgetHome);
    toolBar->addAction(widgetActionHome);
    connect(homeButton, &QPushButton::clicked, this, &MainWindow::showHomePage);

    // Spacer between the icons
    QWidget *spacer2 = new QWidget();
    spacer2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    spacer2->setFixedWidth(26); // Set your desired width
    toolBar->addWidget(spacer2);

    // Custom widget for the third icon with increased padding
    QWidget *customWidgetThree = new QWidget();
    QVBoxLayout *customLayoutThree = new QVBoxLayout(customWidgetThree);
    customLayoutThree->setContentsMargins(0, 25, 0, 25); // Adjust the top and bottom margin as needed
    QLabel *iconLabelThree = new QLabel(customWidgetThree);
    iconLabelThree->setPixmap(QPixmap(":/assets/icons/settings_icon.png").scaled(55, 55, Qt::KeepAspectRatio));
    customLayoutThree->addWidget(iconLabelThree, 0, Qt::AlignCenter);
    QWidgetAction *widgetActionThree = new QWidgetAction(toolBar);
    widgetActionThree->setDefaultWidget(customWidgetThree);
    toolBar->addAction(widgetActionThree);

    // Add stretchable spacer to the right
    QWidget *spacerRight = new QWidget();
    spacerRight->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spacerRight);

    // Mark sketch page as active
    sketchPageActive = true;
}

// mainwindow.cpp

void MainWindow::showHomePage()
{
    qInfo() << "Entering showHomePage()";

    // Remove the current central widget
    QWidget *currentCentralWidget = centralWidget();
    if (currentCentralWidget)
    {
        currentCentralWidget->hide();
        currentCentralWidget->deleteLater(); // Use deleteLater instead of delete
    }

    // Create a new central widget and layout
    QWidget *newCentralWidget = new QWidget(this);
    QVBoxLayout *newMainLayout = new QVBoxLayout(newCentralWidget);
    newMainLayout->setContentsMargins(0, 0, 0, 0);

    // Check centeredAdminBarLayout initialization
    if (!centeredAdminBarLayout)
    {
        qCritical() << "centeredAdminBarLayout is not initialized!";
        return;
    }

    // Remove centeredAdminBarLayout from its current parent
    if (centeredAdminBarLayout->parentWidget())
    {
        centeredAdminBarLayout->parentWidget()->layout()->removeItem(centeredAdminBarLayout);
    }

    // Check if centeredAdminBarLayout already has a parent
    qInfo() << "centeredAdminBarLayout address:" << centeredAdminBarLayout;
    QObject *parentObj = centeredAdminBarLayout->parent();
    if (parentObj)
    {
        qInfo() << "centeredAdminBarLayout parent address:" << parentObj;
        qInfo() << "centeredAdminBarLayout parent class:" << parentObj->metaObject()->className();
    }
    else
    {
        qInfo() << "centeredAdminBarLayout does not have a parent.";
    }

    qInfo() << "Adding centeredAdminBarLayout to newMainLayout...";
    try
    {
        newMainLayout->addLayout(centeredAdminBarLayout);
        qInfo() << "Layout added successfully.";
    }
    catch (const std::exception &e)
    {
        qCritical() << "Exception caught while adding centeredAdminBarLayout: " << e.what();
        return;
    }

    newMainLayout->addSpacing(5);
    newMainLayout->addWidget(headerWidget);

    // Create a new scroll area and grid layout for folders
    QScrollArea *newScrollArea = new QScrollArea();
    QWidget *newGridWidget = new QWidget();
    QGridLayout *newGridLayout = new QGridLayout(newGridWidget);
    newGridLayout->setSpacing(10);

    for (int i = 0; i < folderNames->size(); ++i)
    {
        FolderWidget *folder = new FolderWidget((*folderNames)[i]);
        int row = i / 3;
        int column = i % 3;
        newGridLayout->addWidget(folder, row, column);
    }

    newGridWidget->setLayout(newGridLayout);
    newScrollArea->setWidget(newGridWidget);
    newScrollArea->setWidgetResizable(true);
    newScrollArea->viewport()->setStyleSheet("background-color: rgb(239, 239, 239);");
    newScrollArea->setStyleSheet("QScrollArea { border: none; }");

    newMainLayout->addWidget(newScrollArea, 1);
    newCentralWidget->setLayout(newMainLayout); // Ensure the layout is set for the new central widget
    setCentralWidget(newCentralWidget);

    // Clear the toolbar and re-add the original widgets and actions
    toolBar->clear();

    // Add stretchable spacers to center the icons
    toolBar->addWidget(spacerLeft);
    toolBar->addAction(widgetActionOne);
    toolBar->addWidget(spacer1);
    toolBar->addAction(widgetActionTwo);
    toolBar->addWidget(spacer2);
    toolBar->addAction(widgetActionThree);
    toolBar->addWidget(spacerRight);

    // Mark sketch page as inactive
    sketchPageActive = false;

    // Reassign member variables to prevent invalid access
    scrollArea = newScrollArea;
    gridLayout = newGridLayout;

    qInfo() << "Exiting showHomePage()";
}

MainWindow::~MainWindow()
{
    delete ui;
    delete folderNames;
    delete gridLayout;
    if (newItemDialog)
    {
        newItemDialog->deleteLater();
    }
}
