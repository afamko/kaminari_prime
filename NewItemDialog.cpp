#include "NewItemDialog.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QScreen>

NewItemDialog::NewItemDialog(QWidget *parent)
    : QDialog(parent, Qt::FramelessWindowHint | Qt::Popup) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(10);
    layout->setAlignment(Qt::AlignCenter);

    // Style the QDialog using a style sheet.
    setStyleSheet("background-color: #535353; border: 1px solid #dedede; border-radius: 5px;");

    QLabel *titleLabel = new QLabel("Create new:", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(16);
    titleLabel->setFont(titleFont);

    QPushButton *newFolderButton = new QPushButton(QIcon(":/assets/icons/newFolder_icon.png"), "Folder", this);
    newFolderButton->setIconSize(QSize(24, 24));
    newFolderButton->setCursor(Qt::PointingHandCursor);

    QPushButton *newSheetButton = new QPushButton(QIcon(":/assets/icons/newSheet_icon.png"), "Sheet", this);
    newSheetButton->setIconSize(QSize(24, 24));
    newSheetButton->setCursor(Qt::PointingHandCursor);

    QString buttonStyle = "QPushButton { color: black; border: none; margin: 5px; padding: 10px; }"
                          "QPushButton:hover { background-color: #f0f0f0; }";
    newFolderButton->setStyleSheet(buttonStyle);
    newSheetButton->setStyleSheet(buttonStyle);

    layout->addWidget(titleLabel);
    layout->addWidget(newFolderButton);
    layout->addWidget(newSheetButton);

    connect(newFolderButton, &QPushButton::clicked, this, &NewItemDialog::onNewFolder);
    connect(newSheetButton, &QPushButton::clicked, this, &NewItemDialog::onNewSheet);

    // Set the fixed size of the dialog or set it based on its content and style.
    setFixedSize(300, 200);

    // Position the dialog at the bottom of the parent widget.
    positionAtBottom(parent);
}



void NewItemDialog::onNewFolder() {
    QString folderName = "New Folder";  // This could be retrieved from a QLineEdit or similar widget.
    emit newFolderRequested(folderName);
    close();
}

void NewItemDialog::onNewSheet() {
    emit newSheetRequested();
    close();
}

void NewItemDialog::positionAtBottom(QWidget *parent) {
    if (parent != nullptr) {
        // Get the geometry of the parent widget.
        QRect parentRect = parent->geometry();
        
        // Get the available geometry of the screen (excluding taskbars and such).
        QRect availableGeometry = parent->screen()->availableGeometry();
        
        int x = parentRect.left() + (parentRect.width() - this->width()) / 2;
        // Adjust y position to account for the height of the dialog and a margin if needed.
        int y = availableGeometry.bottom() - this->height() - 10; // 10 is an arbitrary margin value.
        
        // Ensure that the dialog is completely visible on screen.
        if (y < availableGeometry.top()) {
            y = availableGeometry.top();
        }

        move(x, y);
    }
}

