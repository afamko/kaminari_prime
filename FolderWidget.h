#ifndef FOLDERWIDGET_H
#define FOLDERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

class FolderWidget : public QWidget {
    Q_OBJECT

public:
    explicit FolderWidget(const QString &folderName, QWidget *parent = nullptr);

private:
    QLabel* label;
    QLabel* iconLabel;
    QVBoxLayout* layout;
};

#endif // FOLDERWIDGET_H
