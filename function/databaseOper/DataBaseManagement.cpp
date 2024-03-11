#include "DataBaseManagement.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include<QVariant>

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

bool DataBaseManagement::checkLogin(const QString & userName, const QString & passwd)
{
    if (!m_db.isOpen()) {
        qDebug() << "Database not open!";

        return false;  // 或者进行相应的处理
    }

    ///需要更新对应表数据
    QSqlQuery query(m_db);
    query.prepare("SELECT eventid FROM db_user WHERE loginname = :loginname AND loginpassword = :loginpasswo");
    query.bindValue(":loginname", userName);
    query.bindValue(":loginpasswo", passwd);
    // qDebug() << "SQL Query:" << query.lastQuery();

    bool isLogin = false;

    if( query.exec() && query.next() )
    {
        isLogin = true;
        m_eventId = query.value(0).toInt();
    }

    return isLogin;
}

QStringList DataBaseManagement::queryEventListData(const QString &startDate, const QString &endDate, const QString &queryConditions, int queryType)
{
    if (!m_db.isOpen()) {
        qDebug() << "Database not open!";

        return QStringList("");  // 或者进行相应的处理
    }
    qInfo()<<"startDate = "<<startDate;
    qInfo()<<"endDate = "<<endDate;
    qInfo()<<"queryConditions = "<<queryConditions;
    qInfo()<<"queryType = "<<queryType;
    qInfo()<<"m_eventId = "<<m_eventId;

    ///搜索图片
    QString queryImageSql = "SELECT a.greybasemappath FROM db_greybasemap a LEFT JOIN db_event b ON a.eventid = b.id WHERE a.eventid = :eventid AND b.createdate between :startdate and :enddate";
    ///搜索分析
    QString queryAnalysisSql = "SELECT a.greybasemappath FROM db_greybasemap a LEFT JOIN db_event b ON a.eventid = b.id WHERE a.eventid = :eventid  AND a.analysischeck=1 AND b.createdate between :startdate and :enddate;";
    ///搜索计数
    QString queryCountsisSql = "select a.greybasemappath from db_greybasemap a left join db_event b on a.eventid=b.id where a.eventid=:eventid  and a.countcheck=1 and b.createdate between :startdate and :enddate;";

    if( ! queryConditions.isEmpty() )
    {
        queryImageSql = "select a.greybasemappath from db_greybasemap a left join db_event b on a.eventid=b.id where a.eventid=:eventid  and  b.eventname= :eventname and b.createdate  between :startdate and :enddate;";
        queryAnalysisSql = "SELECT a.greybasemappath FROM db_greybasemap a "
                           "LEFT JOIN db_event b ON a.eventid = b.id "
                           "WHERE a.eventid = :eventid AND a.analysischeck = 1 AND "
                           "b.eventname = :eventname AND b.createdate BETWEEN :startdate AND :enddate;";

        queryCountsisSql = "select a.greybasemappath from db_greybasemap a left join db_event b on a.eventid=b.id where a.eventid=:eventid  and a.countcheck=1 and b.eventname= :eventname and b.createdate between :startdate and :enddate;";
    }


    QString exeSql;

    switch( queryType )
    {
    case PhotoGallery:
        exeSql = queryImageSql;
        break;
    case Analyzed:
        exeSql = queryAnalysisSql;
        break;
    case Counted:
        exeSql = queryCountsisSql;
        break;
    default:
        exeSql = queryImageSql;
    }
    qInfo()<<"exeSql = "<<exeSql;
    ///需要更新对应表数据
    QSqlQuery query( m_db );

    query.prepare( exeSql );

    query.bindValue(":eventid", QVariant(m_eventId));
    query.bindValue(":startdate", QVariant(startDate) );
    query.bindValue(":enddate", QVariant(endDate));

    if( ! queryConditions.isEmpty()  )
    {
        query.bindValue(":eventname", QVariant(queryConditions));
    }
    QStringList dirList;
    query.exec();

    while( query.next() )
    {
        QString dir = query.value(0).toString();
        dirList.append(dir);

    }


    return dirList;
}

QStringList DataBaseManagement::queryEventAllName()
{
    ///需要更新对应表数据
    QSqlQuery query( m_db );

    QString querySql = "SELECT eventname FROM db_event";
    query.prepare(querySql);

    query.exec();

    QStringList eventNames;
    while( query.next() )
    {
        eventNames.append(query.value(0).toString());
    }

    return eventNames;

}

