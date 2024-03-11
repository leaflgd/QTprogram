import QtQuick 2.15
import QtQuick.Controls 2.15
import "../../"

Item {
    id:id_ftextInput
    width: id_row_item.width

    property string title: ""
    property string titleColor: "#1C1C1C"

    property alias font:id_title_text.font

    property int intputHeight: height


    property alias display: id_comboBox.displayText

    property alias model:id_comboBox.model

    property int leftPadding:15
    Row{
        id:id_row_item
        spacing: 8

        Item{
            id:id_title_item
            height:intputHeight
            width:id_title_text.contentWidth
         //   color:"red"
            Text{
                id:id_title_text
                text:id_ftextInput.title
                color:id_ftextInput.titleColor
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: CommonData.font_size_14
                font.bold: true

            }
        }

        ComboBox {
            id: id_comboBox
            width: id_ftextInput.width - id_title_item.width - id_row_item.spacing
            height: id_ftextInput.height

            font.pixelSize: CommonData.font_size_18
        }
    }
}
