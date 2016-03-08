#ifndef TIMERMANAGE_H
#define TIMERMANAGE_H

#include <QObject>
#include <QTimer>
#include <QMessageBox>

#include "common.h"
#include "MyTimer.h"
#include "MusicPlayer.h"
#include "GlobalFunctions.h"

#define TIMERMANAGE_DEBUG 1

class TimerManage : public QObject
{
    Q_OBJECT
public:
    explicit TimerManage(QObject *parent = 0);
    void startTiming(EventStruct*);
private:
    struct TimerManageStruct {
        EventStruct eventList;
        MyTimer *myTimer;
    };
    QList<TimerManageStruct> timerList;
    //QList<EventStruct> eventList;

    QString alarmClockTime;

    QString getAlarmClockTime(int);
    void createOnceTimer();
    void onceTimeout(int index, QString myName);
signals:
    void timeOutRemind(QString);//超时
    void alarmClockDelay(QString);//延时
public slots:
    void onTimerTimeout(QString);
};

#endif // TIMERMANAGE_H
