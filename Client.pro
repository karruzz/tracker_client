TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    Model/dataentrymodel.cpp \
    Model/renderthread.cpp \
    Model/qgyroframe.cpp \
    Channel/tfilechannel.cpp \
    View/chart.cpp \
    Core/dispatcher.cpp \
    Subsystems/Gyro/gyrochartmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Model/dataentrymodel.h \
    Data/Devices/gyroframe.h \
    Math/point3d.h \
    Channel/ichannel.h \
    Model/renderthread.h \
    Model/qgyroframe.h \
    Data/iframe.h \
    Channel/tfilechannel.h \
    View/chart.h \
    Core/dispatcher.h \
    Subsystems/Gyro/gyrochartmodel.h

DISTFILES +=

