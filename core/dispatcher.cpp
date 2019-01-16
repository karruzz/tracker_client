/*
 * dispatcher.cpp
 *
 *  Created on: Nov 8, 2018
 *  Copyright © 2018-2080 Ilja Karasev. All rights reserved.
 *     License: GNU GPL 3
 */

#include "dispatcher.h"

void Dispatcher::open(const QString &path)
{
	_gyroChart.reset();
	_gyro3D.reset();
	_channel.reset(new TFileChannel<GyroFrame>());

	if (!_channel->Open(path)) {
		_channel.reset();
		return;
	}

	_channel->Count();
	_gyroChart.reset(new GyroChartModel(_parent, *_channel));
	_gyro3D.reset(new Gyro3DModel(_parent, *_channel));

	emit opened();
	emit count_changed();
}

void Dispatcher::seek(quint64 counter)
{
	_channel->Count();
	_gyroChart->seek(counter);
	_gyro3D->seek(counter);
}

