#ifndef GRAPHICSNODE_H
#define GRAPHICSNODE_H

#include <QQuickPaintedItem>

class GraphicsNode : public QQuickPaintedItem
{
    Q_OBJECT
private:
    QString mText;
public:
    explicit GraphicsNode(QQuickItem *parent = 0);
    GraphicsNode(qreal px, qreal py, qreal w, qreal h, QQuickItem *parent = 0);
    ~GraphicsNode();

    void paint(QPainter *painter);
    void touchEvent(QTouchEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void setText(QString txt);

signals:

public slots:
};

#endif // GRAPHICSNODE_H
