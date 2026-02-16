#ifndef SURNAMEWINDOW_H
#define SURNAMEWINDOW_H

#include "mainwindow.h"

#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class SurnameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SurnameWindow(MainWindow* mainWindow, QWidget* parent = nullptr);
    QWidget* GetWidget();

private:
    QVBoxLayout* vLayout;

    QFrame* frame;
    QLabel* label;
    QVBoxLayout* vFrameLayout;

    QPushButton* nextButton;
};

#endif // SURNAMEWINDOW_H
