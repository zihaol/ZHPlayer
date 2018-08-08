#include "ZHPlayerBaseUI.h"
#include <QFileDialog>

ZHPlayerBaseUI::ZHPlayerBaseUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_pMusicManager = new CMusicManager();
	m_pMusicPlayer = new QMediaPlayer();
	initConnect();
}

void ZHPlayerBaseUI::OnTouchGetMusicPath()
{
	QString strFile = QFileDialog::getOpenFileName(nullptr, QString(u8"´ò¿ª"), nullptr, "*.mp3");
	m_pMusicManager->SetMusicPath(strFile);
}

void ZHPlayerBaseUI::OnTouchLast()
{
	if (nullptr == m_pMusicManager || nullptr == m_pMusicPlayer)
	{
		return;
	}
	QUrl* pUrl = m_pMusicManager->GetLastMusic();
	if (nullptr != pUrl)
	{
		m_pMusicPlayer->setMedia(*pUrl);
		ui.m_pLabelMusicName->setText(pUrl->toString());
		m_pMusicPlayer->play();
	}
}

void ZHPlayerBaseUI::OnTouchNext()
{
	QUrl* pUrl = m_pMusicManager->GetNextMusic();
	if (m_pMusicPlayer != nullptr && m_pMusicManager != nullptr && pUrl != nullptr)
	{
		m_pMusicPlayer->setMedia(*pUrl);
		ui.m_pLabelMusicName->setText(pUrl->toString());
		m_pMusicPlayer->play();
	}
}

void ZHPlayerBaseUI::OnTouchPlay()
{
	if (m_pMusicPlayer != nullptr && m_pMusicManager != nullptr && m_pMusicManager->GetCurrentMusic())
	{
		QUrl* pUrl = m_pMusicManager->GetCurrentMusic();
		m_pMusicPlayer->setMedia(*pUrl);
		ui.m_pLabelMusicName->setText(pUrl->toString());
		m_pMusicPlayer->play();
	}
}

void ZHPlayerBaseUI::initConnect()
{
	QObject::connect(ui.m_pBtnPlay, SIGNAL(clicked()), this, SLOT(OnTouchPlay()));
	QObject::connect(ui.m_pBtnOpen, SIGNAL(clicked()), this, SLOT(OnTouchGetMusicPath()));
	QObject::connect(ui.m_pBtnNextMusic, SIGNAL(clicked()), this, SLOT(OnTouchNext()));
	QObject::connect(ui.m_pBtnLastMusic, SIGNAL(clicked()), this, SLOT(OnTouchLast()));
}



