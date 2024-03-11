import QtQuick 2.12
import QtQuick.Controls 2.15
import "../../"

Item{
    id:id_infoItem
    width:  50
    height: 42

    property alias editTextFont: edit.font
    property alias editText:edit.text
    property alias editEnable:edit.enabled

    property alias flickInteractive:flick.interactive

    property alias title:id_text_title.text;

    property int titleHeight:48
    Row{
        spacing: 9
        Item{
            id:id_textTitle_item
            width:id_text_title.contentWidth
            height: titleHeight
            Text{
                id:id_text_title

                font.bold: true
                font.pointSize: CommonData.font_size_14
                color:"#1C1C1C"
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter

            }
        }

        Frame{
            width: id_infoItem.width - id_textTitle_item.width - 12
            height: id_infoItem.height
            Flickable {
                id: flick

                width: parent.width
                height: parent.height

                contentWidth: width
                contentHeight: edit.paintedHeight
                boundsBehavior: Flickable.StopAtBounds

                interactive: true
                anchors.centerIn: parent
                clip: true

                function ensureVisible(r)
                {
                    if (contentX >= r.x)
                        contentX = r.x;
                    else if (contentX+width <= r.x+r.width)
                        contentX = r.x+r.width-width;
                    if (contentY >= r.y)
                        contentY = r.y;
                    else if (contentY+height <= r.y+r.height)
                        contentY = r.y+r.height-height;
                }

                TextEdit {
                    id: edit
                    width: flick.width
                    focus: true
                    wrapMode: TextEdit.Wrap
                    enabled: true

                    onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)

                    //   font.bold: true
                    font.pointSize: CommonData.font_size_15

                    color:"#363636"
                }
            }
        }
    }
}
