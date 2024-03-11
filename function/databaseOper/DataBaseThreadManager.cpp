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

bool DataBaseThreadManager::checkLogin(QString userName, QString userPasswd)
{
    Q_D( DataBaseThreadManager );

    bool isLogin = d->sigLoginUser( userName , userPasswd );
    return  isLogin;
}

QStringList DataBaseThreadManager::queryEventImageData(const QString &startDate, const QString &endData, const QString &queryConditions, int queryType)
{
    Q_D(DataBaseThreadManager);

    return d->queryEventImageData(
        startDate,
        endData,
        queryConditions,
        queryType);
}

QStringList DataBaseThreadManager::queryEventGlassSliderData()
{
    Q_D(DataBaseThreadManager);

    return d->queryEventGlassSliderData();
}

QStringList DataBaseThreadManager::queryEventGlassSubData( QString eventName )
{
    Q_D(DataBaseThreadManager);

    return d->queryEventGlassSubData(eventName);
}

QStringList DataBaseThreadManager::querySlideDataImage(QString eventName, QString slideNum)
{
    Q_D(DataBaseThreadManager);
    return d->querySlideDataImage( eventName, slideNum );
}

//请求病人信息
ST_PatientInformationData DataBaseThreadManager::queryPatientInformation(QString eventname)
{
    Q_D(DataBaseThreadManager);
    return d->queryPatientInformation( eventname );
}
