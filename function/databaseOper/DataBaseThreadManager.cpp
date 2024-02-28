#include "DataBaseThreadManager.h"
#include "DataBaseThreadManagerPrivate_p.h"

Q_GLOBAL_STATIC(DataBaseThreadManager, dbThreadMs)
DataBaseThreadManager::DataBaseThreadManager(QObject *parent)
    : QObject{parent},
    d_ptr(new DataBaseThreadManagerPrivate(this))
{

}

DataBaseThreadManager *DataBaseThreadManager::instance()
{
    return dbThreadMs();
}

void DataBaseThreadManager::checkLogin(QString userName, QString userPasswd)
{
    Q_D( DataBaseThreadManager );

    emit d->sigLoginUser( userName , userPasswd );
}
