#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QObject>
#include <QSqlDatabase>
#include "DataStruct.h"

/**
* @brief: 摘要
* @author: Fu_Lin
* @date:  2024-02-26
* @details: 数据库操作类，只操作数据库并赋值
* @note: 注意
* @blogs: https://blog.csdn.net/CLinuxF
*/

class DataBaseManagement : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseManagement(QObject *parent = nullptr);
    ~DataBaseManagement();

    enum QueryType{
        PhotoGallery = 0, //图片库
        Analyzed,  //已分析
        Counted     //已记数
    };

public slots:
    //连接数据库
    void connectDB();

    /**
     * @brief checkLogin    登录接口
     * @param userName   登录用户名
     * @param passwd        登录密码
     * @return 登录成功返回true， 登录失败返回false
     */
    bool checkLogin(const QString &userName, const QString &passwd);

    /**
     * @brief queryEventListData 查询事件列表接口
     * @param startDate  查询开始日期
     * @param endDate    查询结束日期
     * @param queryType 查询类型，参考QueryType
     * @param queryConditions 搜索查询过滤条件
     */
    QStringList queryEventListData(const QString & startDate, const QString & endDate,  const QString &queryConditions, int queryType);

    QStringList queryEventAllName();

    QStringList querySlideData( QString eventName );


    //通过slide_num查询图库
    QStringList querySlideDataImage(QString eventName, QString slideNum);

    //请求病人信息
    ST_PatientInformationData queryPatientInformation( QString eventname );
private :


signals:
    void sigLoginFinish(bool isLogin);
private:
    QSqlDatabase m_db;

    int m_eventId = -1;

};

#endif // DATABASEMANAGEMENT_H
