#include "teacher.h"

Teacher::Teacher()
{

}

void Teacher::computeErors()
{
    QList<Neuron *> outputLay = neuralNet->getOutputLay();
    int outputNeuronCount = neuralNet->getOutputNeuronsCount();

    for(int i = 0; i < outputNeuronCount; i++){
        outputLayError.push_back(wishesValue.at(i) - outputLay.at(i)->getOutputSignal());
    }

    QList<Neuron *> hiddenLay = neuralNet->getHiddenLay();
    int hiddenNeuronCount = neuralNet->getHiddenNeuronsCount();

    for(int i = 0; i < hiddenNeuronCount; i++){
        hiddenLayError.push_back();
    }

}

void Teacher::computeWeights()
{

}

