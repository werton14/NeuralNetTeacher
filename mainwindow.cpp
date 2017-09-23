#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setRandowValues();
    ui->setupUi(this);
}

void MainWindow::setRandowValues()
{
        srand(time(NULL));
   for(int i = 0; i < 100; i++){

       int random = rand() % 100;
       double randomValues = random / 100.0;
       qDebug()<<randomValues;
   }



}

MainWindow::~MainWindow()
{
    delete ui;
}

