import QtQuick 2.15
import QtQuick.Controls 2.15
import "./widget"
import "../"
import com.f.cObject 1.0

Item {

    //![0] 背景
    Image{
        anchors.fill: parent
        source: "qrc:/loginBackground.jpg"
    }

    //![1] 登录
    Item{
        width: parent.width*0.4
        height: parent.height*0.4

        anchors.centerIn: parent
        //    color:"red"

        Column{
            spacing: 40
            anchors.centerIn: parent
            FTextInput{
                id:id_userNameInput
                height: 50
                title: "用户名:"
                placeholderText:"请输入登录用户名"
                color:"#80FFFFFF"
                intpuBackground: "transparent"
                radius: height/2
                text:"ceshi"
                textFieldWidth:300
            }
            FTextInput{
                id:id_passwdInput
                height: 50
                title: "密  码:"
                placeholderText:"请输入登录密码"
                color:"#80FFFFFF"
                intpuBackground: "transparent"
                radius: height/2
                echoMode: TextInput.Password
                text:"123456"
                textFieldWidth:300

            }

            Item{
                width: id_userNameInput.width
                height: id_userNameInput.height*2
                FPushButton
                {
                    width: parent.width
                    height: id_userNameInput.height
                    anchors.bottom: parent.bottom
                    text:"登 录"
                    font.bold: true
                    font.pointSize: CommonData.font_size_20
                    radius:height/2

                    onClicked:
                    {
                        let isLogin = LoginObject.loginSystem( id_userNameInput.display, id_passwdInput.displayText );
                        if( isLogin )
                        {
                            CommonData.curPageType = CommonData.EventListPage
                        }
                    }
                }
            }

        }
    }


}
