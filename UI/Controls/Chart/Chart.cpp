#include <UI/Controls/Chart/Chart.h>
#include "LineNode.h"
#include "GridNode.h"

Chart::Chart(QQuickItem *parent)
    : QQuickItem(parent),
      _minY(-0.1), _maxY(0.1), _color("red")
{
    setFlag(ItemHasContents, true);
}

void Chart::appendPoints(const QVector<QPointF> &points, float minY, float maxY, float minX, float maxX)
{
    if (points.isEmpty()) return;
    _points = points;

    _minY = minY;
    _maxY = maxY;

    _minX = minX;
    _maxX = maxX;

    update();
}

class ChartNode : public QSGNode
{
    public:
        LineNode *line;
        GridNode *gridRed;
        GridNode *gridGray;
};

QSGNode *Chart::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    ChartNode *n = static_cast<ChartNode *>(oldNode);

    QRectF rect = boundingRect();

    if (rect.isEmpty()) {
        delete n;
        return 0;
    }

    if (!n) {
        n = new ChartNode();
        n->gridRed = new GridNode(QColor(0x40, 0, 0), QVector2D(5, 3));
        n->gridGray = new GridNode(QColor(0x20, 0x20, 0x20), QVector2D(20, 6));
        n->line = new LineNode(_points.size()+1, _color);

        n->appendChildNode(n->gridGray);
        n->appendChildNode(n->gridRed);
        n->appendChildNode(n->line);
    }
    else
    {
        n->line->alloc(_points.size());
        n->gridRed->alloc();
        n->gridGray->alloc();
    }

    n->gridGray->setRect(rect);
    n->gridRed->setRect(rect);
    n->line->setPoints(rect, _points, _minY, _maxY, _minX, _maxX);

    return n;
}


