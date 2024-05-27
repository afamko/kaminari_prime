#include "NewItemDialog.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QScreen>
#include <QHBoxLayout> // Include for QHBoxLayout

NewItemDialog::NewItemDialog(QWidget *parent)
    : QDialog(parent, Qt::FramelessWindowHint | Qt::Popup)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(5, 5, 5, 5);

    setStyleSheet("background-color: #535353; border: none;");

    QHBoxLayout *titleLayout = new QHBoxLayout();
    QLabel *driveIconLabel = new QLabel(this);
    QPixmap driveIconPixmap(":/assets/icons/createNew_icon.png");
    driveIconLabel->setPixmap(driveIconPixmap.scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    titleLayout->addWidget(driveIconLabel);

    QLabel *titleLabel = new QLabel("Create new:", this);
    titleLabel->setFont(QFont("Arial", 28));
    titleLabel->setStyleSheet("color: #FFFFFF; margin-left: 5px;");
    titleLayout->addWidget(titleLabel);

    layout->addLayout(titleLayout);

    layout->addSpacing(10); // Add extra spacing between the title and the buttons

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setAlignment(Qt::AlignCenter);

    // Create Folder button
    QVBoxLayout *folderLayout = new QVBoxLayout();
    folderLayout->setAlignment(Qt::AlignCenter);
    QPushButton *newFolderButton = new QPushButton();
    newFolderButton->setIcon(QIcon(":/assets/icons/newFolder_icon.png"));
    newFolderButton->setIconSize(QSize(58, 58));
    newFolderButton->setStyleSheet("QPushButton { border: none; background-color: transparent; } QPushButton:hover { background-color: #f0f0f0; }");
    QLabel *folderLabel = new QLabel("Folder");
    folderLabel->setAlignment(Qt::AlignCenter);
    folderLabel->setStyleSheet("color: #FFFFFF;");

    folderLayout->addWidget(newFolderButton);
    folderLayout->addSpacing(5); // Add spacer for spacing between icon and text
    folderLayout->addWidget(folderLabel);

    // Create Sheet button
    QVBoxLayout *sheetLayout = new QVBoxLayout();
    sheetLayout->setAlignment(Qt::AlignCenter);
    QPushButton *newSheetButton = new QPushButton();
    newSheetButton->setIcon(QIcon(":/assets/icons/newSheet_icon.png"));
    newSheetButton->setIconSize(QSize(58, 58));
    newSheetButton->setStyleSheet("QPushButton { border: none; background-color: transparent; } QPushButton:hover { background-color: #f0f0f0; }");
    QLabel *sheetLabel = new QLabel("Sheet");
    sheetLabel->setAlignment(Qt::AlignCenter);
    sheetLabel->setStyleSheet("color: #FFFFFF;");

    sheetLayout->addWidget(newSheetButton);
    sheetLayout->addSpacing(5); // Add spacer for spacing between icon and text
    sheetLayout->addWidget(sheetLabel);

    buttonLayout->addLayout(folderLayout);
    buttonLayout->addSpacing(80); // Add spacing between Folder and Sheet buttons
    buttonLayout->addLayout(sheetLayout);

    layout->addLayout(buttonLayout);

    connect(newFolderButton, &QPushButton::clicked, this, &NewItemDialog::onNewFolder);
    connect(newSheetButton, &QPushButton::clicked, this, &NewItemDialog::onNewSheet);

    setFixedSize(300, 160);

    positionAtBottom(parent);
}

void NewItemDialog::onNewFolder()
{
    emit newFolderRequested("New Folder");
    close();
}

void NewItemDialog::onNewSheet()
{
    emit newSheetRequested();
    close();
}

void NewItemDialog::positionAtBottom(QWidget *parent)
{
    if (parent != nullptr)
    {
        // Set the width of the dialog to match the parent's width
        int dialogWidth = parent->width();
        setFixedWidth(dialogWidth);

        // Calculate the x position to align with the parent's left edge
        int x = parent->geometry().left();

        // Calculate the y position to align at the bottom of the parent
        // Adjust the y-coordinate to position it above the window frame, status bar, or other bottom elements
        int y = parent->geometry().bottom() - this->height() - parent->frameGeometry().height() + parent->geometry().height();

        // Ensure that the dialog is completely visible on screen.
        QRect availableGeometry = QApplication::primaryScreen()->availableGeometry();
        if (y < availableGeometry.top())
        {
            y = availableGeometry.top();
        }
        if (y + height() > availableGeometry.bottom())
        {
            y = availableGeometry.bottom() - height();
        }

        // Set the dialog's position
        move(x, y);
    }
}
