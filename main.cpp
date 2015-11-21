#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtGui>
#include <QtQml>

#include <QtQuick/QQuickView>

#include "Model/dataentrymodel.h"
#include "View/chart.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<DataEntryModel>("GyroData", 1,0, "DataEntryModel");
    qmlRegisterType<QGyroFrame>("GyroData", 1,0, "QGyroFrame");
    qmlRegisterType<Chart>("GyroData", 1,0, "Chart");

    qRegisterMetaType<DataEntryModel*>("DataEntryModel");
    qRegisterMetaType<QGyroFrame*>("QGyroFrame");

    DataEntryModel model;
    engine.rootContext()->setContextProperty("dataEntry", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
