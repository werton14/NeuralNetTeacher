#include "neuron.h"

Neuron::Neuron(int weightCount, QList<double> weights) : weightCount(weightCount), weights(weights)
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
    for(int i = 0; i < weightCount; i++){
        tmp += weightedInputSignals.at(i);
    }
    weightedSumInputSignals = tmp;
}

void Neuron::activationNeuronFunction()
{
    if(weightedInputSignals >= 0.5){
        return 1;
    }else{
        return 0;
    }
}

