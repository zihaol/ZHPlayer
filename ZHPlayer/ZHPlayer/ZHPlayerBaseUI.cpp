#include "ZHPlayerBaseUI.h"

ZHPlayerBaseUI::ZHPlayerBaseUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_pMusicManager = new CMusicManager();
	m_pMusicPlayer = new QMediaPlayer();
	initConnect();
}


void ZHPlayerBaseUI::OnTouchPlay()
{
	if (m_pMusicPlayer != nullptr && m_pMusicManager != nullptr)
	{
		m_pMusicPlayer->setMedia(*(m_pMusicManager->GetCurrentMusic()));
		m_pMusicPlayer->setVolume(50);
		m_pMusicPlayer->play();
	}
}

void ZHPlayerBaseUI::initConnect()
{
	QObject::connect(ui.m_pBtnPlay, SIGNAL(clicked()), this, SLOT(OnTouchPlay()));
}



