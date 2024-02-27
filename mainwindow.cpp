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
    QHBoxLayout *adminLayout = new QHBoxLayout(adminBar);
    QLabel *timeLabel = new QLabel("12:21 PM");
    adminLayout->addWidget(timeLabel);

    QLabel *batteryLabel = new QLabel("78%");
    QPixmap batteryIcon(":/icons/battery_icon.png");
    batteryLabel->setPixmap(batteryIcon);
    adminLayout->addWidget(batteryLabel);

    QLabel *wifiLabel = new QLabel();
    QPixmap wifiIcon(":/icons/wifi_icon.png");
    wifiLabel->setPixmap(wifiIcon);
    adminLayout->addWidget(wifiLabel);

    mainLayout->addWidget(adminBar);

    // Folder Grid setup
    QGridLayout *gridLayout = new QGridLayout();
    QStringList folderNames = {"My Personal", "Work", "Wustl", "OME", "LW", "Scribble Dibble"};

    for (int i = 0; i < folderNames.size(); ++i) {
        FolderWidget *folder = new FolderWidget(folderNames[i]);
        int row = i / 3;  // Assuming 3 columns
        int column = i % 3;
        gridLayout->addWidget(folder, row, column);
    }

    mainLayout->addLayout(gridLayout);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
