#include "NewItemDialog.h"
#include <QVBoxLayout>
#include <QPushButton>

NewItemDialog::NewItemDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *newFolderButton = new QPushButton("Folder", this);
    connect(newFolderButton, &QPushButton::clicked, this, &NewItemDialog::onNewFolder);
    layout->addWidget(newFolderButton);

    QPushButton *newSheetButton = new QPushButton("Sheet", this);
    connect(newSheetButton, &QPushButton::clicked, this, &NewItemDialog::onNewSheet);
    layout->addWidget(newSheetButton);
}

void NewItemDialog::onNewFolder() {
    // Implement new folder creation logic
    accept(); // Close the dialog
}

void NewItemDialog::onNewSheet() {
    // Implement new sheet creation logic
    accept(); // Close the dialog
}
