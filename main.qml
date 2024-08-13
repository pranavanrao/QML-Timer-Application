import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string fileName: "main.qml"

    Connections {
        target: timer

        onNotice: {
            console.log(fileName + " Slots called from source file!!!")
            timerLabel.text = data;
        }
    }

    Column {
        anchors.centerIn: parent

        Label {
            id: timerLabel
            text: "Timer"
            font.pointSize: 24

            anchors.horizontalCenter: parent
        }

        Row {
            id: btnRow
            spacing: 5

            Button {
                id: btnStart
                text: "START"

                width: 100
                height: 40

                onClicked: {
                    console.log(fileName + " START button clicked!!!")
                    timer.start()
                }
            }

            Button {
                id: btnStop
                text: "STOP"

                width: 100
                height: 40

                onClicked: {
                    console.log(fileName + " STOP button clicked!!!")
                    timer.stop()
                }
            }
        }
    }
}
