import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 1024
    height: 600

    property alias button: button
    property alias resultImage: resultImage

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
        x: 670
        y: 392
        width: 222 
        height: 59
        text: qsTr("TERMINER

*")
    }

    Rectangle {
        id: rectangle
        x: 16
        y: 91
        width: 309
        height: 71
        opacity: 0.3
        color: "red"
        radius: 20
    }

    Label {
        x: 113
        y: 145
        width: 276
        height: 43
        color: "#ddffffff"
        text: qsTr("utilisez votre téléphone pour scanner le Qrcode")
        anchors.verticalCenter: rectangle.verticalCenter
        wrapMode: Text.Wrap
        font.bold: true
        anchors.horizontalCenter: rectangle.horizontalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
    }

    BusyIndicator {
        id: busyIndicator

        x: 206
        y: 219
    }

    Image{
        id: resultImage

        x: 613
        y: 38
        width: 279
        height: 251
        sourceSize.width: 177
        sourceSize.height: 177

        cache: true;
    }
}
