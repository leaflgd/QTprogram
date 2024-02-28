#ifndef DATABASETHREADMANAGER_H
#define DATABASETHREADMANAGER_H


///单例类, 数据库线程调用
///
#include <QObject>

class DataBaseThreadManagerPrivate;
class DataBaseThreadManager : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(DataBaseThreadManager)
    Q_DISABLE_COPY(DataBaseThreadManager)

public:
    explicit DataBaseThreadManager(QObject *parent = nullptr);


    static DataBaseThreadManager * instance();

    void checkLogin(QString userName, QString userPasswd);
signals:

private:
    DataBaseThreadManagerPrivate * d_ptr;
};

#endif // DATABASETHREADMANAGER_H
