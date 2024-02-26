import QtQuick 2.15
import QtQuick.Layouts 1.15


Rectangle {

    color:"red"
    Image{
        anchors.fill: parent

        source: "qrc:/eventListBackground.jpg"
    }

    RowLayout{
        anchors.fill: parent
        spacing:0
        Rectangle{
            id:id_leftItem

            Layout.preferredWidth: 500
            Layout.preferredHeight: parent.height
            Layout.fillHeight: true

            color:"#696969"

            Flickable{
                width: parent.width
                height: parent.height

                contentHeight: id_column.height

                Column{
                    id:id_column

                    spacing: 15

                    //按钮
                    Item{

                    }

                }
            }

        }
        Rectangle{
            id:id_rightItem

            Layout.fillWidth: true
            Layout.fillHeight: true

            color:"yellow"
        }
    }

}
