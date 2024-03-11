#include "EventListObject.h"
#include "DataBaseThreadManager.h"
#include "GlassSlideData.h"
#include <QMessageBox>

EventListObject::EventListObject(QObject *parent)
    : QObject{parent}
{

    m_patientTitle.append( "编号" );
    m_patientTitle.append( "姓名" );
    m_patientTitle.append( "社会性别" );
    m_patientTitle.append( "临床诊断" );
    m_patientTitle.append( "诊断意见" );
    m_patientTitle.append( "阅片及报告打印人" );
    m_patientTitle.append( "核型" );
    m_patientTitle.append( "分析" );
    m_patientTitle.append( "计数" );

    emit patientTitleChanged();
}

void EventListObject::setPatientInformations(int eventItemDataIndex)
{

}

QStringList EventListObject::patientInformations() const
{
    return m_patientInformations;
}

QStringList EventListObject::patientTitle() const
{
    return m_patientTitle;
}

QStringList EventListObject::chromosomeGallery() const
{
    return m_chromosomeGallery;
}

void EventListObject::queryEventImageData(const QString &startDate, const QString &endData, const QString &queryConditions, int queryType)
{
    QStringList images = DataBaseThreadManager::instance()->queryEventImageData(
        startDate,
        endData,
        queryConditions,
        queryType
        );

    m_chromosomeGallery = images;

    qInfo()<<"images size = "<<images;
    emit chromosomeGalleryChanged();
}

void EventListObject::queryEventGlassSliderData()
{
    QStringList glassSliderDataList = DataBaseThreadManager::instance()->queryEventGlassSliderData();

    cleanGlassSliderObjectModel();

    for( auto glassSlider : glassSliderDataList)
    {
        GlassSlideData * glassItem = new GlassSlideData(this);
        glassItem->setGlassSheetContainerName( glassSlider );

        m_glassSliderObjectModel.append( glassItem );
    }

    emit glassSliderObjectModelChanged();
}

void EventListObject::queryEventGlassSubData( QString glassSliderName )
{
    auto glassSliderHandle = getGlassSlideObject(glassSliderName);
    if( glassSliderHandle ){

        QStringList glassSliderDataList ;
        if( glassSliderHandle->backupsGlassSheet().isEmpty() )
        {
            glassSliderDataList = DataBaseThreadManager::instance()->queryEventGlassSubData(glassSliderName);
        }
        else
        {
            glassSliderDataList = glassSliderHandle->backupsGlassSheet();
        }

        if( !glassSliderDataList.isEmpty() )
        {
            glassSliderHandle->setGlassSheet( glassSliderDataList );
            glassSliderHandle->setBackupsGlassSheet( glassSliderDataList );

            emit glassSliderObjectModelChanged();
        }
    }

}

void EventListObject::cleanEventGlassSubData( QString glassSliderName )
{
    auto glassSliderHandle = getGlassSlideObject(glassSliderName);

    if( glassSliderHandle ){
        glassSliderHandle->cleanGlassSheetData();
    }
}

void EventListObject::querySlideDataImage(QString eventName, QString slideNum)
{
    m_chromosomeGallery.clear();
    QStringList images = DataBaseThreadManager::instance()->querySlideDataImage(
        eventName,
        slideNum
        );

    m_chromosomeGallery = images;

    qInfo()<<"images size = "<<images;
    if( m_chromosomeGallery.isEmpty() )
    {
        QMessageBox::warning(nullptr, "查询提示","没有查询到数据!");
    }
    emit chromosomeGalleryChanged();
}

void EventListObject::queryPatientInformation(QString eventname)
{
    m_patientInformations.clear();
    emit patientInformationsChanged();

    qInfo()<<" queryPatientInformation eventName = "<<eventname;
    ST_PatientInformationData patientData = DataBaseThreadManager::instance()->queryPatientInformation( eventname );

    m_patientInformations.append( patientData.m_patientNumber );
    m_patientInformations.append( patientData.m_patientName );
    m_patientInformations.append( patientData.m_patientSex );
    m_patientInformations.append( patientData.m_diagnosis );
    m_patientInformations.append( patientData.m_diagnosticOpinion );
    m_patientInformations.append( patientData.m_reportPrinter );
    m_patientInformations.append( patientData.m_karyotype );
    m_patientInformations.append( patientData.m_analyse );
    m_patientInformations.append( patientData.m_count );

    emit patientInformationsChanged();
}

void EventListObject::cleanGlassSliderObjectModel()
{
    qDeleteAll( m_glassSliderObjectModel ) ;
    m_glassSliderObjectModel.clear();

    emit glassSliderObjectModelChanged();
}

GlassSlideData *EventListObject::getGlassSlideObject( QString glassSheetContainerName )
{
    for ( auto glassObjectItem: m_glassSliderObjectModel )
    {
        if( glassObjectItem->glassSheetContainerName() == glassSheetContainerName )
        {
            return glassObjectItem;
        }
    }

    return nullptr;
}

QVariant EventListObject::glassSliderObjectModel() const
{
    return QVariant::fromValue( m_glassSliderObjectModel );
}

