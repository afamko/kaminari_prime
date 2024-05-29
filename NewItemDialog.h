#ifndef NEWITEMDIALOG_H
#define NEWITEMDIALOG_H

#include <QDialog>

class QVBoxLayout;
class QPushButton;

class NewItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewItemDialog(QWidget *parent = nullptr);

signals:
    void newFolderRequested(const QString &folderName);
    void newSheetRequested();

private slots:
    void onNewFolder();
    void onNewSheet();

private:
    void positionAtBottom(QWidget *parent);
};

#endif // NEWITEMDIALOG_H
