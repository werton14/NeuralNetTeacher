#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    setRandowValues();
    ui->setupUi(this);
}

void MainWindow::makeListwithRandomValues(int width, int height)
{
    QList<QList<double>> weightsLay;


    for(int i = 0; i < width; i++){

      QList<double> tmp;

            weightsLay.push_back(tmp);

        for(int j = 0; j < height; j++){

            tmp.push_back(randomDoubleValues());

        }
    }
}

double MainWindow::randomDoubleValues()
{
    int random = rand() % 100;
    return randomValues = random / 100.0;
}




MainWindow::~MainWindow()
{
    delete ui;
}

