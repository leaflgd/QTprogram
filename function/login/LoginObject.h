#ifndef LOGINOBJECT_H
#define LOGINOBJECT_H

#include <QObject>
#include <QtQml>

class LoginObject : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit LoginObject(QObject *parent = nullptr);

    Q_INVOKABLE bool loginSystem(QString userName, QString userPasswd);
signals:
};

#endif // LOGINOBJECT_H
