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

private:
	int						m_nCurMusicIndex;
	int						m_nLastMusicIndex;
	//ChangeType				m_enChaneType;
	std::vector<QUrl*>			m_vecMusic;
	CMusicConfig*			m_pMusicConfig;
};


