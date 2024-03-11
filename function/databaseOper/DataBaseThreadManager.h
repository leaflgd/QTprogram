#ifndef DATABASETHREADMANAGER_H
#define DATABASETHREADMANAGER_H


///单例类, 数据库线程调用
///
#include <QObject>
#include "DataStruct.h"

class DataBaseThreadManagerPrivate;
class DataBaseThreadManager : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(DataBaseThreadManager)
    Q_DISABLE_COPY(DataBaseThreadManager)

public:
    explicit DataBaseThreadManager(QObject *parent = nullptr);


    static DataBaseThreadManager * instance();

    bool checkLogin(QString userName, QString userPasswd);

    QStringList queryEventImageData(const QString &startDate, const QString &endData, const QString &queryConditions, int queryType);

    QStringList queryEventGlassSliderData();
    QStringList queryEventGlassSubData(QString eventName);

    QStringList querySlideDataImage(QString eventName, QString slideNum);

    //请求病人信息
    ST_PatientInformationData queryPatientInformation( QString eventname );
signals:

private:
    DataBaseThreadManagerPrivate * d_ptr;
};

#endif // DATABASETHREADMANAGER_H
