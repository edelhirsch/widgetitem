/******************************************************************************
 * WidgetItem - Copyright (C) 2019 Edelhirsch Software GmbH
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *****************************************************************************/

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
