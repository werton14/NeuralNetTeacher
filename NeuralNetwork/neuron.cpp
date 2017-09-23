#include "neuron.h"

QList<double> Neuron::getWeights() const
{
    return weights;
}

Neuron::Neuron(int weightsCount, QList<double> weights) : weightsCount(weightsCount), weights(weights)
{

}

Neuron::Neuron()
{

}

double Neuron::getOutputSignal() const
{
    return outputSignal;
}

void Neuron::setOutputSignal(double value)
{
    outputSignal = value;
}

void Neuron::setWeights(QList<double> value)
{
    weights = value;
}

void Neuron::weighInputSignal(int index, double signal)
{
    weightedInputSignals.push_back(signal * weights[index]);
}

void Neuron::sumWeightedInputSignals()
{
    double tmp = 0.0;
    for(int i = 0; i < weightsCount; i++){
        tmp += weightedInputSignals.at(i);
    }
    weightedSumInputSignals = tmp;
    weightedInputSignals.clear();
}

void Neuron::activationNeuronFunction()
{
    if(weightedSumInputSignals >= thresholdValue){
        outputSignal = 1.0;
    }else{
        outputSignal = 0.0;
    }
}

