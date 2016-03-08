#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    /*设置窗口属性*/
    this->setMinimumSize(728,445);
    this->setWindowTitle(SYSTEM_NAME);
    this->setWindowIcon(QIcon(SYSTEM_ICON));
    this->addSystemTray();

    createMenuBarAction();
    createMainWindowMenus();
    createMainWindowToolBars();


    /*主窗口布局*/
    centerWindow = new QWidget;
    this->setCentralWidget(centerWindow);

    mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(3, 0, 3, 0);
    tableView = new MyTableView(this);

    mainLayout->addWidget(tableView);
    centerWindow->setLayout(mainLayout);

    statusBar()->showMessage(tr(SYSTEM_NAME));
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenuBarAction()
{
    // QAction: 一建立, 二设置属性, 如图标, 快捷键, 事件处理.
    addAction = new QAction(tr("&新建闹钟"), this);
    addAction->setShortcut(tr("Ctrl+N"));
    addAction->setStatusTip(QString("新建闹钟"));
    addAction->setIcon(QIcon(ADD_BUTTON_ICON));
    connect(addAction, SIGNAL(triggered()), this, SLOT(showAddAlarmClockWidget()));

    removeAction = new QAction(tr("&删除闹钟"), this);
    removeAction->setShortcut(tr("Ctrl+R"));
    removeAction->setStatusTip(QString("删除闹钟"));
    removeAction->setIcon(QIcon(REMOVE_BUTTON_ICON));
    connect(removeAction, SIGNAL(triggered()), this, SLOT(clickedDelTimingButton()));
}

void MainWindow::createMainWindowToolBars()
{
    addAlarmClockButton = new QToolButton(this);
    addAlarmClockButton->setText("添加闹钟");
    addAlarmClockButton->setIcon(QIcon(ADD_BUTTON_ICON));

    reAlarmClockButton = new QToolButton(this);
    reAlarmClockButton->setText("删除闹钟");
    reAlarmClockButton->setIcon(QIcon(REMOVE_BUTTON_ICON));

    toolBar = addToolBar(tr("&File"));
    toolBar->addWidget(addAlarmClockButton);
    toolBar->addWidget(reAlarmClockButton);

    connect(addAlarmClockButton, SIGNAL(clicked()), this, SLOT(showAddAlarmClockWidget()));
    connect(reAlarmClockButton, SIGNAL(clicked()), this, SLOT(clickedDelTimingButton()));
}

void MainWindow::createMainWindowMenus()
{
    fileMenu = menuBar()->addMenu(tr("&文件"));
    fileMenu->addAction(addAction);
    fileMenu->addAction(removeAction);
    fileMenu->addAction(quitAction);

    setMenu = menuBar()->addMenu(tr("&设置"));
}

/*添加系统托盘*/
void MainWindow::addSystemTray()
{
    this->createTrayIcon();
    systemTrayIcon = new QSystemTrayIcon(this);
    systemTrayIcon->setContextMenu(systemTrayMenu);
    systemTrayIcon->setToolTip(SYSTEM_NAME);
    systemTrayIcon->setIcon(QIcon(SYSTEM_ICON));
    systemTrayIcon->show();
    connect(systemTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(systemTrayIconActivated(QSystemTrayIcon::ActivationReason)));
}

/*添加系统托盘图标右键菜单*/
void MainWindow::createTrayIcon()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

    restoreAction = new QAction(tr("打开主界面"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("退出程序"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    systemTrayMenu = new QMenu(this);
    systemTrayMenu->addAction(minimizeAction);
    systemTrayMenu->addAction(maximizeAction);
    systemTrayMenu->addAction(restoreAction);
    systemTrayMenu->addSeparator();
    systemTrayMenu->addAction(quitAction);
}

void MainWindow::changeEvent(QEvent *event)
{
//    if(event->type() == QEvent::WindowStateChange) {
//        if(this->windowState()==Qt::WindowMinimized) {
//            event->ignore();
//            hide();
//        }
//    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
#if MAINWINDOW_DEBUG
    qDebug()<<"MainWindow::";
    qDebug()<<"窗口宽度:"<<this->width();
    qDebug()<<"窗口高度:"<<this->height();
#endif
    QuitPromptWindow quitPromptWindow(this);
    switch (quitPromptWindow.exec()) {
    case 1:
        hide();
        event->ignore();
        break;
    case 0:
        qApp->quit();
        break;
    default:
        event->ignore();
        break;
    }
}

void MainWindow::systemTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::Trigger)
        showNormal();   //系统托盘中的图标被单击
    else if(reason == QSystemTrayIcon::DoubleClick)
        showNormal();   //系统托盘中的图标被双击
}

void MainWindow::showAddAlarmClockWidget()
{
    EventStruct sAACWEventList;
    AddAlarmClockWidget addAlarmClockWidget(&sAACWEventList, this);
    switch (addAlarmClockWidget.exec()) {
    case 1:
        tableView->addRowData(&sAACWEventList);
        break;
    default:
        break;
    }
#if MAINWINDOW_DEBUG
    QDateTime time1 = QDateTime::currentDateTime();
    QDateTime time2 = QDateTime::fromString(sAACWEventList.alarmClockTime, "yyyy-MM-dd hh:mm:ss");
    qDebug()<<"time1:"<<time1.toString("yyyy-MM-dd hh:mm:ss");
    qDebug()<<"time2:"<<time2.toString("yyyy-MM-dd hh:mm:ss");
    qDebug()<<"secsTo:"<<time1.secsTo(time2);
#endif
}

void MainWindow::clickedDelTimingButton ()
{
    tableView->reRowData();
}
