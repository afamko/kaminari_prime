#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QGridLayout>

namespace Ui {
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

private:
    Ui::MainWindow *ui;
    QStringList *folderNames;
    QGridLayout *gridLayout;
    QWidget *createNewSection;
    QToolBar *toolBar;
};

#endif // MAINWINDOW_H
