#ifndef INSTALLERWINDOW_H
#define INSTALLERWINDOW_H

#include "mainwindow.h"

#include <QComboBox>
#include <QProcess>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class InstallerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit InstallerWindow(MainWindow* mainWindow, QWidget* parent = nullptr);
    QWidget* GetWidget();

public slots:
    void InstallProgram();
    void StartedInstall();
    void FinishedInstall(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QVBoxLayout* vLayout;

    QFrame* frame;
    QComboBox* comboBox;
    QVBoxLayout* vFrameLayout;

    QPushButton* prevButton;
    QPushButton* installButton;
    QHBoxLayout* hButtonsLayout;

    QProcess* process;
};
#endif // INSTALLERWINDOW_H
