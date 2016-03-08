#include "AddAlarmClockWidget.h"

AddAlarmClockWidget::AddAlarmClockWidget(EventStruct *eventList, QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(SYSTEM_NAME);
    this->eventList = eventList;
    this->setFixedSize(512, 379);

    /*定义界面所需布局*/
    mainLayout = new QVBoxLayout;
    firstHLayout = new QHBoxLayout;    
    secondHLayout = new QHBoxLayout;
    thirdHLayout = new QHBoxLayout;
    fourthHLayout = new QHBoxLayout;
    fifthHLayout = new QHBoxLayout;
    sixthHLayout = new QHBoxLayout;

    firstHLayout->setAlignment(Qt::AlignRight | Qt::AlignBottom);    
    secondHLayout->setAlignment(Qt::AlignLeft);
    thirdHLayout->setAlignment(Qt::AlignLeft);
    fourthHLayout->setAlignment(Qt::AlignLeft);
    fifthHLayout->setAlignment(Qt::AlignLeft);
    sixthHLayout->setAlignment(Qt::AlignLeft);

    createStackedWidget();

    /*定义界面所需控件*/
    numberLabel = new QLabel("编号:", this);
    numberLineEdit = new QLineEdit(this);
    secondHLayout->addWidget(numberLabel);
    secondHLayout->addWidget(numberLineEdit);

    alarmClockTimeDataLabel = new QLabel("闹钟日期:", this);
    thirdHLayout->addWidget(alarmClockTimeDataLabel);
    thirdHLayout->addWidget(stackedWidget);

    alarmClockTimeLabel = new QLabel("提醒时间:", this);
    alarmClockTimeEdit = new QTimeEdit(this);
    alarmClockTimeEdit->setTime(QTime::currentTime());
    fourthHLayout->addWidget(alarmClockTimeLabel);
    fourthHLayout->addWidget(alarmClockTimeEdit);

    alarmClockLabel = new QLabel("闹钟事件:", this);
    alarmClockLineEdit = new QLineEdit(this);
    fifthHLayout->addWidget(alarmClockLabel);
    fifthHLayout->addWidget(alarmClockLineEdit);

    remarkLabel = new QLabel("备注:", this);
    remarkLineEdit = new QLineEdit(this);
    sixthHLayout->addWidget(remarkLabel);
    sixthHLayout->addWidget(remarkLineEdit);

    determineButton = new QPushButton("确定", this);
    cancelButton = new QPushButton("取消", this);
    firstHLayout->addWidget(determineButton);
    firstHLayout->addWidget(cancelButton);

    createFrequencyWidget();

    /*为界面中的控件布局*/
    mainLayout->addLayout(frequencyHLayout, 0);
    mainLayout->addLayout(secondHLayout, 0);
    mainLayout->addLayout(thirdHLayout, 0);
    mainLayout->addLayout(fourthHLayout, 0);
    mainLayout->addLayout(fifthHLayout, 0);
    mainLayout->addLayout(sixthHLayout, 0);
    mainLayout->addLayout(firstHLayout, 0);

    this->setLayout(mainLayout);

    connect(determineButton, SIGNAL(clicked()), this, SLOT(clickedDetermineButton()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(clickedCancelButton()));
}

void AddAlarmClockWidget::createFrequencyWidget()
{
    frequencyHLayout = new QHBoxLayout;
    frequencyHLayout->setAlignment(Qt::AlignLeft);

    frequencyLabel = new QLabel("循环方式:", this);
    onceButton = new QRadioButton("一次", this);
    onceButton->setChecked(true);
    everyDayButton = new QRadioButton("每天", this);
    weeklyButton = new QRadioButton("每周", this);
    perMonthButton = new QRadioButton("每月", this);
    perYearButton = new QRadioButton("每年", this);
    intervalButton = new QRadioButton("间隔", this);
    frequencyButtonGroup = new QButtonGroup(this);
    frequencyButtonGroup->addButton(onceButton, FREQU_ONCE);
    frequencyButtonGroup->addButton(everyDayButton, FREQU_EVERYDAY);
    frequencyButtonGroup->addButton(weeklyButton, FREQU_WEEKLY);
    frequencyButtonGroup->addButton(perMonthButton, FREQU_PERMONTH);
    frequencyButtonGroup->addButton(perYearButton, FREQU_PERYEAR);
    frequencyButtonGroup->addButton(intervalButton, FREQU_INTERVAL);
    frequencyHLayout->addWidget(frequencyLabel);
    frequencyHLayout->addWidget(onceButton);
    frequencyHLayout->addWidget(everyDayButton);
    frequencyHLayout->addWidget(weeklyButton);
    frequencyHLayout->addWidget(perMonthButton);
    frequencyHLayout->addWidget(perYearButton);
    frequencyHLayout->addWidget(intervalButton);
    connect(onceButton, SIGNAL(clicked()), this, SLOT(onRadioButton()));
    connect(everyDayButton, SIGNAL(clicked()), this, SLOT(onRadioButton()));
    connect(weeklyButton, SIGNAL(clicked()), this, SLOT(onRadioButton()));
    connect(perMonthButton, SIGNAL(clicked()), this, SLOT(onRadioButton()));
    connect(perYearButton, SIGNAL(clicked()), this, SLOT(onRadioButton()));
    connect(intervalButton, SIGNAL(clicked()), this, SLOT(onRadioButton()));
}

void AddAlarmClockWidget::createStackedWidget()
{
    stackedWidget = new QStackedWidget;

    onceWidget = new QWidget(this);
    everyDayWidget = new QWidget(this);
    weeklyWidget = new QWidget(this);
    perMonthWidget = new QWidget(this);
    perYearWidget = new QWidget(this);
    intervalWidget = new QWidget(this);

    stackedWidget->addWidget(onceWidget);
    stackedWidget->addWidget(everyDayWidget);
    stackedWidget->addWidget(weeklyWidget);
    stackedWidget->addWidget(perMonthWidget);
    stackedWidget->addWidget(perYearWidget);
    stackedWidget->addWidget(intervalWidget);
    setStackedWidgetLayout();
    addOncedWidgetControls();
    addIntervalWidgetControls();
    addEveryDayWidgetControls();
    addWeeklyWidgetControls();
    addperMonthWidgetControls();
    addperYearWidgetControls();
}

void AddAlarmClockWidget::setStackedWidgetLayout()
{
    onceWidgetLayout = new QHBoxLayout;
    everyDayWidgetLayout = new QHBoxLayout;
    weeklyLayout = new QHBoxLayout;
    perMonthWidgetLayout = new QHBoxLayout;
    perYearWidgetLayout = new QHBoxLayout;
    intervalWidgetLayout = new QHBoxLayout;

    onceWidgetLayout->setAlignment(Qt::AlignLeft);
    onceWidgetLayout->setSpacing(10);
    onceWidgetLayout->setContentsMargins(0, 0, 0, 0);

    everyDayWidgetLayout->setAlignment(Qt::AlignLeft);
    weeklyLayout->setAlignment(Qt::AlignLeft);
    perMonthWidgetLayout->setAlignment(Qt::AlignLeft);
    perYearWidgetLayout->setAlignment(Qt::AlignLeft);
    intervalWidgetLayout->setAlignment(Qt::AlignLeft);
    intervalWidgetLayout->setSpacing(10);


    onceWidget->setLayout(onceWidgetLayout);
    everyDayWidget->setLayout(everyDayWidgetLayout);
    weeklyWidget->setLayout(weeklyLayout);
    perMonthWidget->setLayout(perMonthWidgetLayout);
    perYearWidget->setLayout(perYearWidgetLayout);
    intervalWidget->setLayout(intervalWidgetLayout);
}



void AddAlarmClockWidget::addOncedWidgetControls()
{
    yearAbstractSpinBox = new QSpinBox(this);
    monthAbstractSpinBox = new QSpinBox(this);
    dayAbstractSpinBox = new QSpinBox(this);
    yearAbstractSpinBox->setFixedWidth(100);
    yearAbstractSpinBox->setRange(2016, 2116);
    monthAbstractSpinBox->setFixedWidth(100);
    monthAbstractSpinBox->setRange(1, 12);
    dayAbstractSpinBox->setFixedWidth(100);
    dayAbstractSpinBox->setRange(1, 31);

    yearLabel = new QLabel("年", this);
    monthLabel = new QLabel("月", this);
    dayLabel = new QLabel("日", this);

    onceWidgetLayout->addWidget(yearAbstractSpinBox);
    onceWidgetLayout->addWidget(yearLabel);
    onceWidgetLayout->addWidget(monthAbstractSpinBox);
    onceWidgetLayout->addWidget(monthLabel);
    onceWidgetLayout->addWidget(dayAbstractSpinBox);
    onceWidgetLayout->addWidget(dayLabel);
}

void AddAlarmClockWidget::addEveryDayWidgetControls()
{
    everyDayLabel = new QLabel("每天", this);
    everyDayWidgetLayout->addWidget(everyDayLabel);
}

void AddAlarmClockWidget::addWeeklyWidgetControls()
{
    sundayCheckBox = new QCheckBox("周日", this);
    mondayCheckBox = new QCheckBox("周一", this);
    tuesdayCheckBox = new QCheckBox("周二", this);
    wednesdayCheckBox = new QCheckBox("周三", this);
    thursdayCheckBox = new QCheckBox("周四", this);
    fridayCheckBox = new QCheckBox("周五", this);
    saturdayCheckBox = new QCheckBox("周六", this);

    weeklyLayout->addWidget(sundayCheckBox);
    weeklyLayout->addWidget(mondayCheckBox);
    weeklyLayout->addWidget(tuesdayCheckBox);
    weeklyLayout->addWidget(wednesdayCheckBox);
    weeklyLayout->addWidget(thursdayCheckBox);
    weeklyLayout->addWidget(fridayCheckBox);
    weeklyLayout->addWidget(saturdayCheckBox);
}

void AddAlarmClockWidget::addperMonthWidgetControls()
{
    perMonthSpinBox = new QSpinBox(this);
    perMonthSpinBox->setFixedWidth(100);
    perMonthSpinBox->setRange(1, 31);
    perMonthLabel = new QLabel("日");
    perMonthWidgetLayout->addWidget(perMonthSpinBox);
    perMonthWidgetLayout->addWidget(perMonthLabel);
}

void AddAlarmClockWidget::addperYearWidgetControls()
{
    perYearSpinBox = new QSpinBox(this);
    perYearSpinBox->setFixedWidth(100);
    perYearSpinBox->setRange(1, 12);
    perYearLabel = new QLabel("月");
    perYearWidgetLayout->addWidget(perYearSpinBox);
    perYearWidgetLayout->addWidget(perYearLabel);
}

void AddAlarmClockWidget::addIntervalWidgetControls()
{
    daysAbstractSpinBox = new QSpinBox(this);
    hourAbstractSpinBox = new QSpinBox(this);
    minuteAbstractSpinBox = new QSpinBox(this);
    secondAbstractSpinBox = new QSpinBox(this);
    daysAbstractSpinBox->setFixedWidth(60);
    hourAbstractSpinBox->setFixedWidth(60);
    minuteAbstractSpinBox->setFixedWidth(60);
    secondAbstractSpinBox->setFixedWidth(60);

    daysLabel = new QLabel("天", this);
    hourLabel = new QLabel("小时", this);
    minuteLabel = new QLabel("分钟", this);
    secondLabel = new QLabel("秒 ", this);
    remindedOnceLabel = new QLabel("提醒一次", this);

    intervalWidgetLayout->addWidget(daysAbstractSpinBox);
    intervalWidgetLayout->addWidget(daysLabel);
    intervalWidgetLayout->addWidget(hourAbstractSpinBox);
    intervalWidgetLayout->addWidget(hourLabel);
    intervalWidgetLayout->addWidget(minuteAbstractSpinBox);
    intervalWidgetLayout->addWidget(minuteLabel);
    intervalWidgetLayout->addWidget(secondAbstractSpinBox);
    intervalWidgetLayout->addWidget(secondLabel);
    intervalWidgetLayout->addWidget(remindedOnceLabel);
}



void AddAlarmClockWidget::getOncedWidgetData()
{
    eventList->frequency = FREQU_ONCE;
    eventList->date = yearAbstractSpinBox->text();
    eventList->date.append('-');
    eventList->date.append(monthAbstractSpinBox->text());
    eventList->date.append('-');
    eventList->date.append(dayAbstractSpinBox->text());

    eventList->time = alarmClockTimeEdit->time().toString("hh:mm:ss");
    eventList->string = alarmClockLineEdit->text();
    eventList->Surplus = "0小时";
    eventList->status = 1;

    switch (eventIsEmpty(eventList)) {
    case 0:
        warningInfo("频率不能为空，请重新添加闹钟信息");
        break;
    case 1:
        warningInfo("日期不能为空，请重新添加闹钟信息");
        break;
    case 2:
        warningInfo("时间不能为空，请重新添加闹钟信息");
        break;
    case 3:
        warningInfo("闹钟事件不能为空，请重新添加闹钟信息");
        break;
    default:
        done(1);
        break;
    }
}

void AddAlarmClockWidget::getEveryDayWidgetData()
{
    eventList->frequency = FREQU_EVERYDAY;
    eventList->date.append("每天");

    eventList->time = alarmClockTimeEdit->time().toString("hh:mm:ss");
    eventList->string = alarmClockLineEdit->text();
    eventList->Surplus = "0小时";
    eventList->status = 1;

    switch (eventIsEmpty(eventList)) {
    case 0:
        warningInfo("频率不能为空，请重新添加闹钟信息");
        break;
    case 1:
        warningInfo("日期不能为空，请重新添加闹钟信息");
        break;
    case 2:
        warningInfo("时间不能为空，请重新添加闹钟信息");
        break;
    case 3:
        warningInfo("闹钟事件不能为空，请重新添加闹钟信息");
        break;
    default:
        done(1);
        break;
    }
}

void AddAlarmClockWidget::getWeeklyWidgetData()
{
    eventList->frequency = FREQU_WEEKLY;
    //eventList->date = weeklySelect;
    if(sundayCheckBox->isChecked())
        eventList->date.append("周日");
    if(mondayCheckBox->isChecked())
        eventList->date.append("周一");
    if(tuesdayCheckBox->isChecked())
        eventList->date.append("周二");
    if(wednesdayCheckBox->isChecked())
        eventList->date.append("周三");
    if(thursdayCheckBox->isChecked())
        eventList->date.append("周四");
    if(fridayCheckBox->isChecked())
        eventList->date.append("周五");
    if(saturdayCheckBox->isChecked())
        eventList->date.append("周六");

    eventList->time = alarmClockTimeEdit->time().toString("hh:mm:ss");
    eventList->string = alarmClockLineEdit->text();
    eventList->Surplus = "0小时";
    eventList->status = 1;

    switch (eventIsEmpty(eventList)) {
    case 0:
        warningInfo("频率不能为空，请重新添加闹钟信息");
        break;
    case 1:
        warningInfo("日期不能为空，请重新添加闹钟信息");
        break;
    case 2:
        warningInfo("时间不能为空，请重新添加闹钟信息");
        break;
    case 3:
        warningInfo("闹钟事件不能为空，请重新添加闹钟信息");
        break;
    default:
        done(1);
        break;
    }
}

void AddAlarmClockWidget::getPerMonthWidgetData()
{
    eventList->frequency = FREQU_PERMONTH;
    eventList->date = perMonthSpinBox->text();
    eventList->date.append("日");

    eventList->time = alarmClockTimeEdit->time().toString("hh:mm:ss");
    eventList->string = alarmClockLineEdit->text();
    eventList->Surplus = "0小时";
    eventList->status = 1;

    switch (eventIsEmpty(eventList)) {
    case 0:
        warningInfo("频率不能为空，请重新添加闹钟信息");
        break;
    case 1:
        warningInfo("日期不能为空，请重新添加闹钟信息");
        break;
    case 2:
        warningInfo("时间不能为空，请重新添加闹钟信息");
        break;
    case 3:
        warningInfo("闹钟事件不能为空，请重新添加闹钟信息");
        break;
    default:
        done(1);
        break;
    }
}

void AddAlarmClockWidget::getPerYearWidgetData()
{
    eventList->frequency = FREQU_PERYEAR;
    eventList->date = perMonthSpinBox->text();
    eventList->date.append("年");

    eventList->time = alarmClockTimeEdit->time().toString("hh:mm:ss");
    eventList->string = alarmClockLineEdit->text();
    eventList->Surplus = "0小时";
    eventList->status = 1;

    switch (eventIsEmpty(eventList)) {
    case 0:
        warningInfo("频率不能为空，请重新添加闹钟信息");
        break;
    case 1:
        warningInfo("日期不能为空，请重新添加闹钟信息");
        break;
    case 2:
        warningInfo("时间不能为空，请重新添加闹钟信息");
        break;
    case 3:
        warningInfo("闹钟事件不能为空，请重新添加闹钟信息");
        break;
    default:
        done(1);
        break;
    }
}

void AddAlarmClockWidget::getIntervalWidgetData()
{
    eventList->frequency = FREQU_INTERVAL;
    eventList->date = perMonthSpinBox->text();
    eventList->date.append("年");

    eventList->time = alarmClockTimeEdit->time().toString("hh:mm:ss");
    eventList->string = alarmClockLineEdit->text();
    eventList->Surplus = "0小时";
    eventList->status = 1;

    switch (eventIsEmpty(eventList)) {
    case 0:
        warningInfo("频率不能为空，请重新添加闹钟信息");
        break;
    case 1:
        warningInfo("日期不能为空，请重新添加闹钟信息");
        break;
    case 2:
        warningInfo("时间不能为空，请重新添加闹钟信息");
        break;
    case 3:
        warningInfo("闹钟事件不能为空，请重新添加闹钟信息");
        break;
    default:
        done(1);
        break;
    }
}



void AddAlarmClockWidget::clickedDetermineButton()
{
    switch (frequencyButtonGroup->checkedId()) {
    case FREQU_ONCE://一次
        getOncedWidgetData();
        break;
    case FREQU_EVERYDAY:
        getEveryDayWidgetData();
        break;
    case FREQU_WEEKLY:
        getWeeklyWidgetData();
        break;
    case FREQU_PERMONTH:
        getPerMonthWidgetData();
        break;
    case FREQU_PERYEAR:
        getPerYearWidgetData();
        break;
    case FREQU_INTERVAL:
        getIntervalWidgetData();
        break;
    default:
        break;
    }
}

void AddAlarmClockWidget::clickedCancelButton()
{
#if ADDALARMCLOCKWIDGET_DEBUG
    qDebug()<<"AddAlarmClockWidget::";
    qDebug()<<"窗口宽度:"<<this->width();
    qDebug()<<"窗口高度:"<<this->height();
#endif
    done(0);
}

void AddAlarmClockWidget::onRadioButton()
{
    switch (frequencyButtonGroup->checkedId()) {
    case 0:
        stackedWidget->setCurrentWidget(onceWidget);
        break;
    case 1:
        stackedWidget->setCurrentWidget(everyDayWidget);
        break;
    case 2:
        stackedWidget->setCurrentWidget(weeklyWidget);
        break;
    case 3:
        stackedWidget->setCurrentWidget(perMonthWidget);
        break;
    case 4:
        stackedWidget->setCurrentWidget(perYearWidget);
        break;
    case 5:
        stackedWidget->setCurrentWidget(intervalWidget);
        break;
    default:
        break;
    }
}
