#include "DataBaseManagement.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

DataBaseManagement::DataBaseManagement(QObject *parent)
    : QObject{parent}
{
    //连接数据库
    connectDB();
}

DataBaseManagement::~DataBaseManagement()
{
    if( m_db.isOpen() )
    {
        m_db.close();
    }
}

void DataBaseManagement::checkLogin(const QString & userName, const QString & passwd)
{
    ///需要更新对应表数据
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", userName);
    query.bindValue(":password", passwd);

    bool isLogin = false;
    if( query.exec() && query.next() )
    {
        isLogin = true;
    }
    Q_EMIT sigLoginFinish(isLogin);
   // return
}

void DataBaseManagement::queryEventListData(const QString &startDate, const QString *endDate, QueryType queryType, EventListData &eventlistData)
{
    ///todo... 待实现
}

void DataBaseManagement::connectDB()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE"); // 使用SQLite数据库驱动程序
    m_db.setDatabaseName("your_database_file.db"); // 设置数据库文件名

    ///******** 连接mysql
    //![0] 连接MySQL数据库
    // m_db = QSqlDatabase::addDatabase("QMYSQL");
    // m_db.setHostName("your_mysql_host");
    // m_db.setPort(3306);  // 默认MySQL端口
    // m_db.setDatabaseName("your_database_name");
    // m_db.setUserName("your_username");
    // m_db.setPassword("your_password");
    ///![0]

    if (!m_db.open()) {

        QMessageBox::warning(nullptr, "数据库提示","数据库连接失败!");

        qWarning() << "Error opening database:" << m_db.lastError().text();
        // 处理连接错误
    } else {
        qWarning() << "Connected to database!";
        // 执行数据库操作

    }
}
