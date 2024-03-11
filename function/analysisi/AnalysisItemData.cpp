#include "AnalysisItemData.h"

AnalysisItemData::AnalysisItemData(QObject *parent)
    : QObject{parent}
{}

QStringList AnalysisItemData::dataList() const
{
    return m_dataList;
}

void AnalysisItemData::setDataList(const QStringList &newDataList)
{
    if (m_dataList == newDataList)
        return;
    m_dataList = newDataList;
    emit dataListChanged();
}

QString AnalysisItemData::textContent() const
{
    return m_textContent;
}

void AnalysisItemData::setTextContent(const QString &newTextContent)
{
    if (m_textContent == newTextContent)
        return;
    m_textContent = newTextContent;
    emit textContentChanged();
}

QString AnalysisItemData::titleName() const
{
    return m_titleName;
}

void AnalysisItemData::setTitleName(const QString &newTitleName)
{
    if (m_titleName == newTitleName)
        return;
    m_titleName = newTitleName;
    emit titleNameChanged();
}

int AnalysisItemData::itemType() const
{
    return m_itemType;
}

void AnalysisItemData::setItemType(int newItemType)
{
    if (m_itemType == newItemType)
        return;
    m_itemType = newItemType;
    emit itemTypeChanged();
}
