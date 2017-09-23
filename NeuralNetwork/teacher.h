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

    const double learnSpeed = 0.001;

    void computeErors();
    void computeWeights();

public:
    Teacher(NeuralNet *neuralNet);
    void learn(QList<int> wishesValue);
};

#endif // TEACHER_H
