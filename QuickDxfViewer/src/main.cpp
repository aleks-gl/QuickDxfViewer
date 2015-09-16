#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "components/drawingcanvas.h"

int main(int argc, char *argv[])
{

    qmlRegisterType<DrawingCanvas>("io.quickcad.qmlcomponents", 1, 0, "DrawingCanvas");

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
