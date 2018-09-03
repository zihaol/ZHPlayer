#pragma once

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>
#include "ui_ZHPlayerBaseUI.h"
#include "MusicManager.h"
#include "SearchMusic.h"
#include "SongSrcGetter.h"

class ZHPlayerBaseUI : public QMainWindow
{
	Q_OBJECT

public:
	ZHPlayerBaseUI(QWidget *parent = Q_NULLPTR);
	~ZHPlayerBaseUI();
	void InitConfig();
	void UpdatePlayStatus();
	void UpdateMusicList();
	void UpdateSearchMusicInfo(std::vector<tagMusicInfo> vMusicInfo);
public slots:
	void OnTouchVolume();
	void OnTouchPlay();
	void OnTouchGetMusicPath();
	void OnTouchNext();
	void OnTouchLast();
	void OnTouchPlayType();
	void OnSliderPositionMoved();
	void OnSliderVoiceMoved();
	//QMediaPlayer�źŲ�
	void OnUpdatePosition(qint64 nPosition);
	void OnUpdateDuration(qint64 nDuration);
	//�б���ʱ��
	void OnItemDoubleClicked(QListWidgetItem *item);
	//������ť
	void OnTouchSearch();
	//�������
	void OnSearchResult(std::vector<tagMusicInfo> vMusicInfo);
	//�����б�˫��
	void OnSearchItemDoubleClicked(QListWidgetItem *item);
	void GetSongSrcFinish(SongInfo pSongInfo);

private:
	void initConnect();

private:
	Ui::ZHPlayerBaseUIClass			ui;
	CMusicManager*					m_pMusicManager;
	QMediaPlayer*					m_pMusicPlayer;
	SearchMusic*					m_pMusicSearch;
	SongSrcGetter*					m_pSongSrcGetter;
};
