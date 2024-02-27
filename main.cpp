#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.setObjectName("mainWindow"); // Set object name for the main window
    w.show();

    // Apply stylesheet to the main window for admin bar and other widgets
    QString styleSheet = "QMainWindow#mainWindow { "
                         "background-color: rgb(200, 200, 200); " // Main window background
                         "} "
                         "QWidget#adminBar { "
                         "background-color: rgb(255, 255, 255); " // Admin bar background
                         "border-bottom: 1px solid rgb(0, 0, 0); " // Admin bar bottom border
                         "} "
                         "QLabel { "
                         "color: rgb(0, 0, 0); " // Text color for labels
                         "}";
    w.setStyleSheet(styleSheet);

    return app.exec();
}
