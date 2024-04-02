#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QGridLayout>
#include <QWidget>
#include <QToolBar> // Include QToolBar

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void toggleCreateNewSection(); // Changed from onSketchButtonClicked to toggleCreateNewSection
    void createNewFolder(const QString &folderName);
    void createNewSheet();

protected:
    void resizeEvent(QResizeEvent *event) override; // To handle resize events

private:
    Ui::MainWindow *ui;
    QStringList *folderNames;  // Stores the names of the folders
    QGridLayout *gridLayout;   // Layout to manage FolderWidgets
    QWidget *createNewSection; // Widget for the 'Create New' section
    QToolBar *toolBar;         // Toolbar for navigation

    // Additional private members and methods as needed
};

#endif // MAINWINDOW_H
