#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onSketchButtonClicked();
    void createNewFolder(const QString &folderName);
    void createNewSheet();  // Assuming this is also connected to some UI action

private:
    Ui::MainWindow *ui;
    QStringList *folderNames;    // Stores the names of the folders
    QGridLayout *gridLayout;    // Layout to manage FolderWidgets

    // Additional private members and methods as needed
};

#endif // MAINWINDOW_H
