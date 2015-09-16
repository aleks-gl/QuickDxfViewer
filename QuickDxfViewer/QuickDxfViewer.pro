TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

QT += qml quick widgets

SOURCES += ./src/main.cpp \
   ./src/components/drawingcanvas.cpp \
   ./src/domain/graphicsnode.cpp

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += ./ui

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ./src/components/drawingcanvas.h \
    ./src/domain/graphicsnode.h
