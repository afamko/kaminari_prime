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
    layout->setSpacing(10);
    layout->setAlignment(Qt::AlignCenter);

    // Style the QDialog using a style sheet.
    setStyleSheet("background-color: #535353;");

    // Create a horizontal layout for the title area
    QHBoxLayout *titleLayout = new QHBoxLayout();
    QLabel *driveIconLabel = new QLabel(this);
    QPixmap driveIconPixmap(":/assets/icons/createNew_icon.png");
    driveIconLabel->setPixmap(driveIconPixmap.scaled(16, 16)); // Scale icon as necessary
    titleLayout->addWidget(driveIconLabel);                    // Add the icon to the horizontal layout

    QLabel *titleLabel = new QLabel("Create new:", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(16);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: #FFFFFF;");
    titleLayout->addWidget(titleLabel); // Add the label to the horizontal layout

    layout->addLayout(titleLayout); // Add the title layout to the main vertical layout

    QPushButton *newFolderButton = new QPushButton(QIcon(":/assets/icons/newFolder_icon.png"), "Folder", this);
    newFolderButton->setIconSize(QSize(24, 24));
    newFolderButton->setCursor(Qt::PointingHandCursor);

    QPushButton *newSheetButton = new QPushButton(QIcon(":/assets/icons/newSheet_icon.png"), "Sheet", this);
    newSheetButton->setIconSize(QSize(24, 24));
    newSheetButton->setCursor(Qt::PointingHandCursor);

    QString buttonStyle = "QPushButton { color: #FFFFFF; border: none; margin: 5px; padding: 10px; }"
                          "QPushButton:hover { background-color: #f0f0f0; }";
    newFolderButton->setStyleSheet(buttonStyle);
    newSheetButton->setStyleSheet(buttonStyle);

    layout->addWidget(newFolderButton);
    layout->addWidget(newSheetButton);

    connect(newFolderButton, &QPushButton::clicked, this, &NewItemDialog::onNewFolder);
    connect(newSheetButton, &QPushButton::clicked, this, &NewItemDialog::onNewSheet);

    // Set the fixed size of the dialog or set it based on its content and style.
    setFixedSize(300, 200);

    // Position the dialog at the bottom of the parent widget.
    positionAtBottom(parent);
}

void NewItemDialog::onNewFolder()
{
    QString folderName = "New Folder"; // This could be retrieved from a QLineEdit or similar widget.
    emit newFolderRequested(folderName);
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
        int y = parent->geometry().bottom() - height(); // No need for an arbitrary margin

        // Ensure that the dialog is completely visible on screen.
        QRect availableGeometry = QApplication::primaryScreen()->availableGeometry();
        if (y < availableGeometry.top())
        {
            y = availableGeometry.top();
        }

        // Set the dialog's position
        move(x, y);
    }
}
