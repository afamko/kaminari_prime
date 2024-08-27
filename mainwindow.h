#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QGridLayout>
#include <QScrollArea>
#include <QWidgetAction>
#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "SketchPage.h"
#include "NewItemDialog.h"

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
    void showSketchPage();
    void showHomePage();

private:
    Ui::MainWindow *ui;
    QStringList *folderNames;
    QGridLayout *gridLayout;
    QWidget *createNewSection;
    QToolBar *toolBar;
    SketchPage *sketchPage;
    bool sketchPageActive = false;
    bool sketchPageFirstAccess = true;    // Flag to track first access to Sketch Page
    bool isFirstSketchButtonClick = true; // Flag to track the first click of the Sketch button

    QVBoxLayout *mainLayout;
    QHBoxLayout *centeredAdminBarLayout;
    QWidget *headerWidget;
    QScrollArea *scrollArea;

    QWidgetAction *widgetActionOne;
    QWidgetAction *widgetActionTwo;
    QWidgetAction *widgetActionThree;

    QWidget *spacerLeft;
    QWidget *spacer1;
    QWidget *spacer2;
    QWidget *spacerRight;

    NewItemDialog *newItemDialog;

    QWidget *customWidgetOne;
    QWidget *customWidgetTwo;
    QWidget *customWidgetThree;

    QWidget *adminBar; // Add this line
};

#endif // MAINWINDOW_H