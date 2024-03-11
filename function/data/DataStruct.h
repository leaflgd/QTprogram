#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <QString>
#include <QStringList>

//事件列表数据，待定义
struct ST_PatientInformationData
{
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

#endif // DATASTRUCT_H