QStringList DataBaseManagement::querySlideData(QString eventName)
{
    QSqlQuery sqlQuery(m_db);

    QString sql = "select a.slidenum from db_slide a left join db_event b on a.eventid = b.id where b.eventname=:eventName;";

    sqlQuery.prepare(sql);
    sqlQuery.bindValue(":eventName", eventName);

    sqlQuery.exec();

    QStringList glassSheetList;
    while( sqlQuery.next() )
    {
        QString glass = sqlQuery.value(0).toString();
        glassSheetList.append(glass);
    }

    return glassSheetList;
}

QStringList DataBaseManagement::querySlideDataImage(QString eventName, QString slideNum)
{
    QSqlQuery sqlQuery(m_db);

    // qInfo()<<"querySlideDataImage eventName = "<<eventName;
    // qInfo()<<"querySlideDataImage slideNum = "<<slideNum;

    QString sql = "select greybasemappath a from db_greybasemap a left join db_slide b on a.slideid = b.id left join db_event c on b.eventid=c.id where c.eventname=:eventName and b.slidenum= :slideNum;";

    sqlQuery.prepare(sql);
    sqlQuery.bindValue(":eventName", eventName);
    sqlQuery.bindValue(":slideNum", slideNum);

    sqlQuery.exec();
    QStringList dirList;
    while( sqlQuery.next() )
    {
        QString dir = sqlQuery.value(0).toString();
        // qInfo()<<"dir = "<<dir;
        dirList.append(dir);
    }

    return dirList;
}

ST_PatientInformationData DataBaseManagement::queryPatientInformation(QString eventname)
{
    ST_PatientInformationData patientInfo;

    QSqlQuery sqlQuery(m_db);

    //查询病人信息
    QString sql = "select a.medicalno,a.patientname,a.sex,a.diagnosis,a.opinion,"
                  "a.putasealon,a.kayotype from db_patient a "
                  " left join db_event b on a.eventid = b.id where b.eventname= :eventName;";

    sqlQuery.prepare( sql );
    sqlQuery.bindValue(":eventName", eventname);
    sqlQuery.exec();

    while( sqlQuery.next() )
    {
        patientInfo.m_patientNumber = sqlQuery.value(0).toString();
        patientInfo.m_patientName =  sqlQuery.value(1).toString();
        patientInfo.m_patientSex =  sqlQuery.value(2).toString();
        patientInfo.m_diagnosis =  sqlQuery.value(3).toString();
        patientInfo.m_diagnosticOpinion =  sqlQuery.value(4).toString();
        patientInfo.m_reportPrinter =  sqlQuery.value(5).toString();
        patientInfo.m_karyotype =  sqlQuery.value(6).toString();
    }

    //分析计数个数
    QString analysisCountSql = "select count(*) from db_greybasemap a left join db_event b on a.eventid = b.id where b.eventname=:eventName and a.analysischeck = 1;";
    sqlQuery.prepare( analysisCountSql );

    sqlQuery.bindValue(":eventName", eventname);
    sqlQuery.exec();
    while( sqlQuery.next() )
    {
        patientInfo.m_analyse = QString::number( sqlQuery.value(0).toInt() );
    }

    QString CountSql = "select count(*) from db_greybasemap a left join db_event b on a.eventid = b.id where b.eventname=:eventName and a.countcheck= 1;";
    sqlQuery.prepare( CountSql );

    sqlQuery.bindValue(":eventName", eventname);
    sqlQuery.exec();

    while( sqlQuery.next() )
    {
        patientInfo.m_count = QString::number( sqlQuery.value(0).toInt() );
    }

    return patientInfo;
}

void DataBaseManagement::connectDB()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE"); // 使用SQLite数据库驱动程序
    m_db.setDatabaseName("genedb.db"); // 设置数据库文件名

    ///******** 连接mysql
    //![0] 连接MySQL数据库
    // m_db = QSqlDatabase::addDatabase("QMYSQL");
    // m_db.setHostName("127.0.01");
    // m_db.setPort(3306);  // 默认MySQL端口
    // m_db.setDatabaseName("genedb");
    // m_db.setUserName("root");
    // m_db.setPassword("123456");
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
