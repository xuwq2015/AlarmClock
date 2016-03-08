#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QTableView>
#include <QMessageBox>
#include <QWidget>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QDebug>
#include "common.h"
#include "TimerManage.h"

#define MYTABLEVIEW_DEBUG 1

class MyTableView : public QTableView
{
    Q_OBJECT
public:
    MyTableView(QWidget *parent = 0);
    int addRowData(EventStruct *eventList);
    void reRowData();
    void getCurrentRowData(EventStruct*);
private:
    QStandardItemModel *tableViewModel;
    TimerManage *timerManage;
public slots:
    void onDoubleClicked(QModelIndex);
};

#endif // MYTABLEVIEW_H
