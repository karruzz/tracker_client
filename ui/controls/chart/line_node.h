/*
 * line_node.h
 *
 *  Created on: Nov 8, 2018
 *  Copyright © 2018-2080 Ilja Karasev. All rights reserved.
 *     License: GNU GPL 3
 */

#ifndef LINENODE_H
#define LINENODE_H

#include <QSGGeometryNode>
#include <QSGGeometry>
#include <QVector2D>

class LineNode : public QSGGeometryNode
{
public:
	LineNode(int size, const QColor &color);

	void setPoints(const QRectF &bounds, const QVector<QPointF> &points,
				   float minY, float maxY, quint64 minX, quint64 maxX);

	void alloc(int size);

private:
	QSGGeometry _geometry;
};

#endif // LINENODE_H

