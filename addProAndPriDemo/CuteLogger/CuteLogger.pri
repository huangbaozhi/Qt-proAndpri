#QT       -= gui

#TARGET = CuteLogger

#TEMPLATE = lib

DEFINES += CUTELOGGER_LIBRARY

INCLUDEPATH += $$PWD/include

SOURCES += $$PWD/src/AbstractAppender.cpp \
           $$PWD/src/AbstractStringAppender.cpp \
           $$PWD/src/ConsoleAppender.cpp \
           $$PWD/src/FileAppender.cpp \
           $$PWD/src/Logger.cpp \
           $$PWD/src/OutputDebugAppender.cpp \
           $$PWD/src/RollingFileAppender.cpp \
    $$PWD/src/logmanager.cpp

HEADERS += $$PWD/include/AbstractStringAppender.h \
           $$PWD/include/ConsoleAppender.h \
           $$PWD/include/CuteLogger_global.h \
           $$PWD/include/FileAppender.h \
           $$PWD/include/Logger.h \
           $$PWD/include/OutputDebugAppender.h \
           $$PWD/include/RollingFileAppender.h \
    $$PWD/include/logmanager.h

#win32 {
#    SOURCES += src/OutputDebugAppender.cpp
#    HEADERS += include/OutputDebugAppender.h
#}

#android {
#    SOURCES += src/AndroidAppender.cpp
#    HEADERS += include/AndroidAppender.h
#}

unix {
    target.path = /usr/lib
    INSTALLS += target
}
