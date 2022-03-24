#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "c4btservice.h"
#include <QLoggingCategory>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    C4BtService btserv;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("btserv", &btserv);
    const QUrl url(u"qrc:/QtQuickStartTutorial/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    qDebug() << "Finished loading";

    return app.exec();
}
