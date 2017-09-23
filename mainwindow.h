#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "NeuralNetwork/neuralnet.h"
#include "NeuralNetwork/teacher.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);



    QList<QList<double> > makeListwithRandomValues(int,int);
    double randomDoubleValues();

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    NeuralNet *neuralNet;
    Teacher *teacher;

};

#endif // MAINWINDOW_H
