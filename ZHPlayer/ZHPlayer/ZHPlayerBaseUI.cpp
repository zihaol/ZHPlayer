#include "ZHPlayerBaseUI.h"
#include <QFileDialog>
#include <QTime>

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
	QString strFile = QFileDialog::getOpenFileName(nullptr, QString(u8"打开"), nullptr, "*.mp3");
	m_pMusicManager->SetMusicPath(strFile);
}

void ZHPlayerBaseUI::OnUpdateDuration(qint64 nDuration)
{
	ui.m_pSlider->setRange(0, nDuration);
}

void ZHPlayerBaseUI::OnSliderMoved()
{
	int nValue = ui.m_pSlider->value();
	if (m_pMusicPlayer != nullptr)
	{
		m_pMusicPlayer->setPosition(nValue);
	}
}

void ZHPlayerBaseUI::OnUpdatePosition(qint64 nPosition)
{
	//ui.m_pLabelTatalTime->setText(m_pMusicPlayer->)
	ui.m_pSlider->setValue(nPosition);
	int a = ui.m_pSlider->maximum();
	if (a != 0 && a == nPosition)
	{
		//切换到下一首
		OnTouchNext();
	}
	QTime duration(0, nPosition / 60000, qRound((nPosition % 60000) / 1000.0f));
	ui.m_pLabelTatalTime->setText(duration.toString(tr("mm:ss")));
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
		//QString strTime;
		//qint64 a = m_pMusicPlayer->position();
		//strTime.sprintf("%lld", m_pMusicPlayer->duration());
		//ui.m_pLabelTatalTime->setText(strTime);
	}
}

void ZHPlayerBaseUI::initConnect()
{
	QObject::connect(ui.m_pBtnPlay, SIGNAL(clicked()), this, SLOT(OnTouchPlay()));
	QObject::connect(ui.m_pBtnOpen, SIGNAL(clicked()), this, SLOT(OnTouchGetMusicPath()));
	QObject::connect(ui.m_pBtnNextMusic, SIGNAL(clicked()), this, SLOT(OnTouchNext()));
	QObject::connect(ui.m_pBtnLastMusic, SIGNAL(clicked()), this, SLOT(OnTouchLast()));

	QObject::connect(m_pMusicPlayer, &QMediaPlayer::positionChanged, this, &ZHPlayerBaseUI::OnUpdatePosition);
	QObject::connect(m_pMusicPlayer, &QMediaPlayer::durationChanged, this, &ZHPlayerBaseUI::OnUpdateDuration);
	QObject::connect(ui.m_pSlider, &QSlider::sliderMoved, this, &ZHPlayerBaseUI::OnSliderMoved);
}



