#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QObject>
#include <QSqlDatabase>
#include "data/DataStruct.h"

/**
* @brief: 摘要
* @author: Fu_Lin
* @date:  2024-02-26
* @details: 数据库操作类，只操作数据库并赋值
* @note: 注意
* @blogs: https://blog.csdn.net/CLinuxF
*/

///单例类
class DataBaseManagement : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseManagement(QObject *parent = nullptr);
    ~DataBaseManagement();

    enum QueryType{
        PhotoGallery, //图片库
        Analyzed,  //已分析
        Counted     //已记数
    };

    static DataBaseManagement * instance();

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
     * @param eventlistData 查询后待赋值的数据结构
     */
    void queryEventListData(const QString & startDate, const QString * endDate, QueryType queryType, EventListData & eventlistData);
private:
    //连接数据库
    void connectDB();

signals:

private:
    QSqlDatabase m_db;

};

#endif // DATABASEMANAGEMENT_H
