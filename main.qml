import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("GCS Autonomus Vehicle PMLDI")

    function updateSensorText(speedNum, distanceNum, pitchNum, rollNum, yawNum) {
        // TODO Use this function to update the data label
        speedText.text = `${speedNum} m/s`;
        distanceText.text = `${distanceNum} m`;
        pitchText.text = `${pitchNum} °`;
        rollText.text = `${rollNum} °`;
        yawText.text = `${yawNum} °`;
    }

    Text {
        id: text1
        x: 14
        y: 18
        text: qsTr("SENSORS")
        font.pixelSize: 22
        font.styleName: "Normal"
    }

    Rectangle {
        id: rectangle
        x: 143
        y: 0
        width: 497
        height: 480
        color: "#9d9d9d"
    }

    Column {
        id: column
        x: 14
        y: 69
        width: 123
        height: 325
        spacing: 8

        Text {
            id: text2
            text: qsTr("SPEED")
            font.pixelSize: 13
            font.styleName: "Regular"
            font.family: "Roboto"
        }

        Text {
            id: speedText
            text: qsTr("0 m/s")
            font.pixelSize: 28
            font.family: "Roboto"
            font.styleName: "Regular"
        }

        Text {
            id: text4
            text: qsTr("DISTANCE")
            font.pixelSize: 13
            font.family: "Roboto"
            font.styleName: "Regular"
        }

        Text {
            id: distanceText
            text: qsTr("0 m")
            font.pixelSize: 28
            font.family: "Roboto"
            font.styleName: "Regular"
        }

        Text {
            id: text6
            text: qsTr("PITCH")
            font.pixelSize: 13
            font.family: "Roboto"
            font.styleName: "Regular"
        }

        Text {
            id: pitchText
            text: qsTr("0 °")
            font.pixelSize: 28
            font.family: "Roboto"
            font.styleName: "Regular"
        }

        Text {
            id: text8
            text: qsTr("YAW")
            font.pixelSize: 13
            font.family: "Roboto"
            font.styleName: "Regular"
        }

        Text {
            id: yawText
            text: qsTr("0 °")
            font.pixelSize: 28
            font.family: "Roboto"
            font.styleName: "Regular"
        }

        Text {
            id: text10
            text: qsTr("ROLL")
            font.pixelSize: 13
            font.family: "Roboto"
            font.styleName: "Regular"
        }

        Text {
            id: rollText
            text: qsTr("0 °")
            font.pixelSize: 28
            font.family: "Roboto"
            font.styleName: "Regular"
        }
    }

    Button {
        id: connectButton
        x: 6
        y: 407
        width: 131
        height: 61
        text: qsTr("Connect")
    }
}
