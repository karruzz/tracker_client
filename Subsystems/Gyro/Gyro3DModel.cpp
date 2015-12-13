
#include "Gyro3DModel.h"

Gyro3DModel::Gyro3DModel(QQuickView *parent, IChannel<GyroFrame> *channel)
    : QObject(parent), _channel(channel)
{
    auto root = parent->rootObject();
    auto view = root->findChild<Projection*>("gyro3D");
    QObject::connect(this, &Gyro3DModel::PointUpdated, view, &Projection::setPosition);
}

void Gyro3DModel::seek(quint64 index)
{
    auto frame = _channel->Read(index);
    emit PointUpdated(frame);
}
