#include "MusicManager.h"

//using namespace std;

CMusicManager::CMusicManager()
{
	QUrl pUrl = QUrl::fromLocalFile("E:\\1.mp3");
	//pUrl->setPath("E:\\1.mp3");
	QUrl* pUrll = new QUrl;
	(*pUrll) = pUrl;
	m_listMusic.push_back(pUrll);
}

CMusicManager::~CMusicManager()
{

}

QUrl* CMusicManager::GetCurrentMusic()
{
	return m_listMusic[0];
}

QUrl* CMusicManager::GetNextMusic()
{
	return &QUrl::fromLocalFile("E:\\1.mp3");
}

ChangeType CMusicManager::GetChangType()
{
	return enChange_Type_Normal;
}


