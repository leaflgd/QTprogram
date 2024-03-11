#ifndef ANALYSISITEMDATA_H
#define ANALYSISITEMDATA_H

#include <QObject>

class AnalysisItemData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList dataList READ dataList WRITE setDataList NOTIFY dataListChanged FINAL)
    Q_PROPERTY(QString textContent READ textContent WRITE setTextContent NOTIFY textContentChanged FINAL)
    Q_PROPERTY(QString titleName READ titleName WRITE setTitleName NOTIFY titleNameChanged FINAL)
    Q_PROPERTY(int itemType READ itemType WRITE setItemType NOTIFY itemTypeChanged FINAL)

public:
    explicit AnalysisItemData(QObject *parent = nullptr);

    QStringList dataList() const;
    void setDataList(const QStringList &newDataList);

    QString textContent() const;
    void setTextContent(const QString &newTextContent);

    QString titleName() const;
    void setTitleName(const QString &newTitleName);

    int itemType() const;
    void setItemType(int newItemType);

signals:
    void dataListChanged();
    void textContentChanged();

    void titleNameChanged();

    void itemTypeChanged();

private:
    QStringList m_dataList;
    QString m_textContent;
    QString m_titleName;
    int m_itemType;
};

#endif // ANALYSISITEMDATA_H
