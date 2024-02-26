#include "DataBaseManagement.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>


Q_GLOBAL_STATIC(DataBaseManagement, dbMs)
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

DataBaseManagement *DataBaseManagement::instance()
{
    return dbMs();
}

bool DataBaseManagement::checkLogin(const QString & userName, const QString & passwd)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", userName);
    query.bindValue(":password", passwd);

    return query.exec() && query.next();
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
        qWarning() << "Error opening database:" << m_db.lastError().text();
        // 处理连接错误
    } else {
        qWarning() << "Connected to database!";
        // 执行数据库操作

    }
}
