#ifndef DATABASETHREADMANAGERPRIVATE_H
#define DATABASETHREADMANAGERPRIVATE_H

#include <QObject>
#include <QThread>

class DataBaseManagement;
class DataBaseThreadManager;
class DataBaseThreadManagerPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(DataBaseThreadManager)

public:
    explicit DataBaseThreadManagerPrivate(DataBaseThreadManager * parent);
    ~DataBaseThreadManagerPrivate();

signals:
    void sigLoginUser(QString userName, QString userPasswd);
private:
    DataBaseThreadManager *q_ptr;

    QThread m_workerThread;

    DataBaseManagement * p_DataBaseManagement = nullptr;
};

#endif // DATABASETHREADMANAGERPRIVATE_H
