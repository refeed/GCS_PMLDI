#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>

class SerialManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parent = nullptr);
    void readFromSerial();

signals:
    void receivedData(int speed, int distance, int roll, int pitch, int yaw);
};

#endif // SERIALMANAGER_H
