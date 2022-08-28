import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 1024
    height: 600
    property alias button: button
    property alias  busyIndicator: busyIndicator
    header: Label {
        color: "#ddbfb5b5"
        text: qsTr("Veuillez commencer à insérer vos mégots ")
        font.pixelSize: Qt.application.font.pixelSize * 2
        font.bold: true

        wrapMode: Text.Wrap
        padding: 10
    }

    Button {
        id: button
        x: 612
        y: 370
        width: 222
        height: 59
        text: qsTr("VALIDER")
    }

    Rectangle {
        id: rectangle
        x: 443
        y: 98
        width: 391
        height: 71
        opacity: 0.3
        color: "red"
        radius: 20
    }

    Label {
        x: 462
        y: 145
        width: 354
        height: 43
        color: "#ddffffff"
        text: qsTr("appuyez sur valider une fois terminé")
        anchors.verticalCenter: rectangle.verticalCenter
        wrapMode: Text.Wrap
        anchors.verticalCenterOffset: 0
        font.bold: true
    }

    BusyIndicator {
        id: busyIndicator
        visible: false
        x: 238
        y: 370
    }

}
