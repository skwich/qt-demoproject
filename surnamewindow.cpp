#include "surnamewindow.h"

SurnameWindow::SurnameWindow(MainWindow* mainWindow, QWidget* parent)
    : QWidget(parent)
{
    frame = new QFrame(this);
    frame->setMinimumSize(400, 300);
    frame->setFrameStyle(QFrame::Box | QFrame::Plain);

    label = new QLabel("Surname", frame);
    label->setAlignment(Qt::AlignCenter);

    vFrameLayout = new QVBoxLayout(frame);
    vFrameLayout->addWidget(label);

    nextButton = new QPushButton();
    nextButton->setText(QString("Далее"));

    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(frame);
    vLayout->addWidget(nextButton);
    vLayout->setAlignment(nextButton, Qt::AlignRight);

    connect(nextButton, &QPushButton::clicked, mainWindow, &MainWindow::NextPage);
}

QWidget* SurnameWindow::GetWidget()
{
    return this;
}
