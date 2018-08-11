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
	~ZHPlayerBaseUI();
	void InitConfig();
	void UpdatePlayStatus();
public slots:
	void OnTouchVolume();
	void OnTouchPlay();
	void OnTouchGetMusicPath();
	void OnTouchNext();
	void OnTouchLast();
	void OnTouchPlayType();
	void OnSliderPositionMoved();
	void OnSliderVoiceMoved();
	//QMediaPlayer–≈∫≈≤€
	void OnUpdatePosition(qint64 nPosition);
	void OnUpdateDuration(qint64 nDuration);
private:
	void initConnect();

private:
	Ui::ZHPlayerBaseUIClass			ui;
	CMusicManager*					m_pMusicManager;
	QMediaPlayer*					m_pMusicPlayer;
};
