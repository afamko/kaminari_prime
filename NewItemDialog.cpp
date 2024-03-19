#include "NewItemDialog.h"
#include <QVBoxLayout>
#include <QPushButton>

NewItemDialog::NewItemDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *newFolderButton = new QPushButton("New Folder", this);
    connect(newFolderButton, &QPushButton::clicked, this, &NewItemDialog::onNewFolder);
    layout->addWidget(newFolderButton);

    QPushButton *newSheetButton = new QPushButton("New Sheet", this);
    connect(newSheetButton, &QPushButton::clicked, this, &NewItemDialog::onNewSheet);
    layout->addWidget(newSheetButton);
}

void NewItemDialog::onNewFolder() {
    QString folderName = "New Folder";  // Or get this from user input
    emit newFolderRequested(folderName);
    accept();  // Close the dialog
}

void NewItemDialog::onNewSheet() {
    emit newSheetRequested();
    accept();  // Close the dialog
}
