#ifndef TEACHER_H
#define TEACHER_H

#include "neuralnet.h"
#include <QList>

class Teacher
{
private:
    NeuralNet *neuralNet;

    QList<double> hiddenLayError;
    QList<double> outputLayError;

    QList<QList<double> > newHiddenLayWeights;
    QList<QList<double> > newOutputLayWeights;
    QList<int> wishesValue;

    const double lernSpeed = 0.001;

public:
    void computeErors();
    void computeWeights();
    Teacher();
};

#endif // TEACHER_H
