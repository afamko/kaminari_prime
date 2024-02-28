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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Load the Roboto font
    int fontId = QFontDatabase::addApplicationFont(":/assets/Roboto-Bold.ttf"); // Adjust the path to your font file
    QFont robotoFont;
    if (fontId != -1) {
        QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
        robotoFont.setFamily(fontFamily);
        robotoFont.setPointSize(20); // Set the font size to 20
    } else {
        // Handle the error, use a default font, or set a fallback
        qDebug() << "Failed to load the Roboto font. Falling back to default font.";
    }


    const int windowWidth = 500; // Width in pixels
    const int windowHeight = windowWidth * 4 / 3; // Height in pixels to maintain a 3:4 ratio
    setFixedSize(windowWidth, windowHeight); // Set the fixed size for the window

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0); // Remove margins around the layout

    // Admin Bar setup
    QWidget *adminBar = new QWidget();
    adminBar->setObjectName("adminBar");
    adminBar->setStyleSheet("background-color: rgb(200, 200, 200);"
                        "border: 1px solid black;"
                        "border-width: 0px 2px 2px 2px;" // Top border set to 0px
                        "border-color: transparent black black black;" // Top border color transparent
                        "border-bottom-left-radius: 8px;"  // Adjust the radius as needed
                        "border-bottom-right-radius: 8px;");  // Adjust the radius as ne
    adminBar->setFixedHeight(35);
    adminBar->setFixedWidth(static_cast<int>(windowWidth * 0.7)); // 70% of window width
    
    QHBoxLayout *adminLayout = new QHBoxLayout(adminBar);
    adminLayout->setContentsMargins(10, 10, 10, 10); // Adjust padding to ensure space for larger text
    adminLayout->setSpacing(10); // Remove spacing between elements

    // Add a single spacer item to push content to the right
    adminLayout->addSpacerItem(new QSpacerItem(1, 10, QSizePolicy::Expanding, QSizePolicy::Minimum)); 

    // Time label
    QLabel *timeLabel = new QLabel("12:21 PM", adminBar);
    timeLabel->setStyleSheet("background-color: transparent; border: none; font-size: 20px;");
    adminLayout->addWidget(timeLabel);
    adminLayout->addSpacing(160); // Adjust this value as needed for visual separation

    // Battery label and icon
    QLabel *batteryLabel = new QLabel("78%", adminBar);
    batteryLabel->setStyleSheet("background-color: transparent; border: none; font-size: 20px;");
    QPixmap batteryIcon(":/icons/battery_icon.png");
    QLabel *batteryIconLabel = new QLabel(adminBar);
    batteryIconLabel->setPixmap(batteryIcon.scaled(24, 24, Qt::KeepAspectRatio));
    batteryIconLabel->setStyleSheet("background-color: transparent; border: none;");
    adminLayout->addWidget(batteryIconLabel);
    adminLayout->addWidget(batteryLabel);

    // WiFi label and icon
    QLabel *wifiLabel = new QLabel(adminBar);
    QPixmap wifiIcon(":/icons/wifi_icon.png");
    wifiLabel->setPixmap(wifiIcon.scaled(24, 24, Qt::KeepAspectRatio));
    wifiLabel->setStyleSheet("background-color: transparent; border: none;");
    adminLayout->addWidget(wifiLabel);

    // Center the admin bar within the centralWidget
    QHBoxLayout *centeredAdminBarLayout = new QHBoxLayout();
    centeredAdminBarLayout->addStretch();
    centeredAdminBarLayout->addWidget(adminBar);
    centeredAdminBarLayout->addStretch();

    mainLayout->addLayout(centeredAdminBarLayout);

    mainLayout->addSpacing(5); // Add some spacing between the admin bar and the rest of the content

    // Folder Grid setup
    QGridLayout *gridLayout = new QGridLayout();
    QStringList folderNames = {"My Personal", "Work", "wustl", "OME", "LW", "scribble dibble"};

    for (int i = 0; i < folderNames.size(); ++i) {
        FolderWidget *folder = new FolderWidget(folderNames[i], adminBar);
        int row = i / 3;
        int column = i % 3;
        gridLayout->addWidget(folder, row, column);
    }

    QWidget *gridWidget = new QWidget(centralWidget);
    gridWidget->setLayout(gridLayout);
    mainLayout->addWidget(gridWidget, 1); // Add grid widget to main layout and let it expand

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
