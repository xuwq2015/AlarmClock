#ifndef QUITPROMPTWINDOW_H
#define QUITPROMPTWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>

#include "common.h"

#define QUITPROMPTWINDOW_DEBUG 0

int showQuitPromptWindow(QWidget*);

class QuitPromptWindow : public QDialog
{
    Q_OBJECT
public:
    explicit QuitPromptWindow(QWidget *parent = 0);
private:
    QVBoxLayout *mainLayout;
    QVBoxLayout *radioButtonLayou;
    QHBoxLayout *pushButtonLayou;

    QRadioButton *miniButton;
    QRadioButton *quitButton;
    QButtonGroup *buttonGroup;
    QPushButton *cancelButton;
    QPushButton *determineButton;
signals:

public slots:
    void determineButtonClicked();
    void cancelButtonClicked();
};

#endif // QUITPROMPTWINDOW_H
