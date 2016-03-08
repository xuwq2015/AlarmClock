#include "GlobalFunctions.h"

int eventIsEmpty(EventStruct *eventList)
{
    if(eventList->frequency < 0)
        return 0;
    else if (eventList->date.isNull())
        return 1;
    if(eventList->date.isEmpty())
        return 1;
    else if (eventList->time.isEmpty())
        return 2;
    else if (eventList->time.isNull())
        return 2;
    if(eventList->string.isEmpty())
        return 3;
    else if (eventList->string.isNull())
        return 3;
    return 4;
}

void warningInfo(QString warningInfoString)
{
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon(SYSTEM_ICON));
    msgBox.setWindowTitle(SYSTEM_NAME);
    msgBox.setText(warningInfoString);
    msgBox.setFixedSize(300, 150);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.exec();
}
