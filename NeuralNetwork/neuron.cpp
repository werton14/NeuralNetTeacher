#include "neuron.h"

Neuron::Neuron(int weightsCount, QList<double> weights) : weightsCount(weightsCount), weights(weights)
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
    weightedInputSignals.clear();
    weightedInputSignals.push_back(signal * weights[index]);
}

void Neuron::sumWeightedInputSignals()
{
    double tmp = 0.0;
    for(int i = 0; i < weightsCount; i++){
        tmp += weightedInputSignals.at(i);
    }
    weightedSumInputSignals = tmp;
}

void Neuron::activationNeuronFunction()
{
    if(weightedSumInputSignals >= thresholdValue){
        outputSignal = 1;
    }else{
        outputSignal = 0;
    }
}

