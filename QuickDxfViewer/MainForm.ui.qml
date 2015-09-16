import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

import io.quickcad.qmlcomponents 1.0

Item {
    width: 640
    height: 480

    property alias drawingClicked: drawingClicked

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: parent.width
        height: 30
        color: "#ffffff"
        Text {
            id: text1
            x: 8
            y: 8
            text: qsTr("Drawing name")
            font.bold: true
            wrapMode: Text.WordWrap
            font.pixelSize: 12
        }

        Text {
            id: text2
            x: 8
            y: 29
            height: 15
            anchors {
                left: text1.right
                leftMargin: 15
                right: parent.right
                rightMargin: 15
                top: text1.top
            }

            text: qsTr("<не выбрано>")
            font.pixelSize: 12
        }
    }

    SplitView {
        id: splitView1
        anchors {
            top: rectangle1.bottom
        }

        width: parent.width
        height: parent.height*0.8
        Rectangle {
            id: panelTools
            x: 251
            y: 0
            width: 64
            height: parent.height
            color: "#ffffff"           

        }
        Rectangle {
            id: panelView
            x: 251
            y: 8
            height: parent.height
            color: "#e2e2e2"
            anchors
            {
                left: panelTools.right
                right: parent.right
            }
            ScrollView{
                id: scrollingSpace
                anchors.fill: parent
                anchors.margins: 5
                contentItem:
                    DrawingCanvas {
                    id: drawing
                    width: panelView.width * 2
                    height: panelView.height * 2
                    MouseArea {
                        id: drawingClicked
                        anchors.fill: parent
                    }
                }
            }
        }
    }
    Rectangle {
        id: item3
        x: 251
        y: 8
        height: parent.height
        color: "#e2e2e2"
        anchors
        {
            top: splitView1.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
    }
}
