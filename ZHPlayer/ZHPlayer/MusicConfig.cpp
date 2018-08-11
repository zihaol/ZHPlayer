#include "MusicConfig.h"

CMusicConfig::CMusicConfig()
{
	m_pConfigFile = new QSettings("Config.ini", QSettings::IniFormat);
	m_pPlayConfig = new tagPlayConfig;
	memset(m_pPlayConfig, 0, sizeof(m_pPlayConfig));
	LoadConfig();
}

CMusicConfig::~CMusicConfig()
{

}

void CMusicConfig::LoadConfig()
{
	m_pPlayConfig->enChangeType = (ChangeType)m_pConfigFile->value("/config/Type").toInt();
	m_pPlayConfig->nCurrentMusic = m_pConfigFile->value("/config/CurrentIndex").toInt();
	m_pPlayConfig->nVolueNum = m_pConfigFile->value("/config/Volue").toInt();
}

void CMusicConfig::SavePlayConfig()
{
	if (nullptr == m_pConfigFile)
	{
		return;
	}
	m_pConfigFile->setValue("config/Volue", m_pPlayConfig->nVolueNum);
	m_pConfigFile->setValue("config/Type", m_pPlayConfig->enChangeType);
	m_pConfigFile->setValue("config/CurrentIndex", m_pPlayConfig->nCurrentMusic);
}

tagPlayConfig* CMusicConfig::GetPlayConfig()
{
	return m_pPlayConfig;
}

void CMusicConfig::SetPlayType(ChangeType enType)
{
	if (nullptr == m_pPlayConfig)
	{
		m_pPlayConfig = new tagPlayConfig;
	}
	m_pPlayConfig->enChangeType = enType;
}

ChangeType CMusicConfig::GetPlayType()
{
	return m_pPlayConfig->enChangeType;
}
void CMusicConfig::SetCurrentMusicIndex(int nIndex)
{
	if (nullptr == m_pPlayConfig)
	{
		m_pPlayConfig = new tagPlayConfig;
	}
	m_pPlayConfig->nCurrentMusic = nIndex;
}

void CMusicConfig::SetVolueNum(int nVolue)
{
	if (nullptr == m_pPlayConfig)
	{
		m_pPlayConfig = new tagPlayConfig;
	}
	m_pPlayConfig->nVolueNum = nVolue;
}

QString CMusicConfig::GetMusic(int nIndex)
{
	QString strRet = "";
	do 
	{
		if (nullptr == m_pConfigFile)
		{
			break;
		}
		QString strIndex;
		strIndex.sprintf("music/%d", nIndex);
		strRet = m_pConfigFile->value(strIndex).toString();
	} while (false);
	return strRet;
}

void CMusicConfig::SaveMusic(int nIdex, QString strMusicName)
{
	if (nullptr == m_pConfigFile)
	{
		return;
	}
	QString strIndex;
	strIndex.sprintf("music/%d", nIdex);
	m_pConfigFile->setValue(strIndex, strMusicName);
}
