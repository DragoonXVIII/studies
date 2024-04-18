#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


#include "./lsm.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;


    LSM *LSMcalculator = new LSM;
    engine.rootContext()->setContextProperty("LSMcalculator",LSMcalculator);


    const QUrl url(u"qrc:/AAN_chart_app/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
