QT += quick sql widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32-msvc*: {
    QMAKE_CFLAGS *= /utf-8
    QMAKE_CXXFLAGS *= /utf-8
}

SOURCES += \
        function/databaseOper/DataBaseManagement.cpp \
        #function/databaseOper/DataBaseManagerThread.cpp \
        function/databaseOper/DataBaseThreadManager.cpp \
        function/databaseOper/DataBaseThreadManagerPrivate.cpp \
        function/eventLIist/EventListItemData.cpp \
        function/eventLIist/EventListObject.cpp \
        function/login/LoginObject.cpp \
        main.cpp

HEADERS += \
            function/data/DataStruct.h \
            function/databaseOper/DataBaseManagement.h \
            #function/databaseOper/DataBaseManagerThread.h \
            function/databaseOper/DataBaseThreadManager.h \
            function/databaseOper/DataBaseThreadManagerPrivate_p.h \
            function/eventLIist/EventListItemData.h \
            function/eventLIist/EventListObject.h \
            function/login/LoginObject.h

INCLUDEPATH += \
        function \
        function/databaseOper \
        function/login \
        function/eventLIist \
        function/data

RESOURCES += qml.qrc \
    image/image.qrc

CONFIG += qmltypes
QML_IMPORT_NAME = com.f.cObject
QML_IMPORT_MAJOR_VERSION = 1


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

