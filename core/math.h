/*
 * math.h
 *
 *  Created on: Nov 8, 2018
 *  Copyright © 2018-2080 Ilja Karasev. All rights reserved.
 *     License: GNU GPL 3
 */

#ifndef MATH_H
#define MATH_H

#include <QMatrix4x4>
#include <QQuaternion>

class Math
{
public:
	static QQuaternion derivative(QQuaternion q, float wx, float wy, float wz);
	static QQuaternion versor(float angle, float x, float y, float z);
	static QMatrix4x4 dcm(QVector3D euler);
	static QMatrix4x4 dcm(QQuaternion q);
};
#endif // MATH_H

