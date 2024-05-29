#include "NewFolderDialog.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

NewFolderDialog::NewFolderDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Enter folder name:", this);
    layout->addWidget(label);

    folderNameEdit = new QLineEdit(this);
    layout->addWidget(folderNameEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();

    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Cancel", this);

    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    layout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, this, &NewFolderDialog::onOkButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

QString NewFolderDialog::folderName() const
{
    return folderNameEdit->text();
}

void NewFolderDialog::onOkButtonClicked()
{
    if (!folderNameEdit->text().isEmpty())
    {
        accept();
    }
}
