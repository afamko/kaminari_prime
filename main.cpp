#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    // Apply stylesheet to the main window for admin bar and other widgets
    QString styleSheet = "QMainWindow { "
                         "background-color: rgb(239, 239, 239); " // Main window background
                         "} "
                         "QLabel { "
                         "color: rgb(0, 0, 0); " // Text color for labels
                         "}";
    w.setStyleSheet(styleSheet);

    return app.exec();
}
