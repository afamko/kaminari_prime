#ifndef NEWITEMDIALOG_H
#define NEWITEMDIALOG_H

#include <QDialog>

class QVBoxLayout;
class QPushButton;

class NewItemDialog : public QDialog {
    Q_OBJECT

public:
    explicit NewItemDialog(QWidget *parent = nullptr);

private slots:
    void onNewFolder();
    void onNewSheet();
};

#endif // NEWITEMDIALOG_H
