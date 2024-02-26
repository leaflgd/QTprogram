#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QObject>
#include <QSqlDatabase>
///单例类
class DataBaseManagement : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseManagement(QObject *parent = nullptr);
    ~DataBaseManagement();

    static DataBaseManagement * instance();

    bool checkLogin(const QString &userName, const QString &passwd);
private:
    //连接数据库
    void connectDB();

signals:

private:
    QSqlDatabase m_db;

};

#endif // DATABASEMANAGEMENT_H
