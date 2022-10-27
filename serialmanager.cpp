#include "serialmanager.h"
#include <thread>


SerialManager::SerialManager(QObject *parent)
    : QObject{parent}
{

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
