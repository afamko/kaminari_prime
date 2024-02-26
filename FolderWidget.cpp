#include "FolderWidget.h"
#include <QPixmap>
#include <QLabel>


FolderWidget::FolderWidget(const QString &folderName, QWidget *parent) : QWidget(parent) {
    // Set up the folder icon
    QLabel* iconLabel = new QLabel(this);
    QPixmap folderIcon(":/icons/folder_icon.png"); // Replace with actual path to folder icon
    iconLabel->setPixmap(folderIcon);
    //iconLabel->setPixmap(folderIcon.scaled(64, 64, Qt::KeepAspectRatio)); // Set the icon size as needed

    // Set up the folder label
    label = new QLabel(folderName, this);

    // Set up the layout
    layout = new QVBoxLayout(this);
    layout->addWidget(iconLabel); // Add the icon to the layout
    layout->addWidget(label); // Add the label below the icon
    layout->setAlignment(Qt::AlignCenter); // Center the contents of the layout
}

// Add more functionality as needed
