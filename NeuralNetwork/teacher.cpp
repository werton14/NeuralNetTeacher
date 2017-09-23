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

    int hiddenNeuronCount = neuralNet->getHiddenNeuronsCount();

    for(int i = 0; i < hiddenNeuronCount; i++){
        double tmp = 0.0;
        for(int j = 0; j < outputNeuronCount; j++){
            tmp += outputLayError.at(i) * outputLay.at(j)->getWeights().at(i);
        }
        hiddenLayError.push_back(tmp);
    }
}

void Teacher::computeWeights()
{

}

