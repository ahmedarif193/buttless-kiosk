import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 1024
    height: 600
    property alias button: button1

    header: Label {
        color: "#ddbfb5b5"
        text: qsTr("insérez des mégots aujourd'hui et sauvez l'écosystème mondial demain")
        font.pixelSize: Qt.application.font.pixelSize * 2
        font.bold: true

        wrapMode: Text.Wrap
        padding: 10
    }

    Button {
        id: button1
        x: 667
        y: 352
        width: 222
        height: 59
        text: qsTr(" insérer les mégots")
    }

    Rectangle {
        id: rectangle
        x: 268
        y: 192
        width: 391
        height: 71
        opacity: 0.3
        color: "red"
        radius: 20
    }

    Label {
        x: 287
        y: 206
        width: 354
        height: 43
        color: "#ddffffff"
        text: qsTr("pour démarrer l'assistant, appuyez sur insérer les mégots")
        wrapMode: Text.Wrap
        font.bold: true
    }
}
