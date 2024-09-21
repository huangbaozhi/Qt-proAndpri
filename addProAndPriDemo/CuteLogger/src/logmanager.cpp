#include "logmanager.h"
#include <Logger.h>
#include <ConsoleAppender.h>
#include <RollingFileAppender.h>
#include <QDebug>

LogManager::LogManager()
{
    m_format = "%{time}{dd-MM-yyyy, HH:mm:ss.zzz} [%{type:-7}] [%{file:-25} %{line}] %{message}\n";
}

//初始化 Console Appender
void LogManager::initConsoleAppender(){
    m_consoleAppender = new ConsoleAppender;
    m_consoleAppender->setFormat(m_format);
    cuteLogger->registerAppender(m_consoleAppender);
}

//初始化文件 Appender
void LogManager::initRollingFileAppender(){
//    QString cachePath = QStandardPaths::standardLocations(QStandardPaths::CacheLocation).at(0);
    QString cachePath = qApp->applicationDirPath();
    qDebug()<<"cachePath = "<<cachePath;
    if (!QDir(cachePath).exists()){
        QDir(cachePath).mkpath(cachePath);
    }
    m_logPath = joinPath(cachePath, QString("%1.log").arg(qApp->applicationName()));
    m_rollingFileAppender = new RollingFileAppender(m_logPath);
    m_rollingFileAppender->setFormat(m_format);
    m_rollingFileAppender->setLogFilesLimit(5);
    m_rollingFileAppender->setDatePattern(RollingFileAppender::DailyRollover);
    cuteLogger->registerAppender(m_rollingFileAppender);
}

void LogManager::debug_log_console_on(){
    #if !defined(QT_NO_DEBUG)
    LogManager::instance()->initConsoleAppender();
    #endif
    LogManager::instance()->initRollingFileAppender();
}


QString LogManager::joinPath(const QString &path, const QString &fileName){
    QString separator(QDir::separator());
    return QString("%1%2%3").arg(path, separator, fileName);
}


QString LogManager::getlogFilePath(){
    return m_logPath;
}

LogManager::~LogManager()
{

}
