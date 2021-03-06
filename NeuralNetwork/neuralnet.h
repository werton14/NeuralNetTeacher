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


public:
    NeuralNet(int, int, int, QList<QList<double> >, QList<QList<double> >);
    void startWith(QList<double>);
    void updateWeights(QList<QList<double> >, QList<QList<double> >);

    int getOutputNeuronsCount() const;
    int getHiddenNeuronsCount() const;
    int getInputNeuronsCount() const;
    QList<Neuron *> getInputLay() const;
    QList<Neuron *> getHiddenLay() const;
    QList<Neuron *> getOutputLay() const;
};

#endif // NEURALNET_H
