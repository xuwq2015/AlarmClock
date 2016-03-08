#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMenu>
#include <QIcon>
#include <QAction>
#include <QWidget>
#include <QToolBar>
#include <QMenuBar>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QToolButton>
#include <QCloseEvent>
#include <QTabWidget>
#include <QTableView>
#include <QStatusBar>
#include <QApplication>
#include <QSpacerItem>
#include <QCalendarWidget>
#include <QSystemTrayIcon>
#include <QDebug>

#include "common.h"
#include "MyTableView.h"
#include "QuitPromptWindow.h"
#include "AddAlarmClockWidget.h"

#define MAINWINDOW_DEBUG 0

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QWidget *centerWindow;

    QVBoxLayout *mainLayout;

    MyTableView *tableView;
    QTabWidget *tabWidget;

    QSystemTrayIcon *systemTrayIcon;
    QMenu *systemTrayMenu;
    QAction *systemTrayAction;
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;

    QToolBar *toolBar;
    QMenu *fileMenu;
    QMenu *setMenu;
    QAction *addAction;
    QAction *removeAction;
    QAction *addAlarmClockAction;
    QToolButton *addAlarmClockButton;
    QToolButton *reAlarmClockButton;

    void addSystemTray();
    void createTrayIcon();
    void createMainWindowToolBars();
    void createMenuBarAction();
    void createMainWindowMenus();
protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
    void changeEvent(QEvent *event) Q_DECL_OVERRIDE;
public slots:
    void showAddAlarmClockWidget();
    void clickedDelTimingButton();
    void systemTrayIconActivated(QSystemTrayIcon::ActivationReason);
};

#endif // MAINWINDOW_H
