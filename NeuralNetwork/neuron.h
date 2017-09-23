#ifndef NEURON_H
#define NEURON_H

#include <QList>

class Neuron
{
private:
    int weightsCount = 0;
    QList<double> weights;
    QList<double> weightedInputSignals;
    double weightedSumInputSignals = 0.0;
    double outputSignal = 0.0;
    const double thresholdValue = 0.5;

public:
    Neuron(int, QList<double>);

    void weighInputSignal(int index, double signal);
    void sumWeightedInputSignals();
    void activationNeuronFunction();

    double getOutputSignal() const;
    void setOutputSignal(double value);
    void setWeights(QList<double>);
};

#endif // NEURON_H
