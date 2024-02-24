#include "mainwindow.h"
#include "FolderWidget.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QStatusBar>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "kaminari_prime_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;

    // Set the background color of the main window using RGB values
    //w.setStyleSheet("background-color: rgb(211, 211, 211);"); // This is equivalent to light grey

    // Create the admin bar at the top
    QWidget* adminBar = new QWidget();
    QHBoxLayout* adminLayout = new QHBoxLayout(adminBar);
    QLabel* timeLabel = new QLabel("12:21 PM");
    adminLayout->addWidget(timeLabel);

    // Add battery label next to the time
    QLabel* batteryLabel = new QLabel("78%"); // Create label with text only
    QPixmap batteryIcon(":/icons/battery_icon.png"); // Load the icon
    batteryLabel->setPixmap(batteryIcon); // Set the icon to the label
    adminLayout->addWidget(batteryLabel); // Add battery label to status bar

    // Add other widgets like WiFi signal, etc., to the status bar here
    QLabel* wifiLabel = new QLabel(); // Create an empty label
    QPixmap wifiIcon(":/icons/wifi_icon.png"); // Load the icon
    wifiLabel->setPixmap(wifiIcon); // Set the icon to the label
    adminLayout->addWidget(wifiLabel); // Add WiFi label to status bar

    // Create a grid layout for the folders
    QGridLayout* gridLayout = new QGridLayout();
    QStringList folderNames = {"My Personal", "Work", "Wustl", "OME", "LW", "Scribble Dibble"}; // Example folder names

    // Add FolderWidgets to the grid layout
    for (int i = 0; i < folderNames.size(); ++i) {
        FolderWidget* folder = new FolderWidget(folderNames[i]);
        int row = i / 3;
        int column = i % 3;
        gridLayout->addWidget(folder, row, column);
    }

    // Main layout that includes the admin bar and the grid layout
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(adminBar); // Add the admin bar to the top
    mainLayout->addLayout(gridLayout); // Add the grid layout below the admin bar

    // Set the layout to the central widget
    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout); // Set mainLayout as the layout for centralWidget
    w.setCentralWidget(centralWidget);

    w.show();
    return app.exec();
}
