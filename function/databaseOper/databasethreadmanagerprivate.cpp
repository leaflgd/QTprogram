#include "DataBaseThreadManagerPrivate_p.h"
#include "DataBaseThreadManager.h"
#include "DataBaseManagement.h"

DataBaseThreadManagerPrivate::DataBaseThreadManagerPrivate(DataBaseThreadManager *parent)
    : QObject{parent},
       q_ptr(parent)
{
    p_DataBaseManagement = new DataBaseManagement();
    p_DataBaseManagement->moveToThread(&m_workerThread);

    connect(&m_workerThread, &QThread::finished, p_DataBaseManagement, &QObject::deleteLater);
    connect(this, &DataBaseThreadManagerPrivate::sigLoginUser, p_DataBaseManagement, &DataBaseManagement::checkLogin);
    m_workerThread.start();
}

DataBaseThreadManagerPrivate::~DataBaseThreadManagerPrivate()
{
    m_workerThread.quit();
    m_workerThread.wait();
}
