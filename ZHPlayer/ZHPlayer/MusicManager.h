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
	int SetMusicPath(QString strPath);
	void LoadMusic();

private:
	int						m_nCurMusicIndex;
	int						m_nLastMusicIndex;
	ChangeType				m_enChaneType;
	std::vector<QUrl*>			m_vecMusic;
	CMusicConfig*			m_pMusicConfig;
};


