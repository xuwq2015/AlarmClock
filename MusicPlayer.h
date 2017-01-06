#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QUrl>
#include <QIcon>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QMediaPlayer>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "common.h"

#define MUSICPLAYER_DEBUG 1

class MusicPlayer : public QDialog
{
    Q_OBJECT
public:
    MusicPlayer(QString contentInfo, QWidget *parent = 0);
    void clickedCancelButton();
private:
    QLabel *contentLabel;
    QPushButton *fulfilButton;//完成按钮
    QPushButton *cancelButton;//取消
    QMediaPlayer *mediaPlayer;

    QHBoxLayout *mainLayout;
    QVBoxLayout *contentLayout;
    QVBoxLayout *buttonLayout;

    void playFile(const QString& filePath);
signals:

public slots:   
    void updateState();
    void clickedFulfilButton();
};

#endif // MUSICPLAYER_H
