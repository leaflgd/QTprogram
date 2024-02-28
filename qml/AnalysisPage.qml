import QtQuick 2.15
import QtQuick.Controls 2.15

import QtQuick.Layouts 1.15
import com.f.cObject 1.0

import "qrc:/qml/widget/"
import ".."

Rectangle {

    color: "#CFCFCF"

    RowLayout{
        anchors.fill: parent
        spacing:0

        //![0] 事件数据
        Item{
            Layout.preferredWidth: 400
            Layout.preferredHeight: parent.height

            Layout.fillHeight: true
            // color:"red"

            Frame{
                anchors.fill: parent
                anchors.margins: 10

                //![0] 数据外框大小
                Flickable{
                    id:id_flickable

                    anchors.fill: parent


                    contentHeight: id_column.height
                    contentWidth: width

                    boundsBehavior: Flickable.StopAtBounds

                    clip: true


                    Column{
                        id:id_column

                        spacing: 15

                        //![0]按钮Item
                        Item{
                            id:id_btnArea_item
                            width: id_flickable.width
                            height: 59
                            ButtonGroup {
                                id:id_buttonGroup
                                buttons: id_row.children
                            }
                            Row{
                                id:id_row
                                anchors.fill: parent
                                FPushButton
                                {
                                    width: id_btnArea_item.width/2
                                    height: id_btnArea_item.height
                                    text : "分析"
                                    textColor: checked?"#1E90FF":"white"
                                    font.pointSize:CommonData.font_size_20
                                    font.bold: true
                                    checked: true
                                    autoExclusive: true
                                    backgroundColor: "transparent"
                                    pressedBackgroundColor: backgroundColor
                                    onClicked:
                                    {
                                        if(!checked)
                                        {
                                            checked = !checked;
                                        }
                                    }
                                }
                                FPushButton
                                {
                                    width: id_btnArea_item.width/2
                                    height: id_btnArea_item.height
                                    text:"计数"
                                    textColor: checked?"#1E90FF":"white"

                                    font.pointSize:CommonData.font_size_20
                                    font.bold: true
                                    backgroundColor: "transparent"
                                    pressedBackgroundColor: backgroundColor

                                    onClicked:
                                    {
                                        if(!checked)
                                        {
                                            checked = !checked;
                                        }
                                    }
                                }
                            }
                        }
                        //![0] Button

                        //![1] 事件信息数据
                        Item{
                            id:id_event_info_data_item
                            width: id_flickable.width
                            height: id_content_item.height

                            Column{
                                id:id_content_item

                                rightPadding: 9
                                leftPadding: 9

                                spacing: 15
                                //![0] 标题
                                Item{
                                    id:id_title_item
                                    width: id_event_info_data_item.width
                                    height: 42

                                    Text
                                    {
                                        anchors.centerIn: parent

                                        text:"事件信息"

                                        color:"#1E90FF"
                                        font.bold: true
                                        font.pointSize: CommonData.font_size_22
                                    }
                                }
                                //![1] 保存按钮
                                Item{
                                    width:  id_event_info_data_item.width
                                    height: 38

                                    FPushButton
                                    {
                                        width: parent.width*0.8
                                        height: 38

                                        anchors.centerIn: parent

                                        font.bold: true
                                        font.pointSize: CommonData.font_size_14

                                        text:"保存"
                                    }
                                }
                                //![1] 保存 按钮 Item end

                                //![2] 信息数据

                                //![2]


                            }
                        }
                        //![1] End
                    }
                }
            }

        }

        //![1] 图片浏览
        Item{
            Layout.fillWidth:  true
            Layout.fillHeight: true
            Layout.preferredHeight: parent.height

            //color:"blue"
            Frame{
                anchors.fill: parent
                anchors.margins: 10
            }
        }

        //![2] 按钮功能区域
        Item{
            Layout.preferredWidth: 400
            Layout.preferredHeight: parent.height

            Layout.fillHeight: true

         //  color:"yellow"
            Frame{
                anchors.fill: parent
                anchors.margins: 10
            }
        }
    }

}
