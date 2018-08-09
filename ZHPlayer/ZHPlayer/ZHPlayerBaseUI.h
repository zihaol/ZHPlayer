#pragma once

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>
#include "ui_ZHPlayerBaseUI.h"
#include "MusicManager.h"

class ZHPlayerBaseUI : public QMainWindow
{
	Q_OBJECT

public:
	ZHPlayerBaseUI(QWidget *parent = Q_NULLPTR);
public slots:
	void OnTouchPlay();
	void OnTouchGetMusicPath();
	void OnTouchNext();
	void OnTouchLast();
	void OnSliderMoved();
	//QMediaPlayer�źŲ�
	void OnUpdatePosition(qint64 nPosition);
	void OnUpdateDuration(qint64 nDuration);
private:
	void initConnect();

private:
	Ui::ZHPlayerBaseUIClass			ui;
	CMusicManager*					m_pMusicManager;
	QMediaPlayer*					m_pMusicPlayer;
};
