#include "TimerManage.h"

TimerManage::TimerManage(QObject *parent) : QObject(parent)
{
}

void TimerManage::startTiming(EventStruct *eventString)
{
    TimerManageStruct timeStruct;
    timeStruct.eventList.date = eventString->date;
    timeStruct.eventList.frequency = eventString->frequency;
    timeStruct.eventList.status = eventString->status;
    timeStruct.eventList.string = eventString->string;
    timeStruct.eventList.Surplus = eventString->Surplus;
    timeStruct.eventList.time = eventString->time;

    timerList.append(timeStruct);
    switch (eventString->frequency) {
    case FREQU_ONCE:
        createOnceTimer();
        break;
    case FREQU_EVERYDAY:

        break;
    case FREQU_WEEKLY:

        break;
    case FREQU_PERMONTH:

        break;
    case FREQU_PERYEAR:

        break;
    case FREQU_INTERVAL:

        break;
    default:
        break;
    }
}

void TimerManage::createOnceTimer()
{
    int timerListIndex = timerList.size() - 1;
    alarmClockTime = getAlarmClockTime(timerListIndex);

    timerList[timerListIndex].myTimer = new MyTimer(this);
    timerList.at(timerListIndex).myTimer->setName(timerList.at(timerListIndex).eventList.string);
    timerList.at(timerListIndex).myTimer->start(alarmClockTime);

    connect(timerList.at(timerListIndex).myTimer, SIGNAL(timerTimeout(QString)), this, SLOT(onTimerTimeout(QString)));
}

QString TimerManage::getAlarmClockTime(int timerListIndex)
{
    QString clockTimeString = timerList.at(timerListIndex).eventList.date;
    clockTimeString.append(' ');
    clockTimeString.append(timerList.at(timerListIndex).eventList.time);
    return clockTimeString;
}

void TimerManage::onTimerTimeout(QString myName)
{
    for (int num = 0; num < timerList.size(); num++) {
        if (!timerList.at(num).eventList.string.compare(&myName, Qt::CaseSensitive)) {
            switch (timerList.at(num).eventList.frequency) {
                case FREQU_ONCE:
                    onceTimeout(num, myName);
                    break;
                case FREQU_EVERYDAY:

                    break;
                case FREQU_WEEKLY:

                    break;
                case FREQU_PERMONTH:

                    break;
                case FREQU_PERYEAR:

                    break;
                case FREQU_INTERVAL:

                    break;
                default:
                    warningInfo("无定时器：" + myName + "信息");
                    break;
            }
        }
    }
}

void TimerManage::onceTimeout(int index, QString myName)
{
    MusicPlayer player(QString("定时器超时：" + myName), NULL);
    if (player.exec()) {
        timerList.at(index).myTimer->~MyTimer();
        timerList.removeAt(index);
        emit timeOutRemind(timerList.at(index).eventList.string);
    } else {
        timerList.at(index).myTimer->start(300);
        emit alarmClockDelay(timerList.at(index).eventList.string);
    }
}
