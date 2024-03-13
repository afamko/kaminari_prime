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



    QAction *actionOne = new QAction(QIcon(":/assets/icons/action_icon.png"), "First", this);
    QAction *actionTwo = new QAction(QIcon(":/assets/icons/sketch_icon.png"), "Second", this);
    QAction *actionThree = new QAction(QIcon(":/assets/icons/settings_icon.png"), "Third", this);

    toolBar->addAction(actionOne);

    // Add an invisible widget as a spacer
    QWidget *spacer1 = new QWidget();
    spacer1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    spacer1->setFixedWidth(26); // Set your desired width
    toolBar->addWidget(spacer1);


    toolBar->addAction(actionTwo);

    // Add an invisible widget as a spacer
    QWidget *spacer2 = new QWidget();
    spacer2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    spacer2->setFixedWidth(26); // Set your desired width
    toolBar->addWidget(spacer2);


    toolBar->addAction(actionThree);

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
