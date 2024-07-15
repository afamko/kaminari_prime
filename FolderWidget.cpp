#include "FolderWidget.h"
#include <QPixmap>
#include <QLabel>
#include <QDebug> // Make sure to include this for qDebug()

FolderWidget::FolderWidget(const QString &folderName, QWidget *parent) : QWidget(parent)
{
    // Set up the folder icon
    iconLabel = new QLabel(this); // Use the member variable, not a local variable
    QPixmap folderIcon(":/assets/icons/folder_icon.png");
    iconLabel->setPixmap(folderIcon.scaled(108, 108, Qt::KeepAspectRatio));
    iconLabel->setAlignment(Qt::AlignCenter); // Ensure the icon is centered in its QLabel

    // Set up the folder label
    label = new QLabel(folderName, this);
    label->setAlignment(Qt::AlignCenter); // Center align the folder label text

    layout = new QVBoxLayout(this);
    layout->addWidget(iconLabel);           // Add the icon to the layout
    layout->addWidget(label);               // Add the label below the icon
    layout->setAlignment(Qt::AlignCenter);  // Center the contents of the layout
    layout->setContentsMargins(0, 0, 0, 0); // Ensure no margins around the layout contents
}
