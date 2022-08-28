#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QZXing.h"
#include "looper.h"
#include <QQmlContext>

Q_DECL_EXPORT int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QZXing::registerQMLTypes();
    QZXing::registerQMLImageProvider(engine);
    looper m_looper;


    engine.rootContext()->setContextProperty("looper", &m_looper);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    return app.exec();
}

