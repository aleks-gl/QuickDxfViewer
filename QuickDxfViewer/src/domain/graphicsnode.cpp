#include "graphicsnode.h"
#include <QtQml>
#include <QtQuick>
#include <QFontMetrics>
#include <QFontMetricsF>
#include <QFont>

GraphicsNode::GraphicsNode(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    setAcceptedMouseButtons(Qt::AllButtons);
}

GraphicsNode::GraphicsNode(qreal px, qreal py, qreal w, qreal h, QQuickItem *parent) : QQuickPaintedItem(parent)
{
    setAcceptedMouseButtons(Qt::AllButtons);
    this->setHeight(h);
    this->setWidth(w);
    this->setPosition(QPointF(px-w/2,py-h/2));
}

GraphicsNode::~GraphicsNode()
{

}

void GraphicsNode::paint(QPainter *painter)
{
    QBrush brushSpace(QColor("#00FF00"));
    QPen   penBorder(QColor("#0000FF"));
    painter->setBrush(Qt::NoBrush);
    painter->setPen(penBorder);
    painter->setRenderHint(QPainter::Antialiasing);

    painter->drawRoundedRect(0, 0, boundingRect().width(), boundingRect().height() - 2, 2, 2);

    painter->drawText( boundingRect(), mText);
}

void GraphicsNode::touchEvent(QTouchEvent *event)
{

}

void GraphicsNode::mousePressEvent(QMouseEvent *event)
{
    event->accept();
}

void GraphicsNode::setText(QString txt)
{
    mText = txt;

    QFont f("Helvetica");

    QFontMetrics fm(f);

    QRectF rect = fm.boundingRect(mText);

    this->setWidth(rect.width()+5);
    this->setHeight(rect.height()+5);
}

