import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuickStartTutorial 1.0

ApplicationWindow {
    id: root
    width: 300
    height: 480
    visible: true

    BackEnd {
        id: backend
    }



    Button {
        id: startBluetooth
        text: "Start device discovery"
        anchors.horizontalCenter: parent
        onClicked: {
            btserv.initializeLocalDevice();
            btserv.startDeviceDiscovery();
        }

    }

    Button {
        id: stopBluetooth
        text: "Start Service Discovery"
        anchors.top: startBluetooth.bottom
        onClicked: {
            btserv.startServiceDiscovery();
        }
    }

    TextField {
        id: textinputname
        text: backend.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent

        onEditingFinished: backend.userName = text
    }
    Text {
        id: textoutput
        text: backend.userName
        anchors.top: textinputname.bottom
    }
}
