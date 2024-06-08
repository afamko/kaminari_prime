#include "NewItemDialog.h"
#include "NewFolderDialog.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QScreen>
#include <QHBoxLayout>
#include <QTimer> // Include QTimer

NewItemDialog::NewItemDialog(QWidget *parent)
    : QDialog(parent, Qt::FramelessWindowHint | Qt::Popup)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(5, 5, 5, 5);

    setStyleSheet("background-color: #535353; border: none;");

    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->setSpacing(0);
    titleLayout->setContentsMargins(0, 0, 0, 0);

    QLabel *driveIconLabel = new QLabel(this);
    QPixmap driveIconPixmap(":/assets/icons/createNew_icon.png");
    driveIconLabel->setPixmap(driveIconPixmap.scaled(21, 21, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    driveIconLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    titleLayout->addWidget(driveIconLabel);

    QLabel *titleLabel = new QLabel("Create new:", this);
    titleLabel->setFont(QFont("Arial", 28));
    titleLabel->setStyleSheet("color: #FFFFFF; margin-left: 0px;");
    titleLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    titleLayout->addWidget(titleLabel);

    layout->addLayout(titleLayout);

    layout->addSpacing(10);

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
    folderLayout->addSpacing(5);
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
    sheetLayout->addSpacing(5);
    sheetLayout->addWidget(sheetLabel);

    buttonLayout->addLayout(folderLayout);
    buttonLayout->addSpacing(80);
    buttonLayout->addLayout(sheetLayout);

    layout->addLayout(buttonLayout);

    connect(newFolderButton, &QPushButton::clicked, this, &NewItemDialog::onNewFolder);
    connect(newSheetButton, &QPushButton::clicked, this, &NewItemDialog::onNewSheet);

    setFixedSize(300, 160);

    positionAtBottom(parent);
}

void NewItemDialog::onNewFolder()
{
    NewFolderDialog *folderDialog = new NewFolderDialog(this);
    if (folderDialog->exec() == QDialog::Accepted)
    {
        QString folderName = folderDialog->folderName();
        emit newFolderRequested(folderName);
    }
    delete folderDialog;
    close();
}

void NewItemDialog::onNewSheet()
{
    emit newSheetRequested();
    QTimer::singleShot(0, this, &NewItemDialog::close);
}

void NewItemDialog::positionAtBottom(QWidget *parent)
{
    if (parent != nullptr)
    {
        int dialogWidth = parent->width();
        setFixedWidth(dialogWidth);

        int x = parent->geometry().left();

        int y = parent->geometry().bottom() - this->height() - parent->frameGeometry().height() + parent->geometry().height();

        QRect availableGeometry = QApplication::primaryScreen()->availableGeometry();
        if (y < availableGeometry.top())
        {
            y = availableGeometry.top();
        }
        if (y + height() > availableGeometry.bottom())
        {
            y = availableGeometry.bottom() - height();
        }

        move(x, y);
    }
}
