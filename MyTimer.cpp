#include "MyTimer.h"

MyTimer::MyTimer(QObject *parent) : QObject(parent)
{
}

MyTimer::MyTimer(QString *myName, QObject *parent) : QObject(parent)
{
    this->myName.append(myName);
}

MyTimer::~MyTimer()
{

}

void MyTimer::setName(QString myNameString)
{
    this->myName.append(myNameString);
}

void MyTimer::start(QString alarmClockTimeStr)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    alarmClockTimeString = alarmClockTimeStr;
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QDateTime alarmClockTime = QDateTime::fromString(alarmClockTimeString, "yyyy-MM-dd hh:mm:ss");
    alarmClockSecs = currentDateTime.secsTo(alarmClockTime);
#if MYTIMER_DEBUG
    qDebug()<<"MyTimer:";
    qDebug()<<alarmClockSecs<<"秒后超时!";
#endif
    timer->start(alarmClockSecs * 1000);
}

void MyTimer::start(QString myNameString, QString alarmClockTimeStr)
{
    this->myName.append(myNameString);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    alarmClockTimeString = alarmClockTimeStr;
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QDateTime alarmClockTime = QDateTime::fromString(alarmClockTimeString, "yyyy-MM-dd hh:mm:ss");
    alarmClockSecs = currentDateTime.secsTo(alarmClockTime);
#if MYTIMER_DEBUG
    qDebug()<<"MyTimer:";
    qDebug()<<alarmClockSecs<<"秒后超时!";
#endif
    timer->start(alarmClockSecs * 1000);
}

void MyTimer::start(qint64 Secs)
{
    alarmClockSecs = Secs;
    timer->start(alarmClockSecs * 1000);
}

QString MyTimer::getAlarmClockTime()
{
    return alarmClockTimeString;
}

QString MyTimer::getAlarmClockName()
{
    return myName;
}

void MyTimer::onTimeout()
{
#if MYTIMER_DEBUG
    qDebug()<<"MyTimer:";
    qDebug()<<"接收到超时信号!";
#endif
    emit timerTimeout(myName);
}
