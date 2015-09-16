#ifndef DRAWINGCANVAS_H
#define DRAWINGCANVAS_H
#include <QObject>
#include <QQuickPaintedItem>
#include <QVector>
#include <QList>
#include <QtQml>
#include <QtQuick>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include "graphicsnode.h"

class DrawingCanvas : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit DrawingCanvas(QQuickItem *parent = 0);
    ~DrawingCanvas();

    void paint(QPainter *painter);
    void touchEvent(QTouchEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    QList<QPointF> _mDots;
    QList<GraphicsNode*> _mNodes;

    QGraphicsScene *_mScene;

private:
    void appendItem(QPointF &atpoint, QGraphicsItem *item = 0);
};

#endif // DRAWINGCANVAS_H
