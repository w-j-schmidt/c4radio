#ifndef C4BTSERVICE_H
#define C4BTSERVICE_H


#include <QObject>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothservicediscoveryagent.h>

class C4BtService : public QObject
{
    Q_OBJECT
public:
    explicit C4BtService(QObject *parent = nullptr);
    QBluetoothLocalDevice localDevice;
    QString localDeviceName;

public slots:
    void startDeviceDiscovery();
    void stopDeviceDiscovery(QBluetoothDeviceDiscoveryAgent &discoveryAgent);
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void initializeLocalDevice();
    void startServiceDiscovery();
    void serviceDiscovered(const QBluetoothServiceInfo &service);



private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent = nullptr;

};

#endif // C4BTSERVICE_H
