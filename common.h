#ifndef COMMON
#define COMMON

#include <QString>

#define SYSTEM_ICON ":/Icon/systemIcon.png"
#define REMOVE_BUTTON_ICON ":/Icon/删除.png"
#define ADD_BUTTON_ICON ":/Icon/添加.png"
#define SYSTEM_NAME "闹钟"

#define MUSIC_FILE_PATH ":/music/music/风筝误 - 刘珂矣.mp3"

/*闹钟频率值定义*/
#define FREQU_ONCE 0        //一次
#define FREQU_EVERYDAY 1    //每天
#define FREQU_WEEKLY 2      //每周
#define FREQU_PERMONTH 3    //每月
#define FREQU_PERYEAR 4     //每年
#define FREQU_INTERVAL 5    //间隔

struct EventStruct {
    int frequency;  //频率
    QString date;
    QString time;     //闹钟时间
    QString string;  //闹钟事件
    QString Surplus;//剩余时间
    int status;//状态
};
#endif // COMMON

