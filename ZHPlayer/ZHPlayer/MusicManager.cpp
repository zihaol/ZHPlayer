#include "MusicManager.h"

//using namespace std;

CMusicManager::CMusicManager()
	: m_nCurMusicIndex(0)
	, m_nLastMusicIndex(0)
	//, m_enChaneType(ChangeType::enChange_Type_Normal)
{
	m_pMusicConfig = new CMusicConfig;
	LoadMusic();
}

CMusicManager::~CMusicManager()
{

}

void CMusicManager::SetCurrentMusicByName(QString strName)
{
	if (strName.isEmpty())
	{
		return;
	}
	QUrl* pUrl = new QUrl(strName);
	//判断是否有重复
	int nIndex = 0;
	for (std::vector<QUrl*>::iterator iter = m_vecMusic.begin(); iter != m_vecMusic.end(); iter++)
	{
		if ((*pUrl) == *(*iter))
		{
			m_nCurMusicIndex = nIndex;
			break;
		}
		nIndex++;
	}
}

void CMusicManager::LoadMusic()
{
	int nIndex = 0;
	while (true)
	{
		QString strPath = m_pMusicConfig->GetMusic(nIndex);
		if (strPath.isEmpty())
		{
			break;
		}
		SetMusicPath(strPath);
		nIndex++;
	}
}

int CMusicManager::GetVoice()
{
	int nRet = 0;
	do 
	{
		if (nullptr == m_pMusicConfig)
		{
			break;
		}
		nRet = m_pMusicConfig->GetPlayConfig()->nVolueNum;
	} while (false);
	return nRet;
}

 void CMusicManager::SetVoice(int nVoice)
{
	 if (nullptr == m_pMusicConfig)
	 {
		 return;
	 }
	 //m_pMusicConfig->GetPlayConfig()->nVolueNum = nVoice;
	 m_pMusicConfig->SetVolueNum(nVoice);
	 m_pMusicConfig->SavePlayConfig();
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
		//判断是否有重复
		for (std::vector<QUrl*>::iterator iter = m_vecMusic.begin(); iter != m_vecMusic.end(); iter++)
		{
			if ((*pUrl) == *(*iter))
			{
				nRet = 2;
				break;
			}
		}
		m_vecMusic.push_back(pUrl);
		m_pMusicConfig->SaveMusic(m_vecMusic.size() - 1, strPath);
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

QUrl* CMusicManager::GetLastMusic()
{
	if (0 == m_vecMusic.size())
	{
		return nullptr;
	}

	if (m_nLastMusicIndex > m_vecMusic.size())
	{
		m_nLastMusicIndex = 0;
	}
	m_nCurMusicIndex = m_nLastMusicIndex;
	return m_vecMusic[m_nLastMusicIndex];
}

QUrl* CMusicManager::GetNextMusic()
{
	//return &QUrl::fromLocalFile("E:\\1.mp3");
	if (0 == m_vecMusic.size())
	{
		return nullptr;
	}

	if (ChangeType::enChange_Type_Normal == m_pMusicConfig->GetPlayType())
	{
		m_nLastMusicIndex = m_nCurMusicIndex;
		m_nCurMusicIndex++;
		if (m_nCurMusicIndex >= m_vecMusic.size())
		{
			m_nCurMusicIndex = 0;
		}
	}
	else if (ChangeType::enChange_Type_Rand == m_pMusicConfig->GetPlayType())
	{
		m_nLastMusicIndex = m_nCurMusicIndex;
		if (m_vecMusic.size() > 0)
		{
			m_nCurMusicIndex = rand() % m_vecMusic.size();
		}
	}
	else
	{
		m_nCurMusicIndex = m_nCurMusicIndex;
	}
	return m_vecMusic[m_nCurMusicIndex];

}

void CMusicManager::GetNextType()
{
	ChangeType enChangeType = ChangeType(m_pMusicConfig->GetPlayType() + 1);
	if (enChangeType >= enChange_Type_TypeNum)
	{
		enChangeType = enChange_Type_Normal;
	}

	if (nullptr != m_pMusicConfig)
	{
		m_pMusicConfig->SetPlayType(enChangeType);
		m_pMusicConfig->SavePlayConfig();
	}
}

ChangeType CMusicManager::GetChangType()
{
	return m_pMusicConfig->GetPlayType();
}


