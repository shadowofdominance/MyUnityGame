#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GitManager.h"

#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectProjectBtn_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(
        this,
        "Select Project Folder"
    );

    if(folderPath.isEmpty())
        return;

    ui->projectPathLabel->setText("Path: " + folderPath);

    GitManager git;

    if(!git.isGitRepo(folderPath)){
        qDebug() << "Not a git repo!";
        ui->projectPathLabel->setText("PATH NOT A GIT REPO!");
        return;
    }

    QString status = git.getStatus(folderPath);

    qDebug() << status;

}


void MainWindow::on_pushBtn_clicked()
{

}


void MainWindow::on_commitBtn_clicked()
{

}

