#ifndef EVENTLISTITEMDATA_H
#define EVENTLISTITEMDATA_H

#include <QObject>
#include <QMap>

class PatientInformationData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString eventListItemName READ eventListItemName WRITE setEventListItemName NOTIFY eventListItemNameChanged FINAL)
    Q_PROPERTY(QString patientNumber READ patientNumber WRITE setPatientNumber NOTIFY patientNumberChanged FINAL)
    Q_PROPERTY(QString patientName READ patientName WRITE setPatientName NOTIFY patientNameChanged FINAL)
    Q_PROPERTY(QString patientSex READ patientSex WRITE setPatientSex NOTIFY patientSexChanged FINAL)
    Q_PROPERTY(QString diagnosis READ diagnosis WRITE setDiagnosis NOTIFY diagnosisChanged FINAL)
    Q_PROPERTY(QString diagnosticOpinion READ diagnosticOpinion WRITE setDiagnosticOpinion NOTIFY diagnosticOpinionChanged FINAL)
    Q_PROPERTY(QString reportPrinter READ reportPrinter WRITE setReportPrinter NOTIFY reportPrinterChanged FINAL)
    Q_PROPERTY(QString karyotype READ karyotype WRITE setKaryotype NOTIFY karyotypeChanged FINAL)
    Q_PROPERTY(QString analyse READ analyse WRITE setAnalyse NOTIFY analyseChanged FINAL)
    Q_PROPERTY(QString count READ count WRITE setCount NOTIFY countChanged FINAL)

public:
    explicit PatientInformationData(QObject *parent = nullptr);

    QString eventListItemName() const;
    void setEventListItemName(const QString &newEventListItemName);

    QString patientNumber() const;
    void setPatientNumber(const QString &newPatientNumber);

    QString patientName() const;
    void setPatientName(const QString &newPatientName);

    QString patientSex() const;
    void setPatientSex(const QString &newPatientSex);

    QString diagnosis() const;
    void setDiagnosis(const QString &newDiagnosis);

    QString diagnosticOpinion() const;
    void setDiagnosticOpinion(const QString &newDiagnosticOpinion);

    QString reportPrinter() const;
    void setReportPrinter(const QString &newReportPrinter);

    QString karyotype() const;
    void setKaryotype(const QString &newKaryotype);

    QString analyse() const;
    void setAnalyse(const QString &newAnalyse);

    QString count() const;
    void setCount(const QString &newCount);




signals:

    void m_eventListItemNameChanged();

    void eventListItemNameChanged();

    void patientNumberChanged();

    void patientNameChanged();

    void patientSexChanged();

    void diagnosisChanged();

    void diagnosticOpinionChanged();

    void reportPrinterChanged();

    void karyotypeChanged();

    void analyseChanged();

    void countChanged();



private:
    //事件列表item数据，对应C505030(80/120.3)数据
    QString m_eventListItemName;

    //病人其它数据
    QString m_patientNumber;       //病人编号
    QString m_patientName;          //名称
    QString m_patientSex;               //性别
    QString m_diagnosis;                //临床诊断
    QString m_diagnosticOpinion;  //诊断意见
    QString m_reportPrinter;         //报告打印人
    QString m_karyotype;               //核型
    QString m_analyse;                   //分析
    QString m_count;                       //计数
};

#endif // EVENTLISTITEMDATA_H
