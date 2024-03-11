#include "DataBaseThreadManagerPrivate_p.h"
#include "DataBaseThreadManager.h"
#include "DataBaseManagement.h"
#include <QDir>
#include <QImageReader>

DataBaseThreadManagerPrivate::DataBaseThreadManagerPrivate(DataBaseThreadManager *parent)
    : QObject{parent},
    q_ptr(parent)
{
    p_DataBaseManagement = new DataBaseManagement(this);
    //   p_DataBaseManagement->moveToThread(&m_workerThread);

    //  connect(&m_workerThread, &QThread::started, p_DataBaseManagement, &DataBaseManagement::connectDB);
    connect(&m_workerThread, &QThread::finished, p_DataBaseManagement, &QObject::deleteLater);
    connect(this, &DataBaseThreadManagerPrivate::sigLoginUser, p_DataBaseManagement, &DataBaseManagement::checkLogin);

    // m_workerThread.start();
}

DataBaseThreadManagerPrivate::~DataBaseThreadManagerPrivate()
{

}

QStringList DataBaseThreadManagerPrivate::queryEventImageData(const QString &startDate, const QString &endData, const QString &queryConditions, int queryType)
{
    QStringList dirList = p_DataBaseManagement->queryEventListData(
        startDate,
        endData,
        queryConditions,
        queryType);

    qInfo()<<"dirList size = "<<dirList.size();
    QStringList imageFilePaths;
    for( auto dirPath : dirList)
    {
        imageFilePaths.append( filterImagesInDirectory(dirPath) );
    }

    return imageFilePaths;
}

QStringList DataBaseThreadManagerPrivate::queryEventGlassSliderData()
{
    return p_DataBaseManagement->queryEventAllName();
}

QStringList DataBaseThreadManagerPrivate::queryEventGlassSubData( QString eventName )
{
    return p_DataBaseManagement->querySlideData( eventName );
}

QStringList DataBaseThreadManagerPrivate::querySlideDataImage(QString eventName, QString slideNum)
{
    QStringList dirList = p_DataBaseManagement->querySlideDataImage(eventName,  slideNum);
    QStringList imageFilePaths;
    for( auto dirPath : dirList)
    {
        imageFilePaths.append( filterImagesInDirectory(dirPath) );
    }

    qInfo()<<"imageFilePaths size = "<<imageFilePaths.size();
    return imageFilePaths;
}

ST_PatientInformationData DataBaseThreadManagerPrivate::queryPatientInformation(QString eventname)
{
    return p_DataBaseManagement->queryPatientInformation( eventname );
}

QStringList DataBaseThreadManagerPrivate::filterImagesInDirectory(const QString &directoryPath) {

    QDir directory(directoryPath);
    // 设置过滤的文件后缀
    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png"; // 添加需要的图片格式

    QStringList filterImagePathFiles;
    // 设置文件过滤器
    directory.setNameFilters(filters);

    // 获取目录中的所有文件
    QStringList files = directory.entryList(QDir::Files);

    // 遍历文件列表
    foreach (const QString &fileName, files) {
        // 获取文件的完整路径
        QString filePath = directory.absoluteFilePath(fileName);

        // 使用QImageReader读取图片信息
        QImageReader imageReader(filePath);

        // 检查是否为有效的图片格式
        if ( !imageReader.format().isEmpty() ) {
            filterImagePathFiles.append( filePath );
        }
    }

    return filterImagePathFiles;
}
