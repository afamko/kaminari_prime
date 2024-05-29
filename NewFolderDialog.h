#ifndef NEWFOLDERDIALOG_H
#define NEWFOLDERDIALOG_H

#include <QDialog>

class QLineEdit;
class QPushButton;

class NewFolderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewFolderDialog(QWidget *parent = nullptr);

    QString folderName() const;

private:
    QLineEdit *folderNameEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

private slots:
    void onOkButtonClicked();
};

#endif // NEWFOLDERDIALOG_H
