#pragma once
#include <QUrl>
#include <vector>

enum ChangeType
{
	enChange_Type_Normal = 0,
	enChange_Type_Rand = 1,
	enChange_Type_OnleOne = 2,
};

class CMusicManager
{
public:
	CMusicManager();
	~CMusicManager();
	QUrl* GetCurrentMusic();
	QUrl* GetNextMusic();
	ChangeType GetChangType();

private:
	int						m_nCurMusicIndex;
	int						m_nLastMusicIndex;
	ChangeType				m_enChaneType;
	//list<QUrl*>				m_listMusic
	std::vector<QUrl*>			m_listMusic;
};


