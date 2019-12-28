TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game/game.cpp \
    game/cell.cpp \
    game/gridhelper.cpp \
    network/neuralnetwork.cpp \
    filehandler/filehandler.cpp \
    trainer/trainer.cpp \
    network/node.cpp \
    network/neuron.cpp \
    network/inputnode.cpp \
    network/kernelmaster.cpp \
    network/kernelinstance.cpp


HEADERS += \
    game/game.h \
    game/cell.h \
    network/neuralnetwork.h \
    filehandler/filehandler.h \
    trainer/trainer.h \
    network/node.h \
    network/neuron.h \
    network/inputnode.h \
    network/kernelmaster.h \
    network/kernelinstance.h
