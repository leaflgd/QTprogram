#include "EventListObject.h"
#include "EventListItemData.h"

EventListObject::EventListObject(QObject *parent)
    : QObject{parent}
{

    for( int i= 0; i < 9; i ++)
    {
        EventListItemData * itemData= new EventListItemData(this);
        itemData->setEventListItemName("itemName" + QString::number(i));
        itemData->setPatientName(i%2==0?"战三":"李四");
        itemData->setPatientNumber(QString::number(i+1));
        itemData->setPatientSex(i%2==0?"女":"男");
        itemData->setDiagnosis("合格");
        itemData->setDiagnosticOpinion("DDEFE住院关闸，的点到为dddddddeff止tian d 诶案犯分分而非而非而非额而非而非");
        itemData->setReportPrinter("王 sir");
        itemData->setKaryotype("xy11");
        itemData->setAnalyse("没有问题");
        itemData->setCount("10");

        QStringList chorPics;
        for(int i = 0 ; i < 40 ; i++)
        {
           chorPics.append("qrc:/testImage.jpg");
        }
        itemData->setChromosomeGallery(chorPics);


        m_listItems.append( itemData );
    }

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
    m_patientInformations.clear();
    emit patientInformationsChanged();

    m_chromosomeGallery.clear();
    emit chromosomeGalleryChanged();

    EventListItemData * itemData = m_listItems.at(eventItemDataIndex);

    m_patientInformations.append( itemData->patientNumber() );
    m_patientInformations.append( itemData->patientName() );
    m_patientInformations.append( itemData->patientSex() );
    m_patientInformations.append( itemData->diagnosis() );
    m_patientInformations.append( itemData->diagnosticOpinion() );
    m_patientInformations.append( itemData->reportPrinter() );
    m_patientInformations.append( itemData->karyotype() );
    m_patientInformations.append( itemData->analyse() );
    m_patientInformations.append( itemData->count() );

    emit patientInformationsChanged();

    m_chromosomeGallery = itemData->chromosomeGallery();
    emit chromosomeGalleryChanged();
}

QVariant EventListObject::listItems() const
{
    return QVariant::fromValue(m_listItems);
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
