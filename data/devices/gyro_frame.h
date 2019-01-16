/*
 * gyro_frame.h
 *
 *  Created on: Nov 8, 2018
 *  Copyright © 2018-2080 Ilja Karasev. All rights reserved.
 *     License: GNU GPL 3
 */

#ifndef GYROFRAME
#define GYROFRAME

#include <QDataStream>
#include <QVector3D>

#include "data/iframe.h"

class GyroFrame : public IFrame
{
public:
	const static int FrameSize = 80;

	QVector3D Acs;
	QVector3D Omega;
	QVector3D Angle;

	friend QDataStream &operator >>(QDataStream &out, GyroFrame &frame);
};

inline QDataStream &operator >>(QDataStream &out, GyroFrame &frame)
{
//	quint64 header;
//	out >> header;
	out >> frame.Counter;

	out >> frame.Angle;
	out >> frame.Omega;
	out >> frame.Acs;

	return out;
}

#endif // GYROFRAME


