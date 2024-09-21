#include "mainwindow.h"
#include <QDateTime>
#include <Logger.h>
#include <ConsoleAppender.h>
#include <FileAppender.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString strFormat = "[%{type:-7}] <%{Function}> %{message}\n";

    FileAppender* fileAppender = new FileAppender(QDateTime::currentDateTime().toString("yy_MM_dd_hh_mm_ss.log"));
    fileAppender->setFormat(strFormat);
    cuteLogger->registerAppender(fileAppender);

    ConsoleAppender* consoleAppender = new ConsoleAppender;
    consoleAppender->setFormat(strFormat);
    cuteLogger->registerAppender(consoleAppender);
    LOG_INFO("Starting the application");

    int result = a.exec();
    if (result)
      LOG_WARNING() << "Something went wrong." << "Result code is" << result;
    return result;

//    MainWindow w;
//    w.show();
//    return a.exec();
}
