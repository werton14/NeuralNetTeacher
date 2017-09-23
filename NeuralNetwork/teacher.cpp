#include "teacher.h"

Teacher::Teacher(NeuralNet *neuralNet) : neuralNet(neuralNet)
{

}

void Teacher::learn(QList<int> wishesValue)
{
    this->wishesValue = wishesValue;

    computeErors();
    computeWeights();

    neuralNet->updateWeights(newHiddenLayWeights, newOutputLayWeights);

    hiddenLayError.clear();
    outputLayError.clear();
    newHiddenLayWeights.clear();
    newOutputLayWeights.clear();

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
    int hiddenNeuronCount = neuralNet->getHiddenNeuronsCount();
    int inputNeuronCount = neuralNet->getInputNeuronsCount();
    QList<Neuron *> hiddenLay = neuralNet->getHiddenLay();
    QList<Neuron *> inputLay = neuralNet->getInputLay();

    for(int i = 0; i < hiddenNeuronCount; i++){
        QList<double> tmp;
        for(int j = 0; j < inputNeuronCount; j++){
            tmp.push_back(hiddenLay.at(i)->getWeights().at(j) + learnSpeed * hiddenLayError.at(i)
                          * inputLay.at(j)->getOutputSignal());
        }
        newHiddenLayWeights.push_back(tmp);
    }

    QList<Neuron *> outputLay = neuralNet->getOutputLay();
    int outputNeuronCount = neuralNet->getOutputNeuronsCount();

    for(int i = 0; i < outputNeuronCount; i++){
        QList<double> tmp;
        for(int j = 0; j < hiddenNeuronCount; j++){
            tmp.push_back(outputLay.at(i)->getWeights().at(j) + learnSpeed * outputLayError.at(i)
                          * hiddenLay.at(j)->getOutputSignal());
        }
        newOutputLayWeights.push_back(tmp);
    }
}

