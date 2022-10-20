#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QMetaObject>


// TODO
// 1. [Sudah] Data dummy (mencoba mengubah angka value agar dinamis)
// 2. Coba koneksi lewat serial terlebih dahulu, misal protokol string
//    Bisa menggunakan https://libserial.readthedocs.io/en/latest/tutorial.html
// 3. Prioritas terakhir: map, karena hanya ditampilkan saja

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlComponent component(&engine, "qrc:/main.qml");
    QObject *object = component.create();

    // TODO: Mencoba menjalankan method di thread lain
    // Atau gunakan mekanisme SLOT & SIGNAL di Qt
    QMetaObject::invokeMethod(
                object,
                "updateSensorText",
                Q_ARG(QVariant, 3),
                Q_ARG(QVariant, "some"),
                Q_ARG(QVariant, "some"),
                Q_ARG(QVariant, "some"),
                Q_ARG(QVariant, "some"));

    return app.exec();
}
