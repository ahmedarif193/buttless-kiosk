import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    width: 1024
    height: 600
    visible: true
    title: qsTr("Tabs")
    Image {
        id: bg
        anchors.fill: parent
        source: "qrc:/imgs/bg.jpg"
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent

        Page1Form {
            id: page1
            background: Rectangle{
                color:"transparent"
            }
            Connections {
                target: page1.button
                function onClicked() {
                    var ret = looper.stageOne();
                    console.log("----------" + ret)
                    swipeView.currentIndex += 1;
                }
            }
        }

        Page2Form {
            id : page2
            background: Rectangle{
                color:"transparent"
            }
            Connections {
                id : azeaze

                target: page2.button
                function onClicked() {
                    page2.busyIndicator.visible = true
                    var ret = looper.stageTwo();
                    console.log("the ret of the looper.stageTwo in qml side is  : " + ret+ " waiting ....")                   
                }
            }
        }
        Page3Form {
            id : page3

            background: Rectangle{
                color:"transparent"
            }
        }
    }


    Connections {
        target: looper
        function onFinishedGatheringDataForItem(signalString, signalInt) {
            console.log("the ret from onFinishedGatheringDataForItem is  " + signalString + ", with value : "+ signalInt)
            page2.busyIndicator.visible = false
            swipeView.currentIndex += 1;
            page3.resultImage.source = "image://QZXing/encode/" + signalString + "&border=true"
            page3.resultImage.cache = false;
            page3.resultImage.cache = true;
        }
    }
}
