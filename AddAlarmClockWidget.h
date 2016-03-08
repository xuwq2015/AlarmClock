#ifndef ADDALARMCLOCKWIDGET_H
#define ADDALARMCLOCKWIDGET_H

#include <QDialog>
#include <QLabel>
#include <QIcon>
#include <QDebug>
#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTime>
#include <QSpinBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QStackedWidget>
//#include <QAbstractSpinBox>

#include "common.h"
#include "GlobalFunctions.h"

#define ADDALARMCLOCKWIDGET_DEBUG 1

class AddAlarmClockWidget : public QDialog
{
    Q_OBJECT
public:
    AddAlarmClockWidget(EventStruct *eventList, QWidget *parent = 0);
private:
    EventStruct *eventList;

    QVBoxLayout *mainLayout;
    QHBoxLayout *firstHLayout;
    QHBoxLayout *frequencyHLayout;
    QHBoxLayout *secondHLayout;
    QHBoxLayout *thirdHLayout;
    QHBoxLayout *fourthHLayout;
    QHBoxLayout *fifthHLayout;
    QHBoxLayout *sixthHLayout;

    QLabel *numberLabel;
    QLineEdit *numberLineEdit;

    QLabel *frequencyLabel;
    QRadioButton *onceButton;
    QRadioButton *everyDayButton;
    QRadioButton *weeklyButton;
    QRadioButton *perMonthButton;
    QRadioButton *perYearButton;
    QRadioButton *intervalButton;
    QButtonGroup *frequencyButtonGroup;

    QStackedWidget *stackedWidget;

    /*onceWidget窗口所需控件(循环次数:一次)*/
    QWidget *onceWidget;
    QHBoxLayout *onceWidgetLayout;
    QSpinBox *yearAbstractSpinBox;
    QSpinBox *monthAbstractSpinBox;
    QSpinBox *dayAbstractSpinBox;
    QLabel *yearLabel;
    QLabel *monthLabel;
    QLabel *dayLabel;

    /*everyDayWidget窗口所需控件(循环次数:每天)*/
    QWidget *everyDayWidget;
    QHBoxLayout *everyDayWidgetLayout;
    QLabel *everyDayLabel;

    /*weeklyWidget窗口所需控件(循环次数:每周)*/
    QWidget *weeklyWidget;
    QHBoxLayout *weeklyLayout;
    QCheckBox *sundayCheckBox;
    QCheckBox *mondayCheckBox;
    QCheckBox *tuesdayCheckBox;
    QCheckBox *wednesdayCheckBox;
    QCheckBox *thursdayCheckBox;
    QCheckBox *fridayCheckBox;
    QCheckBox *saturdayCheckBox;

    /*perMonthWidget窗口所需控件(循环次数:每月)*/
    QWidget *perMonthWidget;
    QHBoxLayout *perMonthWidgetLayout;
    QSpinBox *perMonthSpinBox;
    QLabel *perMonthLabel;

    /*perYearWidget窗口所需控件(循环次数:每年)*/
    QWidget *perYearWidget;
    QHBoxLayout *perYearWidgetLayout;
    QSpinBox *perYearSpinBox;
    QLabel *perYearLabel;

    /*intervalWidget窗口所需控件(循环次数:间隔)*/
    QWidget *intervalWidget;
    QHBoxLayout *intervalWidgetLayout;
    QSpinBox *daysAbstractSpinBox;
    QSpinBox *hourAbstractSpinBox;
    QSpinBox *minuteAbstractSpinBox;
    QSpinBox *secondAbstractSpinBox;
    QLabel *daysLabel;
    QLabel *hourLabel;
    QLabel *minuteLabel;
    QLabel *secondLabel;
    QLabel *remindedOnceLabel;

    QLabel *alarmClockTimeDataLabel;

    QLabel *alarmClockTimeLabel;
    QTimeEdit *alarmClockTimeEdit;

    QLabel *alarmClockLabel;
    QLineEdit *alarmClockLineEdit;

    QLabel *remarkLabel;
    QLineEdit *remarkLineEdit;

    QPushButton *determineButton;
    QPushButton *cancelButton;

    void createStackedWidget();
    void setStackedWidgetLayout();
    void addOncedWidgetControls();
    void addIntervalWidgetControls();
    void createFrequencyWidget();
    void addEveryDayWidgetControls();
    void addWeeklyWidgetControls();
    void addperMonthWidgetControls();
    void addperYearWidgetControls();

    void getOncedWidgetData();
    void getEveryDayWidgetData();
    void getWeeklyWidgetData();
    void getPerMonthWidgetData();
    void getPerYearWidgetData();
    void getIntervalWidgetData();
public slots:
    void clickedDetermineButton();
    void clickedCancelButton();
    void onRadioButton();
};

#endif // ADDALARMCLOCKWIDGET_H
