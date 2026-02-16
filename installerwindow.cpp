#include "installerwindow.h"

#include <QDirIterator>

void FillComboBox(QComboBox* comboBox);

InstallerWindow::InstallerWindow(MainWindow* mainWindow, QWidget* parent)
    : QWidget{parent}
{
    frame = new QFrame(this);
    frame->setMinimumSize(400, 300);
    frame->setFrameStyle(QFrame::Box | QFrame::Plain);

    comboBox = new QComboBox(frame);
    comboBox->setStyleSheet(":disabled { background-color: lightGray; color: gray }");
    FillComboBox(comboBox);

    vFrameLayout = new QVBoxLayout(frame);
    vFrameLayout->addWidget(comboBox);
    vFrameLayout->setAlignment(comboBox, Qt::AlignCenter);

    prevButton = new QPushButton(this);
    prevButton->setText(QString("Назад"));
    prevButton->setStyleSheet(":disabled { background-color: lightGray; color: gray }");

    installButton = new QPushButton(this);
    installButton->setText(QString("Установить"));
    installButton->setStyleSheet(":disabled { background-color: lightGray; color: gray }");

    hButtonsLayout = new QHBoxLayout();
    hButtonsLayout->addWidget(prevButton);
    hButtonsLayout->setAlignment(prevButton, Qt::AlignLeft);
    hButtonsLayout->addWidget(installButton);
    hButtonsLayout->setAlignment(installButton, Qt::AlignRight);

    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(frame);
    vLayout->addLayout(hButtonsLayout);

    connect(prevButton, &QPushButton::clicked, mainWindow, &MainWindow::PrevPage);
    connect(installButton, &QPushButton::clicked, this, &InstallerWindow::InstallProgram);
}

QWidget* InstallerWindow::GetWidget()
{
    return this;
}

void InstallerWindow::InstallProgram()
{
    QString packageName = comboBox->currentText();
    QString file = packageName + ".deb";

    QString filePath = ":/packages/packages/" + file;
    QString tempFilePath = QDir::tempPath() + "/" + file;

    QFile::copy(filePath, tempFilePath);

    if (QFile::exists(tempFilePath))
    {
        process = new QProcess(this);
        QStringList arguments;
        arguments << "apt" << "install" << tempFilePath << "-y";

        connect(process, &QProcess::started, this, &InstallerWindow::StartedInstall);
        connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &InstallerWindow::FinishedInstall);

        process->start("pkexec", arguments);
    }
}

void InstallerWindow::StartedInstall()
{
    prevButton->setDisabled(true);
    installButton->setDisabled(true);
    comboBox->setDisabled(true);
}

void InstallerWindow::FinishedInstall(int exitCode, QProcess::ExitStatus exitStatus)
{
    QString file = comboBox->currentText() + ".deb";
    QString tempFilePath = QDir::tempPath() + "/" + file;
    QFile::remove(tempFilePath);

    prevButton->setDisabled(false);
    installButton->setDisabled(false);
    comboBox->setDisabled(false);

    process->deleteLater();
    process = nullptr;
}

void FillComboBox(QComboBox* comboBox)
{
    QDirIterator it(":/packages/packages/");
    while (it.hasNext())
    {
        it.next();
        comboBox->addItem(it.fileInfo().baseName());
    }
}
