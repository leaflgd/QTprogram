#ifndef GLASSSLIDEDATA_H
#define GLASSSLIDEDATA_H

#include <QObject>

class GlassSlideData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList glassSheet READ glassSheet WRITE setGlassSheet NOTIFY glassSheetChanged FINAL)
    Q_PROPERTY(QStringList backupsGlassSheet READ backupsGlassSheet WRITE setBackupsGlassSheet NOTIFY backupsGlassSheetChanged FINAL)
    Q_PROPERTY(QString glassSheetContainerName READ glassSheetContainerName WRITE setGlassSheetContainerName NOTIFY glassSheetContainerNameChanged FINAL)
    Q_PROPERTY(bool isExportedReport READ isExportedReport WRITE setIsExportedReport NOTIFY isExportedReportChanged FINAL)
public:
    explicit GlassSlideData(QObject *parent = nullptr);


    void cleanGlassSheetData();
    void cleanBackupsGlassSheetData();

    QStringList glassSheet() const;
    void setGlassSheet(const QStringList &newGlassSheet);

    QString glassSheetContainerName() const;
    void setGlassSheetContainerName(const QString &newGlassSheetContainerName);

    bool isExportedReport() const;
    void setIsExportedReport(bool newIsExportedReport);

    QStringList backupsGlassSheet() const;
    void setBackupsGlassSheet(const QStringList &newBackupsGlassSheet);

signals:

    void glassSheetChanged();

    void glassSheetContainerNameChanged();

    void isExportedReportChanged();

    void backupsGlassSheetChanged();

private:

    bool m_isExportedReport = false; //是否导致报告

    //玻璃片集合名称
    QStringList m_glassSheet;
    //玻璃片容器名称
    QString m_glassSheetContainerName;
    QStringList m_backupsGlassSheet;
};

#endif // GLASSSLIDEDATA_H
