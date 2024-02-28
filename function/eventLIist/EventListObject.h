#ifndef EVENTLISTOBJECT_H
#define EVENTLISTOBJECT_H

#include <QObject>
#include <QVariant>
#include <QtQml>

class EventListItemData;
class EventListObject : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(QVariant listItems READ listItems  NOTIFY listItemsChanged FINAL)
    Q_PROPERTY(QStringList patientInformations READ patientInformations NOTIFY patientInformationsChanged FINAL)
    Q_PROPERTY(QStringList patientTitle READ patientTitle  NOTIFY patientTitleChanged FINAL)

    Q_PROPERTY(QStringList chromosomeGallery READ chromosomeGallery  NOTIFY chromosomeGalleryChanged FINAL)
public:
    explicit EventListObject(QObject *parent = nullptr);

    /**
     * @brief startQueryEventListInfoData 开始调用事件列表页面所有信息
     */
    Q_INVOKABLE void startQueryEventListInfoData(){};

    Q_INVOKABLE void setPatientInformations( int eventItemDataIndex );

    QVariant listItems() const;

    QStringList patientInformations() const;

    QStringList patientTitle() const;

    QStringList chromosomeGallery() const;

signals:
    void listItemsChanged();
    void patientInformationsChanged();

    void patientTitleChanged();

    void chromosomeGalleryChanged();

private:
    QList<EventListItemData *> m_listItems;
    QStringList m_patientInformations;
    QStringList m_patientTitle;


    QStringList m_chromosomeGallery;
};

#endif // EVENTLISTOBJECT_H
