#include "SketchPage.h"
#include <QVBoxLayout>
#include <QLabel>

SketchPage::SketchPage(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Set up the sketch page layout and contents
    QLabel *titleLabel = new QLabel("Sketch", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);

    // Add more UI elements as needed

    setLayout(layout);
}
