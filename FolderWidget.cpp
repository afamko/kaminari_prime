#include "FolderWidget.h"
#include <QPixmap>
#include <QLabel>
#include <QDebug> // Make sure to include this for qDebug()

FolderWidget::FolderWidget(const QString &folderName, QWidget *parent) : QWidget(parent) {
    // Set up the folder icon
    iconLabel = new QLabel(this); // Use the member variable, not a local variable
    QPixmap folderIcon(":/assets/icons/folder_icon.png");
    if (folderIcon.isNull()) {
        qDebug() << "Failed to load the folder icon.";
    } else {
        iconLabel->setPixmap(folderIcon.scaled(64, 64, Qt::KeepAspectRatio));
    }

    // Set up the folder label
    label = new QLabel(folderName, this);

    layout = new QVBoxLayout(this);
    layout->addWidget(iconLabel); // Add the icon to the layout
    layout->addWidget(label); // Add the label below the icon
    layout->setAlignment(Qt::AlignCenter); // Center the contents of the layout
}
