TEMPLATE = subdirs
CONFIG   += ordered

QMAKE_CXXFLAGS += -std=c++11
QT += qml quick widgets

SUBDIRS = application \
	lib \
    libs
