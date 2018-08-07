#include "MusicManager.h"

//using namespace std;

CMusicManager::CMusicManager()
	: m_nCurMusicIndex(0)
	, m_nLastMusicIndex(0)
	, m_enChaneType(ChangeType::enChange_Type_Normal)
{

}

CMusicManager::~CMusicManager()
{

}

int CMusicManager::SetMusicPath(QString strPath)
{
	int nRet = 0;
	do 
	{
		if (strPath.isEmpty())
		{
			nRet = 1;
			break;
		}
		QUrl* pUrl = new QUrl(strPath);
		//≈–∂œ «∑Ò”–÷ÿ∏¥
		for (std::vector<QUrl*>::iterator iter = m_vecMusic.begin(); iter != m_vecMusic.end(); iter++)
		{
			if ((*pUrl) == *(*iter))
			{
				nRet = 2;
				break;
			}
		}
		m_vecMusic.push_back(pUrl);
	} while (false);
	return nRet;
}

QUrl* CMusicManager::GetCurrentMusic()
{
	if (0 == m_vecMusic.size())
	{
		return nullptr;
	}

	if (m_nCurMusicIndex > m_vecMusic.size())
	{
		m_nCurMusicIndex = 0;
	}
	m_nLastMusicIndex = m_nCurMusicIndex;
	return m_vecMusic[m_nCurMusicIndex];
}

QUrl* CMusicManager::GetNextMusic()
{
	//return &QUrl::fromLocalFile("E:\\1.mp3");
	if (0 == m_vecMusic.size())
	{
		return nullptr;
	}

	if (ChangeType::enChange_Type_Normal == m_enChaneType)
	{
		m_nLastMusicIndex = m_nCurMusicIndex;
		m_nCurMusicIndex++;
		if (m_nCurMusicIndex >= m_vecMusic.size())
		{
			m_nCurMusicIndex = 0;
		}
	}
	return m_vecMusic[m_nCurMusicIndex];

}

ChangeType CMusicManager::GetChangType()
{
	return enChange_Type_Normal;
}


