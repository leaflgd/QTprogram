pragma Singleton
import QtQuick 2.15

Item {

    enum PageType{
        LoginPage,                     //登录页面
        EventListPage,              //事件列表页面
        AnalysisPage                 //分析页面
    }

    property string loginPageUri: "qrc:/qml/LoginPage.qml"
    property string eventListPageUri: "qrc:/qml/EventListPage.qml"
    property string analysisPageUri: ""
    //默认登录页面
    property int curPageType:CommonData.LoginPage
    property string curPageUri: loginPageUri

    onCurPageTypeChanged:
    {
        switch(curPageType)
        {
        case CommonData.LoginPage:
            curPageUri = loginPageUri
            break;
        case CommonData.EventListPage:
            curPageUri = eventListPageUri
            break;
        case CommonData.AnalysisPage:
            curPageUri = analysisPageUri
            break;
        }
    }

    property int designScreenWidth: 1920
    property int designScreenHeight: 1080

    property int font_size_13:13
    property int font_size_14:14
    property int font_size_15:15
    property int font_size_16:16
    property int font_size_17:17
    property int font_size_18:18
    property int font_size_19:19
    property int font_size_20:20
    property int font_size_22:22
    property int font_size_24:24
    property int font_size_26:26
    property int font_size_28:28
    property int font_size_30:30
    property int font_size_32:32


}
