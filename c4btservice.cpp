#include "c4btservice.h"

C4BtService::C4BtService(QObject *parent)
    : QObject{parent}
{
}

void C4BtService::initializeLocalDevice()
{
    // Check if Bluetooth is available on this device
    if (localDevice.isValid()) {

        // Turn Bluetooth on
        localDevice.powerOn();

        // Read local device name
        localDeviceName = localDevice.name();

        // Make it visible to others
        localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

        // Get connected devices
        QList<QBluetoothAddress> remotes;
        remotes = localDevice.connectedDevices();
    }
}



void C4BtService::startDeviceDiscovery()
{

    // Create a discovery agent and connect to its signals
    QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

    // Start a discovery
    QBluetoothDeviceDiscoveryAgent::DiscoveryMethod deviceTypes = QBluetoothDeviceDiscoveryAgent::DiscoveryMethod::ClassicMethod;
    discoveryAgent->start();
    qDebug() << "Starting device discovery";
    //...
}

void C4BtService::stopDeviceDiscovery(QBluetoothDeviceDiscoveryAgent &discoveryAgent)
{
    discoveryAgent.stop();
}

// In your local slot, read information about the found devices
void C4BtService::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
}

void C4BtService::startServiceDiscovery()
{

    // Create a discovery agent and connect to its signals
    QBluetoothServiceDiscoveryAgent *discoveryAgent = new QBluetoothServiceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(serviceDiscovered(QBluetoothServiceInfo)),
            this, SLOT(serviceDiscovered(QBluetoothServiceInfo)));

    // Start a discovery
    discoveryAgent->start();

    //...
}

// In your local slot, read information about the found devices
void C4BtService::serviceDiscovered(const QBluetoothServiceInfo &service)
{
    qDebug() << "Found new service:" << service.serviceName()
             << '(' << service.device().address().toString() << ')';
}
