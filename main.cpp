#include "mainwindow.h"
#include "FolderWidget.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
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

    // Create the admin bar at the top
    auto statusBar = w.statusBar(); // Using the existing status bar for convenience
    statusBar->setSizeGripEnabled(false); // Disable the resize grip

    // Add time label to the right side of the status bar
    QLabel* timeLabel = new QLabel("12:21 PM");
    statusBar->addPermanentWidget(timeLabel);

    // Add battery label next to the time
    // Create the QLabel for the battery indicator
    QLabel* batteryLabel = new QLabel("78%"); // Create label with text only
    QPixmap batteryIcon(":/icons/battery_icon.png"); // Load the icon
    batteryLabel->setPixmap(batteryIcon); // Set the icon to the label
    statusBar->addPermanentWidget(batteryLabel); // Add battery label to status bar


    // Add other widgets like WiFi signal, etc., to the status bar here
    // Create the QLabel for the WiFi indicator
    QLabel* wifiLabel = new QLabel(); // Create an empty label
    QPixmap wifiIcon(":/icons/wifi_icon.png"); // Load the icon
    wifiLabel->setPixmap(wifiIcon); // Set the icon to the label
    statusBar->addPermanentWidget(wifiLabel); // Add WiFi label to status bar


    // Create a grid layout for the folders
    QGridLayout* gridLayout = new QGridLayout();

    // Add FolderWidgets to the grid layout
    for (int i = 0; i < 9; ++i) {
        FolderWidget* folder = new FolderWidget(); // Your custom widget to represent a folder
        int row = i / 3;
        int column = i % 3;
        gridLayout->addWidget(folder, row, column);
    }

    // Set the layout to the central widget
    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(gridLayout);
    w.setCentralWidget(centralWidget);

    w.show();
    return app.exec();
}
