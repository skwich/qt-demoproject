#include "mainwindow.h"

#include "installerwindow.h"
#include "surnamewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    SurnameWindow* surnameWindow = new SurnameWindow(this, this);
    InstallerWindow* installerWindow = new InstallerWindow(this, this);

    stackedWidget->addWidget(surnameWindow->GetWidget());
    stackedWidget->addWidget(installerWindow->GetWidget());
}

MainWindow::~MainWindow() {}

void MainWindow::NextPage()
{
    int nextPage = stackedWidget->currentIndex() + 1;
    if (nextPage >= stackedWidget->count())
        return;

    stackedWidget->setCurrentIndex(nextPage);
}

void MainWindow::PrevPage()
{
    int prevPage = stackedWidget->currentIndex() - 1;
    if (prevPage < 0)
        return;

    stackedWidget->setCurrentIndex(prevPage);
}

