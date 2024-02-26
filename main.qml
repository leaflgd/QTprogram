import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQml 2.15
import "./"

ApplicationWindow
{
    id:id_applicationWindow
    width: CommonData.designScreenWidth
    height: CommonData.designScreenHeight

    maximumWidth:width
    maximumHeight: height

    minimumWidth: width
    minimumHeight: height

    visible: true
    flags: Qt.WindowCloseButtonHint | Qt.WindowMinimizeButtonHint|Qt.CustomizeWindowHint | Qt.Dialog |Qt.WindowTitleHint

    title: qsTr("demo pro")


    Loader{
        anchors.fill: parent
        source:CommonData.curPageUri
    }

    Component.onCompleted:
    {
        id_applicationWindow.FullScreen
    }
}
