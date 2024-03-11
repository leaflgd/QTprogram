#ifndef DATABASETHREADMANAGERPRIVATE_H
#define DATABASETHREADMANAGERPRIVATE_H

#include <QObject>
#include <QThread>
#include "DataStruct.h"

class DataBaseManagement;
class DataBaseThreadManager;
class DataBaseThreadManagerPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(DataBaseThreadManager)

public:
    explicit DataBaseThreadManagerPrivate(DataBaseThreadManager * parent);
    ~DataBaseThreadManagerPrivate();

    //查询事件数据
    QStringList queryEventImageData(const QString & startDate, const QString & endData, const QString & queryConditions, int queryType);

    QStringList queryEventGlassSliderData();
    QStringList queryEventGlassSubData(QString eventName);

    QStringList querySlideDataImage(QString eventName, QString slideNum);

    ST_PatientInformationData queryPatientInformation( QString eventname );

private:
    QStringList filterImagesInDirectory(const QString &directoryPath);

signals:
    bool sigLoginUser(QString userName, QString userPasswd);
private:
    DataBaseThreadManager *q_ptr;

    QThread m_workerThread;

    DataBaseManagement * p_DataBaseManagement = nullptr;
};

#endif // DATABASETHREADMANAGERPRIVATE_H
