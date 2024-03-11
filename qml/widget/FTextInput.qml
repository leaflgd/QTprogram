import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "../../"

Rectangle {
    id:id_ftextInput
    width: id_row_item.width

    property string title: ""
    property string titleColor: "#4F4F4F"

    property alias font:id_title_text.font
    property alias placeholderText:id_textField.placeholderText
    property string intpuBorderColor :"#6495ED"
    property string intpuBackground: "#80FFFFFF"
    property bool round: true
    property int textFieldWidth: id_ftextInput.width - id_titleItem.width - leftPadding*2
    property int intputHeight: height


    property alias text:id_textField.text
    property alias echoMode:id_textField.echoMode

    property alias display: id_textField.displayText
    property alias displayText: id_textField.text

    property int leftPadding:15
    Row{
        id:id_row_item
        spacing: 8

        Item{
            id:id_titleItem
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
                font.pointSize: CommonData.font_size_18
                font.bold: true

            }
        }


        TextField {
            id: id_textField
          //  placeholderText: qsTr("Enter description")

            font.pixelSize: CommonData.font_size_20

            selectByMouse:true
            selectedTextColor:"white"
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
