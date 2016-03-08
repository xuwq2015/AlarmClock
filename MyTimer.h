#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QDebug>

#define MYTIMER_DEBUG 1

class MyTimer : public QObject
{
    Q_OBJECT
public:
    explicit MyTimer(QObject *parent = 0);
    explicit MyTimer(QString*, QObject *parent = 0);
    ~MyTimer();

    void setName(QString);
    void start(QString);
    void start(qint64);
    void start(QString, QString);
    QString getAlarmClockTime();
    QString getAlarmClockName();
private:
    QString myName;                     //定时器名称
    QString alarmClockTimeString;       //超时时间yyyy-MM-dd hh:mm:ss
    qint64 alarmClockSecs;              //定时器超时秒数

    QTimer *timer;
signals:
    void timerTimeout(QString);
public slots:
    void onTimeout();
};

#endif // MYTIMER_H
