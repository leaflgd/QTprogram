import QtQuick 2.15
import QtQuick.Controls 2.15
import "../../"

Rectangle {
    id:id_ftextInput
    width: id_row_item.width

    property string title: ""
    property string titleColor: "#363636"

    property alias font:id_title_text.font
    property alias placeholderText:id_textField.placeholderText
    property string intpuBorderColor :"#6495ED"
    property string intpuBackground: "#80FFFFFF"
    property bool round: true
    property int textFieldWidth:300
    property int intputHeight: height

    property alias echoMode:id_textField.echoMode

    property alias display: id_textField.displayText

    property int leftPadding:15
    Row{
        id:id_row_item
        spacing: 8

        Item{
            height:intputHeight
            width:id_title_text.contentWidth + id_ftextInput.leftPadding
         //   color:"red"
            Text{
                id:id_title_text
                text:id_ftextInput.title
                color:id_ftextInput.titleColor
                anchors.left: parent.left
                anchors.leftMargin: id_ftextInput.leftPadding
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: CommonData.font_size_28
                font.bold: true

            }
        }


        TextField {
            id: id_textField
          //  placeholderText: qsTr("Enter description")

            font.pixelSize: CommonData.font_size_20

            background: Rectangle {
                implicitWidth: textFieldWidth
                implicitHeight: intputHeight
                radius: round?height/2:1
                color:intpuBackground

                border.color: id_textField.enabled ?intpuBorderColor : "transparent"
                border.width: round?0:1
            }
        }
    }
}
