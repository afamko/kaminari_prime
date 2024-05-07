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
    // Reduce the vertical margins around the content
    layout->setContentsMargins(5, 5, 5, 5);

    // Style the QDialog using a style sheet.
    setStyleSheet("background-color: #535353; border: none;");

    // Create a horizontal layout for the title area
    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->setSpacing(2);                  // Reduced spacing between icon and text
    titleLayout->setContentsMargins(0, 0, 0, 0); // No extra margins in the horizontal layout

    QLabel *driveIconLabel = new QLabel(this);
    QPixmap driveIconPixmap(":/assets/icons/createNew_icon.png");
    driveIconLabel->setPixmap(driveIconPixmap.scaled(32, 32)); // Scale icon as necessary
    titleLayout->addWidget(driveIconLabel);                    // Add the icon to the horizontal layout

    QLabel *titleLabel = new QLabel("Create new:", this);
    titleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(24);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: #FFFFFF; margin-left: 5px;"); // Minimal left margin for text alignment
    titleLayout->addWidget(titleLabel);

    layout->addLayout(titleLayout); // Add the title layout to the main vertical layout

    // Add a vertical spacer
    layout->addSpacing(0); // Adjust the spacing to your preference

    // Horizontal layout for buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *newFolderButton = new QPushButton(QIcon(":/assets/icons/newFolder_icon.png"), "Folder", this);
    newFolderButton->setIconSize(QSize(48, 48));
    newFolderButton->setCursor(Qt::PointingHandCursor);

    QPushButton *newSheetButton = new QPushButton(QIcon(":/assets/icons/newSheet_icon.png"), "Sheet", this);
    newSheetButton->setIconSize(QSize(48, 48));
    newSheetButton->setCursor(Qt::PointingHandCursor);

    QString buttonStyle = "QPushButton { color: #FFFFFF; border: none; margin: 5px; padding: 10px; }"
                          "QPushButton:hover { background-color: #f0f0f0; }";
    newFolderButton->setStyleSheet(buttonStyle);
    newSheetButton->setStyleSheet(buttonStyle);

    buttonLayout->addWidget(newFolderButton);
    buttonLayout->addWidget(newSheetButton);

    layout->addLayout(buttonLayout); // Add horizontal layout for buttons to the main vertical layout

    connect(newFolderButton, &QPushButton::clicked, this, &NewItemDialog::onNewFolder);
    connect(newSheetButton, &QPushButton::clicked, this, &NewItemDialog::onNewSheet);

    // Set the fixed size of the dialog or set it based on its content and style.
    setFixedSize(300, 140);

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
