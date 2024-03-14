#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "FolderWidget.h"
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



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load the Roboto font
    QFontDatabase::addApplicationFont(":/assets/Roboto-Bold.ttf");
    QFont robotoFont("Roboto", 20);


    const int windowWidth = 500; // Width in pixels
    const int windowHeight = windowWidth * 4 / 3; // Height in pixels to maintain a 3:4 ratio
    setFixedSize(windowWidth, windowHeight); // Set the fixed size for the window

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0); // Remove margins around the layout

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
    adminBar->setFixedWidth(static_cast<int>(windowWidth * 0.56)); // 60% of window width

    QHBoxLayout *adminLayout = new QHBoxLayout(adminBar);
    adminLayout->setContentsMargins(10, 5, 10, 5); // Adjusted top and bottom padding

    // Time label - aligned towards the left
    QLabel *timeLabel = new QLabel("12:21 PM", adminBar);
    timeLabel->setStyleSheet("background-color: transparent; border: none; font-size: 16px;");
    adminLayout->addWidget(timeLabel);

    adminLayout->addStretch(2); // Add stretchable space for centering

    // WiFi label and icon - centered
    QLabel *wifiLabel = new QLabel(adminBar);
    QPixmap wifiIcon(":/assets/icons/wifi_icon.png");
    const int wifiIconSize = 24; // The desired icon size for WiFi
    wifiIcon = wifiIcon.scaled(wifiIconSize, wifiIconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    wifiLabel->setPixmap(wifiIcon);
    wifiLabel->setFixedSize(wifiIcon.size());
    wifiLabel->setStyleSheet("background-color: transparent; border: none;");
    adminLayout->addWidget(wifiLabel);

    adminLayout->addStretch(1); // Add another stretchable space for even spacing

    // Battery label and icon - aligned towards the right
    QLabel *batteryLabel = new QLabel("78%", adminBar);
    batteryLabel->setStyleSheet("background-color: transparent; border: none; font-size: 16px;");
    adminLayout->addWidget(batteryLabel);

    // Adjust the margin to the right of the batteryLabel to bring it closer to the battery icon
    //batteryLabel->setContentsMargins(20, 0, 0, 0); // Negative right margin to reduce space

    QLabel *batteryIconLabel = new QLabel(adminBar);
    QPixmap batteryIcon(":/assets/icons/battery_icon.png");
    const int batteryIconSize = 42; // Increased icon size for battery
    batteryIcon = batteryIcon.scaled(batteryIconSize, batteryIconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    batteryIconLabel->setPixmap(batteryIcon);
    batteryIconLabel->setFixedSize(batteryIcon.size());
    batteryIconLabel->setStyleSheet("background-color: transparent; border: none;");
    adminLayout->addWidget(batteryIconLabel);

    // Center the admin bar within the centralWidget
    QHBoxLayout *centeredAdminBarLayout = new QHBoxLayout();
    centeredAdminBarLayout->addStretch(1); // Stretchable space to the left of the admin bar
    centeredAdminBarLayout->addWidget(adminBar);
    centeredAdminBarLayout->addStretch(1); // Stretchable space to the right of the admin bar

    mainLayout->addLayout(centeredAdminBarLayout);

    mainLayout->addSpacing(5); // Add some spacing between the admin bar and the rest of the content


    // Header section setup
    QWidget *headerWidget = new QWidget();
    QVBoxLayout *headerLayout = new QVBoxLayout(headerWidget);

    // Top Row
    QWidget *topRowWidget = new QWidget();
    QHBoxLayout *topRowLayout = new QHBoxLayout(topRowWidget);

    // Add the sticky note button
    QPushButton *stickyNoteButton = new QPushButton();
    stickyNoteButton->setIcon(QIcon(":/assets/icons/sticky_note_icon.png"));
    stickyNoteButton->setIconSize(QSize(30, 30));
    topRowLayout->addWidget(stickyNoteButton);

    // Add the search button
    QPushButton *searchButton = new QPushButton();
    searchButton->setIcon(QIcon(":/assets/icons/search_icon.png"));
    searchButton->setIconSize(QSize(30, 30));
    topRowLayout->addWidget(searchButton);

    // Add the sort/filter buttons
    QPushButton *sortButton = new QPushButton("Sort");
    QPushButton *filterButton = new QPushButton("Filter");
    topRowLayout->addWidget(sortButton);
    topRowLayout->addWidget(filterButton);

    headerLayout->addWidget(topRowWidget);


    // Bottom Row
    QWidget *bottomRowWidget = new QWidget();
    QHBoxLayout *bottomRowLayout = new QHBoxLayout(bottomRowWidget);

    // Add the page title to the bottom row layout
    QLabel *pageTitle = new QLabel("Local Home");
    pageTitle->setFont(robotoFont);
    bottomRowLayout->addWidget(pageTitle);

    // Add stretch after title to push icons to the right
    bottomRowLayout->addStretch(1);

    // Add action icons (D, G, O, trash can)
    QPushButton *actionButtonD = new QPushButton();
    actionButtonD->setIcon(QIcon(":/assets/icons/d_icon.png"));
    actionButtonD->setIconSize(QSize(24, 24));
    bottomRowLayout->addWidget(actionButtonD);

    // For example, with QPushButton:
    QPushButton *actionButtonG = new QPushButton();
    actionButtonG->setIcon(QIcon(":/assets/icons/g_icon.png"));
    actionButtonG->setIconSize(QSize(24, 24)); // Adjust size as needed
    bottomRowLayout->addWidget(actionButtonG);

    // For example, with QPushButton:
    QPushButton *actionButtonO = new QPushButton();
    actionButtonO->setIcon(QIcon(":/assets/icons/o_icon.png"));
    actionButtonO->setIconSize(QSize(24, 24)); // Adjust size as needed
    bottomRowLayout->addWidget(actionButtonO);

    // For example, with QPushButton:
    QPushButton *actionButtonTrash = new QPushButton();
    actionButtonTrash->setIcon(QIcon(":/assets/icons/trashcan_icon.png"));
    actionButtonTrash->setIconSize(QSize(24, 24)); // Adjust size as needed
    bottomRowLayout->addWidget(actionButtonTrash);

    headerLayout->addWidget(bottomRowWidget);

    // Add header layout to main layout before the scroll area
    mainLayout->addWidget(headerWidget);

    // Create a grid layout to hold the FolderWidgets
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSpacing(10);  // Adjust spacing as needed

    // List of folder names
    QStringList folderNames = {"My Personal", "Work", "wustl", "OME", "LW", 
                               "scribble dibble", "Fathie/Sekai", "Shutter", "Mode", "Fathie/Sekai", "Shutter", "Mode", "Fathie/Sekai", "Shutter", "Mode"};

    // Populate the grid layout with FolderWidgets
    for (int i = 0; i < folderNames.size(); ++i) {
        FolderWidget *folder = new FolderWidget(folderNames[i]);
        int row = i / 3;
        int column = i % 3;
        gridLayout->addWidget(folder, row, column);
    }

    // Wrap the grid layout in a widget
    QWidget *gridWidget = new QWidget();
    gridWidget->setLayout(gridLayout);

    // Create a scroll area and set the grid layout widget as its child
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidget(gridWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->viewport()->setStyleSheet("background-color: rgb(239, 239, 239);");
    scrollArea->setStyleSheet("QScrollArea { border: none; }");  // Remove border from scroll area


    // Add the scroll area to the main layout
    mainLayout->addWidget(scrollArea, 1);

    // Navigation Bar Setup
    QToolBar *toolBar = new QToolBar;
    toolBar->setStyleSheet("QToolBar { background-color: rgb(239, 239, 239); border: none; }");
    toolBar->setMovable(false);

    // Set the icon size to be twice as large
    toolBar->setIconSize(QSize(55, 55));  // Replace iconWidth and iconHeight with actual values

    // Add stretchable spacers to center the icons
    QWidget* spacerLeft = new QWidget();
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

    // Repeat the custom widget process for the second icon
    QWidget *customWidgetTwo = new QWidget();
    QVBoxLayout *customLayoutTwo = new QVBoxLayout(customWidgetTwo);
    customLayoutTwo->setContentsMargins(0, 25, 0, 25); // Adjust the top and bottom margin as needed
    QLabel *iconLabelTwo = new QLabel(customWidgetTwo);
    iconLabelTwo->setPixmap(QPixmap(":/assets/icons/sketch_icon.png").scaled(55, 55, Qt::KeepAspectRatio));
    customLayoutTwo->addWidget(iconLabelTwo, 0, Qt::AlignCenter);
    QWidgetAction *widgetActionTwo = new QWidgetAction(toolBar);
    widgetActionTwo->setDefaultWidget(customWidgetTwo);
    toolBar->addAction(widgetActionTwo);

    // Spacer between the icons
    QWidget *spacer2 = new QWidget();
    spacer2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    spacer2->setFixedWidth(26); // Set your desired width
    toolBar->addWidget(spacer2);

    // Repeat the custom widget process for the third icon
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
    QWidget* spacerRight = new QWidget();
    spacerRight->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spacerRight);

    this->addToolBar(Qt::BottomToolBarArea, toolBar);


    // Set the central widget
    setCentralWidget(centralWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
