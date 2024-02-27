#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "FolderWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Admin Bar setup
    QWidget *adminBar = new QWidget(centralWidget);
    adminBar->setObjectName("adminBar");  // Set object name for the admin bar
    QHBoxLayout *adminLayout = new QHBoxLayout(adminBar);
    adminLayout->setContentsMargins(10, 0, 10, 0); // Margin adjustment to match wireframe

    QLabel *timeLabel = new QLabel("12:21 PM");
    adminLayout->addWidget(timeLabel);

    adminLayout->addSpacerItem(new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum)); // Expanding spacer

    QLabel *batteryLabel = new QLabel("78%");
    QPixmap batteryIcon(":/icons/battery_icon.png");
    QLabel *batteryIconLabel = new QLabel();
    batteryIconLabel->setPixmap(batteryIcon.scaled(24, 24, Qt::KeepAspectRatio)); // Scale icon size as needed
    adminLayout->addWidget(batteryIconLabel);
    adminLayout->addWidget(batteryLabel);

    QLabel *wifiLabel = new QLabel();
    QPixmap wifiIcon(":/icons/wifi_icon.png");
    wifiLabel->setPixmap(wifiIcon.scaled(24, 24, Qt::KeepAspectRatio)); // Scale icon size as needed
    adminLayout->addWidget(wifiLabel);

    mainLayout->addWidget(adminBar);

    // Rest of the code for Folder Grid setup...

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
