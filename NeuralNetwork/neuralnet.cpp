#include "neuralnet.h"

int NeuralNet::getOutputNeuronsCount() const
{
    return outputNeuronsCount;
}

int NeuralNet::getHiddenNeuronsCount() const
{
    return hiddenNeuronsCount;
}

int NeuralNet::getInputNeuronsCount() const
{
    return inputNeuronsCount;
}

QList<Neuron *> NeuralNet::getInputLay() const
{
    return inputLay;
}

QList<Neuron *> NeuralNet::getHiddenLay() const
{
    return hiddenLay;
}

QList<Neuron *> NeuralNet::getOutputLay() const
{
    return outputLay;
}

NeuralNet::NeuralNet(int inputNeuronsCount, int hiddenNeuronsCount, int outputNeuronsCount,
                     QList<QList<double> > weightsHiddenLay, QList<QList<double> > weightsOutputLay) :
    inputNeuronsCount(inputNeuronsCount), hiddenNeuronsCount(hiddenNeuronsCount), outputNeuronsCount(outputNeuronsCount)
{
    for(int i = 0; i < inputNeuronsCount; i++){
        inputLay.push_back(new Neuron());
    }

    for(int i = 0; i < hiddenNeuronsCount; i++){
        hiddenLay.push_back(new Neuron(inputNeuronsCount, weightsHiddenLay.at(i)));
    }

    for(int i = 0; i < outputNeuronsCount; i++){
        outputLay.push_back(new Neuron(hiddenNeuronsCount, weightsOutputLay.at(i)));
    }
}

void NeuralNet::startWith(QList<double> inputs)
{
    for(int i = 0; i < inputNeuronsCount; i++){
        inputLay.at(i)->setOutputSignal(inputs.at(i));
    }

    for(int i = 0; i < hiddenNeuronsCount; i++){
        Neuron *neuron = hiddenLay.at(i);
        for(int j = 0; j < inputNeuronsCount; j++){
            neuron->weighInputSignal(j, inputLay.at(j)->getOutputSignal());
        }
        neuron->sumWeightedInputSignals();
        neuron->activationNeuronFunction();
    }

    for(int i = 0; i < outputNeuronsCount; i++){
        Neuron *neuron = outputLay.at(i);
        for(int j = 0; j < hiddenNeuronsCount; j++){
            neuron->weighInputSignal(j, hiddenLay.at(j)->getOutputSignal());
        }
        neuron->sumWeightedInputSignals();
        neuron->activationNeuronFunction();
    }
}

void NeuralNet::updateWeights(QList<QList<double> > weightsHiddenLay, QList<QList<double> > weightsOutputLay)
{
    for(int i = 0; i < hiddenNeuronsCount; i++){
        hiddenLay.at(i)->setWeights(weightsHiddenLay.at(i));
    }

    for(int i = 0; i < outputNeuronsCount; i++){
        outputLay.at(i)->setWeights(weightsOutputLay.at(i));
    }
}
