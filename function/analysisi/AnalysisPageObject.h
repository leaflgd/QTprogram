#ifndef ANALYSISPAGEOBJECT_H
#define ANALYSISPAGEOBJECT_H

#include <QObject>
#include <QQmlEngine>
#include <QVariant>

class AnalysisItemData;
class AnalysisPageObject : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(QVariant itemObjectModel READ itemObjectModel  NOTIFY itemObjectModelChanged FINAL)

public:
    explicit AnalysisPageObject(QObject *parent = nullptr);

    enum ItemTypeEnum{
        Type_InputText,
        Type_InputTextExpand,
        Type_ComboBox,
        Type_DateButton,
        Type_InputTextAndComboBox,
        Type_InputTextAndCheckBox
    };

    Q_ENUM(ItemTypeEnum);

public:
    void initAllData();

    QVariant itemObjectModel() const;

signals:
    void itemObjectModelChanged();
private:
    QList< AnalysisItemData * > m_itemObjectModel;
};

#endif // ANALYSISPAGEOBJECT_H
