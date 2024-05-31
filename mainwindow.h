#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QGridLayout>
#include "SketchPage.h" // Include the SketchPage header

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void showNewItemDialog();
    void toggleCreateNewSection();
    void createNewFolder(const QString &folderName);
    void createNewSheet();
    void showSketchPage(); // Slot for showing the sketch page

private:
    Ui::MainWindow *ui;
    QStringList *folderNames;
    QGridLayout *gridLayout;
    QWidget *createNewSection;
    QToolBar *toolBar;
    SketchPage *sketchPage; // Member variable for the sketch page
};

#endif // MAINWINDOW_H
