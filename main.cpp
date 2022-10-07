#include <QGuiApplication>
#include <QQmlApplicationEngine>

// TODO
// 1. Data dummy (mencoba mengubah angka value agar dinamis)
// 2. Coba koneksi lewat serial terlebih dahulu, misal protokol string
// 3. Prioritas terakhir: map, karena hanya ditampilkan saja

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
