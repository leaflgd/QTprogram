import QtQuick 2.12
import QtQuick.Controls 2.5

Button {
    id: control
    text: qsTr("Button")

    property string backgroundColor: "#1E90FF"
    property string pressedBackgroundColor: "#1C86EE"

    property string textColor: "white"

    property int radius

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: textColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: control.width
        implicitHeight: control.height

        radius: control.radius
        opacity: enabled ? 1 : 0.3
        color: control.pressed?pressedBackgroundColor:backgroundColor

    }
}
