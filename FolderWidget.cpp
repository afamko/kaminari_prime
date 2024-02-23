#include "FolderWidget.h"

FolderWidget::FolderWidget(QWidget *parent) : QWidget(parent) {
    label = new QLabel("Folder Name");
    layout = new QVBoxLayout(this);
    layout->addWidget(label);
    // You can add your folder icon to the layout as well
}

// Add more functionality as needed
