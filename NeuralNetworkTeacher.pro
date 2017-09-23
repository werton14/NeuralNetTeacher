#-------------------------------------------------
#
# Project created by QtCreator 2017-09-20T23:03:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++0x

TARGET = NeuranNetworkTeacher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    NeuralNetwork/neuralnet.cpp \
    NeuralNetwork/neuron.cpp \
    NeuralNetwork/teacher.cpp \
    qxtspanslider.cpp


HEADERS  += mainwindow.h \
    NeuralNetwork/neuralnet.h \
    NeuralNetwork/neuron.h \
    NeuralNetwork/teacher.h \
    qxtspanslider.h \
    qxtspanslider_p.h

FORMS    += mainwindow.ui
