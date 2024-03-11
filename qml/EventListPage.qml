import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Controls 1.4 as Controls1
import com.f.cObject 1.0
import "qrc:/qml/widget/"
import ".."

Rectangle {

    property string startDate: id_startDateSelect_btn.text
    property string endDate: id_endDateSelect_btn.text
    property int indexType:0  //0图片库，1"已分析", 2"已计数"
    property string searchText: id_serachTextField.text

    Component.onCompleted:
    {
        startDate = '2024/03/05'
        endDate = '2024/03/07'
        EventListObject.queryEventImageData(startDate, endDate, searchText, indexType)
        EventListObject.queryEventGlassSliderData();
    }

    Image{
        anchors.fill: parent

        source: "qrc:/eventListBackground.jpg"
    }

    function getCurrentDate( diffMonth )
    {
        let currentDate = new Date()
        var year = currentDate.getFullYear();
        var month = (currentDate.getMonth() + 1 ).toString().padStart(2, '0');
        var day = currentDate.getDate().toString().padStart(2, '0');

        if( diffMonth != 0 ){
            var twoMonthsAgo = new Date(currentDate);
            twoMonthsAgo.setMonth(twoMonthsAgo.getMonth() - 2);

            // 将日期格式化为字符串，这里使用toLocaleDateString()方法
            var formattedDate = twoMonthsAgo.toLocaleDateString(Qt.locale(), "yyyy/MM/dd");
            return formattedDate;
        }
        else{

            let ymd = year + "/" + month + "/" + day;

            return ymd;
        }


    }

    //![列表布局数据]
    RowLayout{
        anchors.fill: parent
        spacing:0
        Rectangle{
            id:id_leftItem

            Layout.preferredWidth: 500
            Layout.preferredHeight: parent.height
            Layout.fillHeight: true

            color:"#CFCFCF"

            Frame{
                anchors.fill: parent
                anchors.margins: 10

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
                                    text : "事件列表"
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
                                    text:"信息索引"
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

                        //![1] readioButton
                        Item{
                            id:id_radioButton_item
                            width: id_flickable.width
                            height: 59
                            ButtonGroup {
                                id:id_radioGroup
                            }
                            Row{
                                id:id_row_radio
                                //anchors.fill: parent
                                anchors.centerIn: parent
                                Repeater
                                {
                                    model:["图片库", "已分析", "已计数"]
                                    Item{
                                        width: id_radioButton_item.width/3
                                        height: id_radioButton_item.height

                                        property alias checked: id_radioButton.checked
                                        RadioButton {
                                            id:id_radioButton
                                            anchors.centerIn: parent

                                            autoExclusive: true
                                            checked: index == 0?true:false
                                            text:modelData
                                            font.pointSize: CommonData.font_size_14

                                            ButtonGroup.group: id_radioGroup
                                        }
                                        MouseArea
                                        {
                                            anchors.fill: parent
                                            onClicked:
                                            {

                                                if( !id_radioButton.checked )
                                                {
                                                    id_radioButton.checked = !id_radioButton.checked;
                                                    indexType = index
                                                    ///调用搜索接口
                                                    EventListObject.queryEventImageData(startDate, endDate, "", indexType)

                                                }

                                            }
                                        }
                                    }
                                }
                            }
                        }
                        //![1]

                        //![2] 日期选择
                        Item{
                            id:id_dateSelect_item

                            width:  id_flickable.width
                            height: 49

                            property int curSelectDateType: 0

                            // 定义一个属性来保存今天的日期
                            // property var today: new Date()

                            Row{
                                anchors.centerIn: parent
                                spacing: id_dateSelect_item.width/6
                                FPushButton
                                {
                                    id:id_startDateSelect_btn
                                    width: id_dateSelect_item.width/3 + 30
                                    height: id_dateSelect_item.height
                                    text: getCurrentDate(0) // id_dateSelect_item.today.toLocaleDateString()
                                    font.bold: true
                                    radius: height/2
                                    font.pointSize:CommonData.font_size_16
                                    onClicked:
                                    {
                                        id_dateSelect_item.curSelectDateType  = 0
                                        id_calendar.visible = true;
                                    }
                                }
                                FPushButton
                                {
                                    id:id_endDateSelect_btn
                                    width: id_dateSelect_item.width/3 + 30
                                    height: id_dateSelect_item.height
                                    text:getCurrentDate(3) /* {
                                        let futureDate = new Date(id_dateSelect_item.today.getTime() - 3 * 24 * 60 * 60 * 1000);
                                        return futureDate.toLocaleDateString();
                                    }*/
                                    radius: height/2
                                    font.bold: true
                                    font.pointSize:CommonData.font_size_16
                                    onClicked:
                                    {
                                        id_dateSelect_item.curSelectDateType = 1

                                        id_calendar.visible = true;
                                    }
                                }

                            }
                        }
                        //![2]

                        //![3] 搜索
                        Item{
                            id:id_search_item
                            width:  id_flickable.width
                            height: 49
                            Row{
                                spacing: 9
                                anchors.centerIn: parent
                                TextField {
                                    id:id_serachTextField
                                    height: id_search_item.height
                                    width: id_search_item.width - id_searchBtn.width*2
                                    placeholderText: qsTr("输入搜索内容")
                                    font.pointSize: CommonData.font_size_13
                                    selectByMouse: true
                                    selectedTextColor: "white"

                                }
                                FPushButton
                                {
                                    id:id_searchBtn
                                    width: height*2
                                    height: id_search_item.height
                                    text:"搜索"
                                    font.bold: true

                                    font.pointSize: CommonData.font_size_14

                                    onClicked: {
                                        id_searchBtn.focus = true
                                        ///调用搜索接口
                                        EventListObject.queryEventImageData(startDate, endDate, searchText, indexType)

                                    }
                                }
                            }
                        }
                        //![3]

                        //![4] 列表信息
                        Item{
                            width: id_flickable.width
                            height: 350
                            // color: "red"
                            //![Frame]

                            Frame {
                                anchors.fill: parent
                                anchors.margins: 10
                                ListView{
                                    id:id_listview
                                    anchors.fill: parent

                                    clip: true
                                    boundsBehavior: Flickable.StopAtBounds

                                    model:EventListObject.glassSliderObjectModel
                                    property int currentSIndex:0

                                    ScrollBar.vertical: ScrollBar { policy:ScrollBar.AlwaysOn }
                                    delegate: Item{
                                        width: id_listview.width
                                        height: id_glassNameItem.height + id_id_item_slide.height

                                        Behavior on height {
                                            NumberAnimation { duration: 400 }
                                        }

                                        Component.onCompleted:
                                        {
                                            if( index == 0)
                                            {
                                                EventListObject.queryPatientInformation(control.text);
                                            }
                                        }

                                        //![0] 玻璃片容器名称
                                        Rectangle{
                                            id:id_glassNameItem
                                            width: parent.width
                                            height: 42

                                            color: id_listview.currentSIndex == index?"#1C86EE": "transparent"
                                            radius: 3

                                            CheckBox {
                                                id:control
                                                checked: model.modelData.isExportedReport
                                                enabled: false
                                                text: model.modelData.glassSheetContainerName
                                                anchors.verticalCenter: parent.verticalCenter
                                                anchors.left: parent.left
                                                anchors.leftMargin: 18

                                                font.pointSize: CommonData.font_size_16
                                                font.bold: true
                                                contentItem: Text {
                                                    text: control.text
                                                    font: control.font

                                                    color: id_listview.currentSIndex == index?"white":"#1A1A1A"
                                                    verticalAlignment: Text.AlignVCenter
                                                    leftPadding: control.indicator.width + control.spacing
                                                }

                                            }
                                            MouseArea
                                            {
                                                anchors.fill: parent
                                                onClicked:
                                                {
                                                    //console.info("请求queryEventGlassSubData")

                                                    EventListObject.queryPatientInformation(control.text);

                                                    id_listview.currentSIndex = index
                                                    if( id_id_item_slide.glassSheetModel.length == 0 )
                                                    {
                                                        EventListObject.queryEventGlassSubData(control.text)
                                                    }
                                                    else
                                                    {
                                                        EventListObject.cleanEventGlassSubData(control.text);
                                                    }
                                                }
                                            }
                                        }
                                        //![0]
                                        //![1] 具体玻璃片
                                        Item{
                                            id:id_id_item_slide
                                            width: parent.width *0.8
                                            height: id_column_item_slide.height

                                            anchors.top: id_glassNameItem.bottom
                                            anchors.topMargin: 2
                                            property var glassSheetModel:model.modelData.glassSheet

                                            property int currentSSubIndex:-1

                                            Column
                                            {
                                                id:id_column_item_slide

                                                Repeater
                                                {
                                                    model:id_id_item_slide.glassSheetModel

                                                    Rectangle{
                                                        width: id_id_item_slide.width
                                                        height: 40
                                                        color: "transparent"
                                                        border.color: index == id_listview.currentSSubIndex?"#5B89FE":"transparent"
                                                        Text {
                                                            id:id_subSlideNum_text
                                                            text: modelData

                                                            font.pointSize: CommonData.font_size_14

                                                            color: index == id_id_item_slide.currentSSubIndex?"white":"#1A1A1A"

                                                            anchors.left: parent.left
                                                            anchors.leftMargin: 20
                                                            anchors.verticalCenter: parent.verticalCenter

                                                        }
                                                        MouseArea
                                                        {
                                                            anchors.fill: parent
                                                            onClicked:
                                                            {
                                                           //    console.info("请求querySlideDataImage", control.text , id_subSlideNum_text.text)
                                                                 id_id_item_slide.currentSSubIndex = index
                                                                EventListObject.querySlideDataImage( control.text , id_subSlideNum_text.text);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                    }
                                    //!delegate Item
                                }
                                //![ListView] END
                            }
                            //![Frame] End
                        }
                        //![4]End

                        //![5] 病人信息
                        Item{
                            id:id_patientInfo_item

                            width: id_flickable.width
                            height: id_dataColumn_item.height + id_dataColumn_item.spacing*id_repeater_item.count + id_title_item.height


                            Item{
                                id:id_title_item
                                width: parent.width
                                height: 42

                                Text
                                {
                                    anchors.centerIn: parent

                                    text:"病人信息"

                                    color:"#1E90FF"
                                    font.bold: true
                                    font.pointSize: CommonData.font_size_22

                                }
                            }

                            Frame{
                                id:id_frame_item
                                width: parent.width - 20
                                height: id_dataColumn_item.height + id_dataColumn_item.spacing * 3

                                anchors.top: id_title_item.bottom
                                anchors.topMargin: 10
                                anchors.horizontalCenter: parent.horizontalCenter

                                Column
                                {
                                    id:id_dataColumn_item
                                    spacing: 9
                                    anchors.centerIn: parent
                                    Repeater
                                    {
                                        id:id_repeater_item
                                        model:EventListObject.patientTitle

                                        Item{
                                            id:id_infoItem
                                            width:  id_frame_item.width - 20
                                            height: index == 4?150:48

                                            property int indexOf:index
                                            Row{
                                                spacing: 9
                                                Item{
                                                    width:id_text_title.contentWidth
                                                    height: 38
                                                    Text{
                                                        id:id_text_title
                                                        text:modelData + ":"

                                                        font.bold: true
                                                        font.pointSize: CommonData.font_size_14
                                                        color:"#1C1C1C"
                                                        anchors.left: parent.left
                                                        anchors.verticalCenter: parent.verticalCenter

                                                    }
                                                }

                                                Frame{
                                                    width: id_infoItem.width - id_text_title.contentWidth - 9
                                                    height: id_infoItem.height
                                                    Flickable {
                                                        id: flick

                                                        width: parent.width
                                                        height: parent.height

                                                        contentWidth: width
                                                        contentHeight: edit.paintedHeight
                                                        boundsBehavior: Flickable.StopAtBounds

                                                        interactive: index == 4? true:false
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
                                                            enabled: false
                                                            text: EventListObject.patientInformations[id_infoItem.indexOf]
                                                            onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)

                                                            //   font.bold: true
                                                            font.pointSize: CommonData.font_size_15

                                                            color:"#363636"
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                    }
                                }
                            }
                        }
                    }
                }
            }
            //![Frame] End

            Controls1.Calendar
            {
                id:id_calendar

                visible: false

                width: parent.width*0.9
                height: width
                anchors.centerIn: parent
                z:2
                onClicked:
                {
                    var selectedYear = selectedDate.getFullYear();
                    var selectedMonth = selectedDate.getMonth() + 1; // 月份从0开始，需要加1
                    var selectedDay = selectedDate.getDate();

                    if( id_dateSelect_item.curSelectDateType == 0 )
                    {
                        id_startDateSelect_btn.text = selectedYear+"/"+selectedMonth+"/"+selectedDay
                    }
                    else{
                        id_endDateSelect_btn.text = selectedYear+"/"+selectedMonth+"/"+selectedDay
                    }

                    id_calendar.visible = false

                }
            }

        }
        Rectangle{
            id:id_rightItem

            Layout.fillWidth: true
            Layout.fillHeight: true

            color:"#CFCFCF"

            Frame
            {
                anchors.fill: parent
                anchors.margins: 10

                GridView
                {
                    id:id_gridview
                    anchors.fill: parent

                    cellWidth: width/4
                    cellHeight: height/5

                    model: EventListObject.chromosomeGallery

                    boundsBehavior: Flickable.StopAtBounds
                    clip: true

                    delegate: Item
                    {
                        width:id_gridview.cellWidth
                        height:id_gridview.cellHeight

                        Image{

                            asynchronous:true
                            anchors.fill: parent

                            anchors.margins: 5

                            source: "file:///"+modelData

                        }

                        MouseArea
                        {
                            anchors.fill: parent

                            onClicked:
                            {
                                CommonData.curPageType = CommonData.AnalysisPage
                            }
                        }
                    }
                }
            }
        }
    }
    //![布局]


}
