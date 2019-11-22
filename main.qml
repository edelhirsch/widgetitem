import QtQuick 2.12
import QtQuick.Window 2.12
import WidgetItem 1.0

Window {
    visible: true
    width: 450
    height: 70
    title: qsTr("Hello Widget")

    Rectangle {
        anchors.fill: parent
        Text {
            id: text
            anchors.margins: 20
            text: "This text is created with QML, the item below is a QWidget:"
        }

        WidgetItem {
            anchors.top: text.bottom
            anchors.topMargin: 15
            width: parent.width
            height: parent.height - text.height
        }
    }

    Shortcut {
        sequence: "Ctrl+q"
        onActivated: Qt.quit()
    }
}
