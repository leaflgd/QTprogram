#include "GlassSlideData.h"
#include "qdebug.h"

GlassSlideData::GlassSlideData(QObject *parent)
    : QObject{parent}
{}

void GlassSlideData::cleanGlassSheetData()
{
    m_glassSheet.clear();
    emit glassSheetChanged();
}

void GlassSlideData::cleanBackupsGlassSheetData()
{
    m_backupsGlassSheet.clear();
    emit backupsGlassSheetChanged();
}

QStringList GlassSlideData::glassSheet() const
{
    return m_glassSheet;
}

void GlassSlideData::setGlassSheet(const QStringList &newGlassSheet)
{
    qInfo()<<"setGlassSheet newGlassSheet = "<<newGlassSheet;
    if (m_glassSheet == newGlassSheet)
        return;
    m_glassSheet = newGlassSheet;
    emit glassSheetChanged();
}

QString GlassSlideData::glassSheetContainerName() const
{
    return m_glassSheetContainerName;
}

void GlassSlideData::setGlassSheetContainerName(const QString &newGlassSheetContainerName)
{
    if (m_glassSheetContainerName == newGlassSheetContainerName)
        return;
    m_glassSheetContainerName = newGlassSheetContainerName;
    emit glassSheetContainerNameChanged();
}

bool GlassSlideData::isExportedReport() const
{
    return m_isExportedReport;
}

void GlassSlideData::setIsExportedReport(bool newIsExportedReport)
{
    if (m_isExportedReport == newIsExportedReport)
        return;
    m_isExportedReport = newIsExportedReport;
    emit isExportedReportChanged();
}

QStringList GlassSlideData::backupsGlassSheet() const
{
    return m_backupsGlassSheet;
}

void GlassSlideData::setBackupsGlassSheet(const QStringList &newBackupsGlassSheet)
{
    if (m_backupsGlassSheet == newBackupsGlassSheet)
        return;
    m_backupsGlassSheet = newBackupsGlassSheet;
    emit backupsGlassSheetChanged();
}
