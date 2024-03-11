#ifndef EVENTLISTOBJECT_H
#define EVENTLISTOBJECT_H

#include <QObject>
#include <QVariant>
#include <QQmlEngine>

class PatientInformationData;
class GlassSlideData;
class EventListObject : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(QStringList patientInformations READ patientInformations NOTIFY patientInformationsChanged FINAL)
    Q_PROPERTY(QStringList patientTitle READ patientTitle  NOTIFY patientTitleChanged FINAL)

    Q_PROPERTY(QStringList chromosomeGallery READ chromosomeGallery  NOTIFY chromosomeGalleryChanged FINAL)

    Q_PROPERTY(QVariant glassSliderObjectModel READ glassSliderObjectModel  NOTIFY glassSliderObjectModelChanged FINAL)

public:
    explicit EventListObject(QObject *parent = nullptr);

    Q_INVOKABLE void setPatientInformations( int eventItemDataIndex );


    QStringList patientInformations() const;

    QStringList patientTitle() const;

    QStringList chromosomeGallery() const;

    QVariant glassSliderObjectModel() const;

public slots:
    void queryEventImageData(const QString &startDate, const QString &endData, const QString &queryConditions, int queryType);
    //请求所有的eventName, 玻璃片容器名称
    void queryEventGlassSliderData();
    //请求玻璃片子数据
    void queryEventGlassSubData(QString glassSliderName);
    void cleanEventGlassSubData(QString glassSliderName);
    //点击玻璃片获取对应的图片
    void querySlideDataImage(QString eventName, QString slideNum);

    //请求病人信息
    void queryPatientInformation( QString eventname );
private:
    void cleanGlassSliderObjectModel();

    GlassSlideData * getGlassSlideObject(QString glassSheetContainerName);
signals:
    void listItemsChanged();
    void patientInformationsChanged();

    void patientTitleChanged();

    void chromosomeGalleryChanged();

    void glassSliderObjectModelChanged();

private:

    QList<GlassSlideData *> m_glassSliderObjectModel;
    QStringList m_patientInformations;
    QStringList m_patientTitle;


    QStringList m_chromosomeGallery;
};

#endif // EVENTLISTOBJECT_H
