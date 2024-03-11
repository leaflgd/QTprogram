#include "PatientInformationData.h"

PatientInformationData::PatientInformationData(QObject *parent)
    : QObject{parent}
{}


QString PatientInformationData::eventListItemName() const
{
    return m_eventListItemName;
}

void PatientInformationData::setEventListItemName(const QString &newEventListItemName)
{
    if (m_eventListItemName == newEventListItemName)
        return;
    m_eventListItemName = newEventListItemName;
    emit eventListItemNameChanged();
}

QString PatientInformationData::patientNumber() const
{
    return m_patientNumber;
}

void PatientInformationData::setPatientNumber(const QString &newPatientNumber)
{
    if (m_patientNumber == newPatientNumber)
        return;
    m_patientNumber = newPatientNumber;
    emit patientNumberChanged();
}

QString PatientInformationData::patientName() const
{
    return m_patientName;
}

void PatientInformationData::setPatientName(const QString &newPatientName)
{
    if (m_patientName == newPatientName)
        return;
    m_patientName = newPatientName;
    emit patientNameChanged();
}

QString PatientInformationData::patientSex() const
{
    return m_patientSex;
}

void PatientInformationData::setPatientSex(const QString &newPatientSex)
{
    if (m_patientSex == newPatientSex)
        return;
    m_patientSex = newPatientSex;
    emit patientSexChanged();
}

QString PatientInformationData::diagnosis() const
{
    return m_diagnosis;
}

void PatientInformationData::setDiagnosis(const QString &newDiagnosis)
{
    if (m_diagnosis == newDiagnosis)
        return;
    m_diagnosis = newDiagnosis;
    emit diagnosisChanged();
}

QString PatientInformationData::diagnosticOpinion() const
{
    return m_diagnosticOpinion;
}

void PatientInformationData::setDiagnosticOpinion(const QString &newDiagnosticOpinion)
{
    if (m_diagnosticOpinion == newDiagnosticOpinion)
        return;
    m_diagnosticOpinion = newDiagnosticOpinion;
    emit diagnosticOpinionChanged();
}

QString PatientInformationData::reportPrinter() const
{
    return m_reportPrinter;
}

void PatientInformationData::setReportPrinter(const QString &newReportPrinter)
{
    if (m_reportPrinter == newReportPrinter)
        return;
    m_reportPrinter = newReportPrinter;
    emit reportPrinterChanged();
}

QString PatientInformationData::karyotype() const
{
    return m_karyotype;
}

void PatientInformationData::setKaryotype(const QString &newKaryotype)
{
    if (m_karyotype == newKaryotype)
        return;
    m_karyotype = newKaryotype;
    emit karyotypeChanged();
}

QString PatientInformationData::analyse() const
{
    return m_analyse;
}

void PatientInformationData::setAnalyse(const QString &newAnalyse)
{
    if (m_analyse == newAnalyse)
        return;
    m_analyse = newAnalyse;
    emit analyseChanged();
}

QString PatientInformationData::count() const
{
    return m_count;
}

void PatientInformationData::setCount(const QString &newCount)
{
    if (m_count == newCount)
        return;
    m_count = newCount;
    emit countChanged();
}

