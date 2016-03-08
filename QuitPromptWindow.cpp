#include "QuitPromptWindow.h"

QuitPromptWindow::QuitPromptWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(SYSTEM_NAME);
#if QUITPROMPTWINDOW_DEBUG
    this->setFixedWidth(243);
    this->setFixedHeight(85);
#else
    this->setFixedSize(243, 85);
#endif
    mainLayout = new QVBoxLayout;
    this->setLayout(mainLayout);
    mainLayout->setContentsMargins(0, 0, 0, 8);

    radioButtonLayou = new QVBoxLayout;
    radioButtonLayou->setSpacing(1);
    radioButtonLayou->setContentsMargins(60, 8, 0, 0);

    miniButton = new QRadioButton("最小化到系统托盘", this);
    miniButton->setChecked(true);
    quitButton = new QRadioButton("退出程序", this);
    buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(miniButton, 0);
    buttonGroup->addButton(quitButton, 1);
    radioButtonLayou->addWidget(miniButton, 0, Qt::AlignVCenter);
    radioButtonLayou->addWidget(quitButton, 0, Qt::AlignVCenter);

    pushButtonLayou = new QHBoxLayout;
    pushButtonLayou->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    pushButtonLayou->setSpacing(10);
    determineButton = new QPushButton("确定");
    cancelButton = new QPushButton("取消");

    pushButtonLayou->addWidget(determineButton);
    pushButtonLayou->addWidget(cancelButton);

    mainLayout->addLayout(radioButtonLayou);
    mainLayout->addLayout(pushButtonLayou);

    connect(determineButton, SIGNAL(clicked()), this, SLOT(determineButtonClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));
}

void QuitPromptWindow::determineButtonClicked()
{
    switch(buttonGroup->checkedId())
    {
    case 0:
        done(1);
        break;
    case 1:
        done(0);
        break;
    }
#if QUITPROMPTWINDOW_DEBUG
    qDebug()<<"QuitPromptWindow::";
    qDebug()<<"窗口宽度:"<<this->width();
    qDebug()<<"窗口高度:"<<this->height();
#endif
}

void QuitPromptWindow::cancelButtonClicked()
{
    done(-1);
}

int showQuitPromptWindow(QWidget *parent) {
    QuitPromptWindow quitPromptWindow(parent);
    return quitPromptWindow.exec();
}
