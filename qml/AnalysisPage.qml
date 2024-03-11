import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15
import QtQuick.Layouts 1.15
import com.f.cObject 1.0
import QtQuick.Controls 1.4 as Controls1
import "qrc:/qml/widget/"
import ".."

Rectangle {
    id:id_analysisPage_item

    color: "#CFCFCF"

    signal sigSelectDateChanged(string date);

    RowLayout{
        anchors.fill: parent
        spacing:0

        //![0] 事件数据
        Item{
            Layout.preferredWidth: 400
            Layout.preferredHeight: parent.height

            Layout.fillHeight: true
            // color:"red"
            Controls1.Calendar
            {
                id:id_calendar

                visible: false

                width: parent.width*0.9
                height: width
                anchors.centerIn: parent
                // property string currentSelectDate
                z:2
                onClicked:
                {
                    var selectedYear = selectedDate.getFullYear();
                    var selectedMonth = selectedDate.getMonth() + 1; // 月份从0开始，需要加1
                    var selectedDay = selectedDate.getDate();


                    let currentSelectDate = selectedYear+"年"+selectedMonth+"月"+selectedDay+"日"


                    id_calendar.visible = false
                    sigSelectDateChanged( currentSelectDate );

                }
            }

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
                        anchors.horizontalCenter: parent.horizontalCenter
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
                                Item{
                                    width: id_event_info_data_item.width
                                    height: id_listView.height

                                    ListView
                                    {
                                        id:id_listView
                                        width: parent.width
                                        height: 900

                                        spacing: 10
                                        model:AnalysisPageObject.itemObjectModel

                                        clip: true
                                        delegate: Item
                                        {
                                            id:id_item_root
                                            width: id_listView.width
                                            height: 48

                                            //color:index%2== 0?"red":"yellow"

                                            Loader
                                            {
                                                id:id_loader
                                                anchors.fill: parent

                                                onLoaded:
                                                {
                                                    item.titleName = model.modelData.titleName
                                                }
                                            }
                                            Connections
                                            {
                                                target: id_analysisPage_item
                                                enabled: model.modelData.itemType == AnalysisPageObject.Type_DateButton
                                                function  onSigSelectDateChanged(date){
                                                    if( id_loader.item.isSetDate ){
                                                        id_loader.item.isSetDate = false;
                                                        id_loader.item.dateText = date
                                                    }


                                                }
                                            }
                                            Component.onCompleted:
                                            {
                                                switch( model.modelData.itemType)
                                                {
                                                case AnalysisPageObject.Type_InputText:
                                                    id_loader.sourceComponent = id_inputTextComponent
                                                    break
                                                case AnalysisPageObject.Type_InputTextExpand:
                                                    id_loader.sourceComponent = id_inputTextComponent
                                                    id_item_root.height = 150
                                                    break;
                                                case AnalysisPageObject.Type_ComboBox:
                                                    id_loader.sourceComponent = id_textComboBoxComponent
                                                    id_loader.item.model = model.modelData.dataList
                                                    break;
                                                case AnalysisPageObject.Type_InputTextAndComboBox:
                                                    id_loader.sourceComponent = id_InputTextAndComboBoxComponent
                                                    id_loader.item.model = model.modelData.dataList
                                                    break;
                                                case AnalysisPageObject.Type_DateButton:
                                                    id_loader.sourceComponent = id_dateButtonComponent
                                                    break;
                                                case AnalysisPageObject.Type_InputTextAndCheckBox:
                                                    id_loader.sourceComponent = id_InputTextAndCheckBox_Component

                                                    break;

                                                }
                                            }

                                        }

                                        //![0]
                                        Component{
                                            id:id_inputTextComponent
                                            Item{
                                                id:id_inputText_item
                                                property alias titleName: id_textInput.title
                                                property bool flickInteractive: false

                                                FTextEdit
                                                {
                                                    id:id_textInput
                                                    anchors.fill: parent
                                                    flickInteractive:id_inputText_item.flickInteractive
                                                }
                                            }
                                        }
                                        //![0] End

                                        //![1] textCombox
                                        Component{
                                            id:id_textComboBoxComponent
                                            Item{
                                                property alias titleName: id_textComboxBox.title
                                                property alias model: id_textComboxBox.model

                                                FTextComboBox{
                                                    id:id_textComboxBox
                                                    anchors.fill: parent
                                                }

                                            }
                                        }
                                        //![1]

                                        //![2] Type_InputTextAndComboBox
                                        Component{
                                            id:id_InputTextAndComboBoxComponent
                                            Item{
                                                id:id_intpuAndComboBox_root
                                                property alias model:id_comboBox.model
                                                property alias titleName:id_textComboxBox.title

                                                Row{
                                                    FTextEdit{
                                                        id:id_textComboxBox
                                                        width: id_intpuAndComboBox_root.width - id_comboBox.width
                                                        height: id_intpuAndComboBox_root.height
                                                    }
                                                    ComboBox
                                                    {
                                                        id:id_comboBox
                                                        width: id_intpuAndComboBox_root.width*0.3
                                                        height: id_intpuAndComboBox_root.height

                                                        font.pointSize: CommonData.font_size_14

                                                    }
                                                }
                                            }
                                        }
                                        //![2]End

                                        //![3]日期按钮
                                        Component{
                                            id:id_dateButtonComponent
                                            Item
                                            {
                                                id:id_dateSelect_item

                                                property int curSelectDateType: 0

                                                // 定义一个属性来保存今天的日期
                                                property var today: new Date()
                                                property alias titleName:id_text_title.text
                                                property string dateText: id_dateSelect_item.today.toLocaleDateString()

                                                property bool isSetDate: false
                                                Row{
                                                    anchors.centerIn: parent
                                                    spacing: 9
                                                    Item{
                                                        id:id_textTitle_item
                                                        width:id_text_title.contentWidth
                                                        height: id_dateSelect_item.height
                                                        Text{
                                                            id:id_text_title

                                                            font.bold: true
                                                            font.pointSize: CommonData.font_size_14
                                                            color:"#1C1C1C"
                                                            anchors.left: parent.left
                                                            anchors.verticalCenter: parent.verticalCenter

                                                        }
                                                    }
                                                    FPushButton
                                                    {
                                                        id:id_startDateSelect_btn
                                                        width: id_dateSelect_item.width - id_textTitle_item.width - 12
                                                        height: id_dateSelect_item.height
                                                        text: id_dateSelect_item.dateText
                                                        font.bold: true
                                                        //  radius: height/2
                                                        font.pointSize:CommonData.font_size_16
                                                        onClicked:
                                                        {
                                                            id_dateSelect_item.isSetDate = true;
                                                            id_calendar.visible = true;
                                                        }
                                                    }

                                                }
                                            }
                                        }
                                        //![3] End

                                        //![4] checkbox 文本输入
                                        Component{
                                            id:id_InputTextAndCheckBox_Component
                                            Item{
                                                id:id_id_InputTextAndCheckBox_root

                                                property alias checked:id_checkBox.checked
                                                property alias titleName:id_textCheckTitleInput.title

                                                Row{
                                                    FTextEdit{
                                                        id:id_textCheckTitleInput
                                                        width: id_id_InputTextAndCheckBox_root.width - id_checkBox_item.width
                                                        height: id_id_InputTextAndCheckBox_root.height
                                                    }
                                                    Item{
                                                        id:id_checkBox_item
                                                        width: height
                                                        height: id_id_InputTextAndCheckBox_root.height
                                                        CheckBox
                                                        {
                                                            id:id_checkBox
                                                            // width: id_id_InputTextAndCheckBox_root.width*0.3
                                                            // height: id_id_InputTextAndCheckBox_root.height

                                                            anchors.centerIn: parent

                                                        }
                                                    }



                                                }
                                            }
                                        }
                                    }
                                }
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
                id:id_frame_item
                anchors.fill: parent
                anchors.margins: 10
                Column{
                    spacing: 10
                    bottomPadding:  10
                    Item{
                        width: id_frame_item.width  - 20
                        height: id_frame_item.height - id_bottomItem.height-25
                        Item{
                            id:id_flow_view_item
                        }
                        Item{
                            id:id_image

                        }
                    }

                    //底部状态栏： 当前核型
                    Item{
                        id:id_bottomItem
                        width: id_frame_item.width - 20
                        height: 58
                        FTextInput{
                            anchors.fill: parent

                            color:"#00000000"
                            border.color: "#868686"
                            intpuBackground:"#00000000"
                            intpuBorderColor: intpuBackground
                            round: false
                            title: "当前核型: "

                        }
                    }
                }


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
