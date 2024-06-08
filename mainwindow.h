#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QGridLayout>
#include "SketchPage.h"
#include <QScrollArea>
#include <QWidgetAction>
#include "NewItemDialog.h" // Include the NewItemDialog header

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
    void showHomePage();   // Slot for showing the home page

private:
    Ui::MainWindow *ui;
    QStringList *folderNames;
    QGridLayout *gridLayout;
    QWidget *createNewSection;
    QToolBar *toolBar;
    SketchPage *sketchPage;        // Member variable for the sketch page
    bool sketchPageActive = false; // To keep track of whether the sketch page is active

    // Member variables for UI elements to restore on home page
    QVBoxLayout *mainLayout;
    QHBoxLayout *centeredAdminBarLayout;
    QWidget *headerWidget;
    QScrollArea *scrollArea;

    // Member variables for toolbar actions
    QWidgetAction *widgetActionOne;
    QWidgetAction *widgetActionTwo;
    QWidgetAction *widgetActionThree;

    QWidget *spacerLeft;
    QWidget *spacer1;
    QWidget *spacer2;
    QWidget *spacerRight;

    NewItemDialog *newItemDialog; // Declare newItemDialog as a member variable
};

#endif // MAINWINDOW_H
