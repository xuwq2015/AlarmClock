#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(QString contentInfo, QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(SYSTEM_NAME);
    this->setWindowIcon(QIcon(SYSTEM_ICON));

    contentLabel = new QLabel(contentInfo);
    fulfilButton = new QPushButton("完成");//完成按钮
    cancelButton = new QPushButton("延时");//取消
    mediaPlayer = new QMediaPlayer(this);

    mainLayout = new QHBoxLayout;
    contentLayout = new QVBoxLayout;
    buttonLayout = new QVBoxLayout;

    this->setLayout(mainLayout);
    contentLayout->addWidget(contentLabel);
    buttonLayout->addWidget(fulfilButton);
    buttonLayout->addWidget(cancelButton);
    mainLayout->addLayout(contentLayout);
    mainLayout->addLayout(buttonLayout);

    const QString filePath = MUSIC_FILE_PATH;
    if (!filePath.isEmpty()) {
        playFile(filePath);
    }

    connect(mediaPlayer, &QMediaPlayer::stateChanged, this, &MusicPlayer::updateState);
    connect(fulfilButton, &QPushButton::clicked, this, &MusicPlayer::clickedFulfilButton);
    connect(cancelButton, &QPushButton::clicked, this, &MusicPlayer::clickedCancelButton);
}

void MusicPlayer::playFile(const QString &filePath)
{
    mediaPlayer.setMedia(QUrl::fromLocalFile(filePath));
    mediaPlayer.play();
}

void MusicPlayer::updateState()
{
    mediaPlayer.play();
}

void MusicPlayer::clickedFulfilButton()
{
    done(0);
}
void MusicPlayer::clickedCancelButton()
{
    done(1);
}
