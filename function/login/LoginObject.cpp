#include "LoginObject.h"
#include "DataBaseThreadManager.h"
#include <QDebug>
#include <QMessageBox>

LoginObject::LoginObject(QObject *parent)
    : QObject{parent}
{

}

bool LoginObject::loginSystem(QString userName, QString userPasswd)
{
    qInfo()<<"loginSystem userName = "<<userName;
    if( userName.isEmpty() || userPasswd.isEmpty() )
    {
        QMessageBox::warning(nullptr, "登录提示","用户名或密码不能为空!");
        return false;
    }

    bool isLogin = DataBaseThreadManager::instance()->checkLogin(userName, userPasswd);

    if( !isLogin )
    {
        QMessageBox::warning(nullptr, "登录提示","登录失败， 用户名或密码错误!");
    }
    return isLogin;

}
