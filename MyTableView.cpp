#include "MyTableView.h"

MyTableView::MyTableView(QWidget *parent):QTableView(parent){
    timerManage = new TimerManage(this);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置tableview只读属性
    this->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
    this->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单个目标
    this->verticalHeader()->setVisible(false);   //隐藏列表头
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//行自适应宽度
    this->resizeRowsToContents(); //根据内容自动调整给定列宽
    //qTableView->verticalHeader()->setVisible(true); //显示列表头
    //qTableView->horizontalHeader()->setVisible(true); //显示行表头

    tableViewModel = new QStandardItemModel();
    tableViewModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("频率")));
    tableViewModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("日期")));
    tableViewModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("时间")));
    tableViewModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("事件")));
    tableViewModel->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("剩余")));
    tableViewModel->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("状态")));

    this->setColumnWidth(0, 35);
    this->setColumnWidth(1, 121);
    tableViewModel->sort(4, Qt::AscendingOrder); //设置排序方式，按提醒时间升序显示
    //利用setModel()方法将数据模型与QTableView绑定
    this->setModel(tableViewModel);
    connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onDoubleClicked(QModelIndex)));
}

/*添加一行信息*/
int MyTableView::addRowData(EventStruct *eventList) {
    QList<QStandardItem*> standardItem;
    switch (eventList->frequency) {
    case FREQU_ONCE:
        standardItem.append(new QStandardItem("一次"));
        break;
    case FREQU_EVERYDAY:
        standardItem.append(new QStandardItem("每天"));
        break;
    case FREQU_WEEKLY:
        standardItem.append(new QStandardItem("每周"));
        break;
    case FREQU_PERMONTH:
        standardItem.append(new QStandardItem("每月"));
        break;
    case FREQU_PERYEAR:
        standardItem.append(new QStandardItem("每年"));
        break;
    case FREQU_INTERVAL:
        standardItem.append(new QStandardItem("间隔"));
        break;
    default:
        break;
    }
    standardItem.append(new QStandardItem(eventList->date));
    standardItem.append(new QStandardItem(eventList->time));
    standardItem.append(new QStandardItem(eventList->string));
    standardItem.append(new QStandardItem("0小时"));
    standardItem.append(new QStandardItem("开启"));
    tableViewModel->appendRow(standardItem);
    timerManage->startTiming(eventList);
    return 0;
}

/*双击信号槽*/
void MyTableView::onDoubleClicked(QModelIndex modelIndex) {
    QStandardItem *qStandardItem = tableViewModel->itemFromIndex(modelIndex);
    //QMessageBox::about(this, SYSTEM_NAME, qStandardItem->text());
    warningInfo(qStandardItem->text());
#if MYTABLEVIEW_DEBUG
    qDebug()<<"MyTableView:";
    qDebug()<<"编号长度:"<<this->columnWidth(0);
    qDebug()<<"闹钟时间长度:"<<this->columnWidth(0);
    qDebug()<<"闹钟事件长度:"<<this->columnWidth(1);
    qDebug()<<"备注长度:"<<this->columnWidth(2);
#endif
}

/*获取当前选中行中每列的信息*/
void MyTableView::getCurrentRowData(EventStruct *eventList) {
    int currentRowNum = this->currentIndex().row();
    eventList->frequency = tableViewModel->data(tableViewModel->index(currentRowNum, 0)).toInt();
    eventList->date = tableViewModel->data(tableViewModel->index(currentRowNum, 0)).toString();
    eventList->time = tableViewModel->data(tableViewModel->index(currentRowNum, 1)).toString();
    eventList->string = tableViewModel->data(tableViewModel->index(currentRowNum, 2)).toString();
    eventList->Surplus = tableViewModel->data(tableViewModel->index(currentRowNum, 2)).toString();
    eventList->status = tableViewModel->data(tableViewModel->index(currentRowNum, 2)).toInt();
}

void MyTableView::reRowData()
{
    int currentRowNum = -1;
    currentRowNum = this->currentIndex().row();
    if (currentRowNum == -1) {
        QMessageBox::about(this, SYSTEM_NAME, "请选择要删除的数据");
    } else {
        if(QMessageBox::Yes == QMessageBox::warning(this, tr(SYSTEM_NAME),
                                       tr("确定删除此条定时数据"),
                                       QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)) {
            tableViewModel->removeRow(currentRowNum);
        }
    }
}
