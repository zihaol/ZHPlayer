#pragma once
#include <QUrl>
#include <vector>
#include "MusicConfig.h"


class CMusicManager
{
public:
	CMusicManager();
	~CMusicManager();
	QUrl* GetCurrentMusic();
	QUrl* GetNextMusic();
	QUrl* GetLastMusic();
	ChangeType GetChangType();
	void GetNextType();
	int GetVoice();
	void SetVoice(int nVoice);
	int SetMusicPath(QString strPath);
	void LoadMusic();
	void SetCurrentMusicByName(QString strName);
public:
	std::vector<QUrl*>			m_vecMusic;

private:
	int						m_nCurMusicIndex;
	int						m_nLastMusicIndex;
	//ChangeType				m_enChaneType;
	CMusicConfig*			m_pMusicConfig;
};


