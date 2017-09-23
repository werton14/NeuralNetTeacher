#ifndef NEURALNET_H
#define NEURALNET_H

#include "NeuralNetwork/neuron.h"

#include <QList>


class NeuralNet
{
private:
    int inputNeuronsCount = 0;
    int hiddenNeuronsCount = 0;
    int outputNeuronsCount = 0;

    QList<Neuron*> inputLay;
    QList<Neuron*> hiddenLay;
    QList<Neuron*> outputLay;

    void updateWeights(QList<QList<double> >, QList<QList<double> >);

public:
    NeuralNet(int, int, int, QList<QList<double> >, QList<QList<double> >);
    void startWith(QList<double>);

};

#endif // NEURALNET_H
