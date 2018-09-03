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
	//QMediaPlayer信号槽
	void OnUpdatePosition(qint64 nPosition);
	void OnUpdateDuration(qint64 nDuration);
	//列表点击时间
	void OnItemDoubleClicked(QListWidgetItem *item);
	//搜索按钮
	void OnTouchSearch();
	//搜索结果
	void OnSearchResult(std::vector<tagMusicInfo> vMusicInfo);
	//搜索列表双击
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
