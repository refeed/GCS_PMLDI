#include "serialmanager.h"
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

    // TODO: Make a pop-up window when "Connect" is clicked

    SerialManager manager;

    QObject::connect(&manager, &SerialManager::receivedData,
                     [&](int speed, int distance, int roll, int pitch, int yaw) {
        QMetaObject::invokeMethod(
                    object,
                    "updateSensorText",
                    Q_ARG(QVariant, speed),
                    Q_ARG(QVariant, distance),
                    Q_ARG(QVariant, roll),
                    Q_ARG(QVariant, pitch),
                    Q_ARG(QVariant, yaw));
    });

    // TODO: Use arduino or dummy serial to test whether the serial module is working or not
    manager.enumeratePorts();
    manager.readFromSerial();

    return app.exec();
}
