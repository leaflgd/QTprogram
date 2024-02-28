#include "EventListItemData.h"

EventListItemData::EventListItemData(QObject *parent)
    : QObject{parent}
{}


QString EventListItemData::eventListItemName() const
{
    return m_eventListItemName;
}

void EventListItemData::setEventListItemName(const QString &newEventListItemName)
{
    if (m_eventListItemName == newEventListItemName)
        return;
    m_eventListItemName = newEventListItemName;
    emit eventListItemNameChanged();
}

QString EventListItemData::patientNumber() const
{
    return m_patientNumber;
}

void EventListItemData::setPatientNumber(const QString &newPatientNumber)
{
    if (m_patientNumber == newPatientNumber)
        return;
    m_patientNumber = newPatientNumber;
    emit patientNumberChanged();
}

QString EventListItemData::patientName() const
{
    return m_patientName;
}

void EventListItemData::setPatientName(const QString &newPatientName)
{
    if (m_patientName == newPatientName)
        return;
    m_patientName = newPatientName;
    emit patientNameChanged();
}

QString EventListItemData::patientSex() const
{
    return m_patientSex;
}

void EventListItemData::setPatientSex(const QString &newPatientSex)
{
    if (m_patientSex == newPatientSex)
        return;
    m_patientSex = newPatientSex;
    emit patientSexChanged();
}

QString EventListItemData::diagnosis() const
{
    return m_diagnosis;
}

void EventListItemData::setDiagnosis(const QString &newDiagnosis)
{
    if (m_diagnosis == newDiagnosis)
        return;
    m_diagnosis = newDiagnosis;
    emit diagnosisChanged();
}

QString EventListItemData::diagnosticOpinion() const
{
    return m_diagnosticOpinion;
}

void EventListItemData::setDiagnosticOpinion(const QString &newDiagnosticOpinion)
{
    if (m_diagnosticOpinion == newDiagnosticOpinion)
        return;
    m_diagnosticOpinion = newDiagnosticOpinion;
    emit diagnosticOpinionChanged();
}

QString EventListItemData::reportPrinter() const
{
    return m_reportPrinter;
}

void EventListItemData::setReportPrinter(const QString &newReportPrinter)
{
    if (m_reportPrinter == newReportPrinter)
        return;
    m_reportPrinter = newReportPrinter;
    emit reportPrinterChanged();
}

QString EventListItemData::karyotype() const
{
    return m_karyotype;
}

void EventListItemData::setKaryotype(const QString &newKaryotype)
{
    if (m_karyotype == newKaryotype)
        return;
    m_karyotype = newKaryotype;
    emit karyotypeChanged();
}

QString EventListItemData::analyse() const
{
    return m_analyse;
}

void EventListItemData::setAnalyse(const QString &newAnalyse)
{
    if (m_analyse == newAnalyse)
        return;
    m_analyse = newAnalyse;
    emit analyseChanged();
}

QString EventListItemData::count() const
{
    return m_count;
}

void EventListItemData::setCount(const QString &newCount)
{
    if (m_count == newCount)
        return;
    m_count = newCount;
    emit countChanged();
}

QStringList EventListItemData::otherDatas() const
{
    return m_otherDatas;
}

void EventListItemData::setOtherDatas(const QStringList &newOtherDatas)
{
    if (m_otherDatas == newOtherDatas)
        return;
    m_otherDatas = newOtherDatas;
    emit otherDatasChanged();
}

QStringList EventListItemData::chromosomeGallery() const
{
    return m_chromosomeGallery;
}

void EventListItemData::setChromosomeGallery(const QStringList &newChromosomeGallery)
{
    if (m_chromosomeGallery == newChromosomeGallery)
        return;
    m_chromosomeGallery = newChromosomeGallery;
    emit chromosomeGalleryChanged();
}

bool EventListItemData::isExportedReport() const
{
    return m_isExportedReport;
}

void EventListItemData::setIsExportedReport(bool newIsExportedReport)
{
    if (m_isExportedReport == newIsExportedReport)
        return;
    m_isExportedReport = newIsExportedReport;
    emit isExportedReportChanged();
}
