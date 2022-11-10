#include "serialmanager.h"
#include <thread>
#include <serial/serial.h>

using std::vector;

SerialManager::SerialManager(QObject *parent)
    : QObject{parent}
{

}

void SerialManager::enumeratePorts() {
    vector<serial::PortInfo> devicesFound = serial::list_ports();

    for (vector<serial::PortInfo>::iterator it = devicesFound.begin(); it != devicesFound.end(); ++it) {
        serial::PortInfo device = *it;
        printf("(%s, %s, %s)\n", device.port.c_str(), device.description.c_str(), device.hardware_id.c_str());
    }
}

void SerialManager::readFromSerial() {
    // TODO: Replace this with the real data
    std::thread receiveDataThread([this](){
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            emit receivedData(
                        rand() % 10,
                        rand() % 10,
                        rand() % 10,
                        rand() % 10,
                        rand() % 10);
        }
    });
    receiveDataThread.detach();
}
