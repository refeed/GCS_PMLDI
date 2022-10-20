#include "serialmanager.h"

SerialManager::SerialManager(QObject *parent)
    : QObject{parent}
{

}

void SerialManager::readFromSerial() {
    emit receivedData(33, 33, 33, 33, 33);
}
