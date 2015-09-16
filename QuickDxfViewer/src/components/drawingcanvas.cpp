#include "drawingcanvas.h"

#include <QGraphicsRectItem>

DrawingCanvas::DrawingCanvas(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    //_mScene = new QGraphicsScene(this);
    setAcceptedMouseButtons(Qt::AllButtons);
}

DrawingCanvas::~DrawingCanvas()
{
    //QList<QGraphicsItem*> gl = _mScene->items();
    for(auto node: _mNodes){
        delete node;
    }
    //_mScene->clear();
}

void DrawingCanvas::paint(QPainter *painter)
{
    QBrush brushSpace(QColor("#335533"));
    QBrush brushDot(QColor("#00FFFF"));
    QPen   penBorder(QColor("#FFFFFF"));
    painter->setBrush(brushSpace);
    painter->setPen(penBorder);
    painter->setRenderHint(QPainter::Antialiasing);

    painter->drawRoundedRect(0, 0, boundingRect().width(), boundingRect().height() - 2, 2, 2);

    painter->setBrush(Qt::NoBrush);
    //QGraphicsItem* gi;
    //QList<QGraphicsItem*> gl = _mScene->items();

    /*for(auto g: gl){
        if(g != nullptr){
            g->paint(painter, );
        }
    }*/

}

void DrawingCanvas::touchEvent(QTouchEvent *event)
{
    QTouchEvent::TouchPoint p = event->touchPoints().at(0);
    QPointF pt = p.lastPos();
    _mDots.append(pt);

    appendItem(pt);

    event->accept();

    update();
}

void DrawingCanvas::mousePressEvent(QMouseEvent *event)
{
    QPointF pt = event->localPos();

    _mDots.append(pt);

    appendItem(pt);

    event->accept();

    update();
}

void DrawingCanvas::appendItem(QPointF &atpoint, QGraphicsItem *item)
{
    qreal rx(atpoint.rx());
    qreal ry(atpoint.ry());
    GraphicsNode *ngi = new GraphicsNode(rx, ry, 20, 25, this);
    ngi->setText("New item");
    _mNodes.append(ngi);
    /*if(_mScene != nullptr)
        _mScene->addItem(ngi);
    else
        qDebug() << " Error on append item";*/
}

