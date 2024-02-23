#ifndef FOLDERWIDGET_H
#define FOLDERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class FolderWidget : public QWidget {
    Q_OBJECT

public:
    explicit FolderWidget(QWidget *parent = nullptr);

private:
    QLabel* label;
    QVBoxLayout* layout;
};

#endif // FOLDERWIDGET_H
