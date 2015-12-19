#ifndef CHART_H
#define CHART_H

#include <QList>
#include <QPointF>
#include <QQuickItem>
#include <QSGGeometryNode>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>

class Chart : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY( QColor color READ color WRITE setColor NOTIFY colorChanged)

    Q_PROPERTY( qreal minY READ minY NOTIFY minYChanged)
    Q_PROPERTY( qreal maxY READ maxY NOTIFY maxYChanged)

    Q_PROPERTY( qint64 minX READ minX NOTIFY minXChanged)
    Q_PROPERTY( qint64 maxX READ maxX NOTIFY maxXChanged)
public:
    explicit Chart(QQuickItem *parent = 0);

    QColor color() const { return _color; }
    void setColor(QColor c) { _color = c; emit colorChanged(); }

    qreal minY() const { return _minY; }
    qreal maxY() const { return _maxY; }

    quint64 minX() const { return _minX; }
    quint64 maxX() const { return _maxX; }

public slots:
    void appendPoints(const QVector<QPointF> &points, float minY, float maxY, float minX, float maxX );

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *);

signals:
    void minYChanged();
    void maxYChanged();

    void minXChanged();
    void maxXChanged();

    void pointsChanged();
    void colorChanged();

private:
    QVector<QPointF> _points;
    qreal _minY, _maxY;
    QColor _color;

    int _samples;
    qint64 _minX, _maxX;
};

#endif // CHART_H


