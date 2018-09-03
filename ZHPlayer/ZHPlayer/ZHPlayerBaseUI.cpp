#include "ZHPlayerBaseUI.h"
#include <QFileDialog>
#include <QListWidgetItem>
#include <QTime>

ZHPlayerBaseUI::ZHPlayerBaseUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.m_pSliderVoice->setVisible(false);
	m_pMusicManager = new CMusicManager();
	m_pMusicPlayer = new QMediaPlayer();
	m_pMusicSearch = new SearchMusic();
	m_pSongSrcGetter = new SongSrcGetter();

	ui.m_pSliderVoice->setRange(0, 100);
	initConnect();
	InitConfig();

	QFile qssFile("qss.qss");
	qssFile.open(QFile::ReadOnly);
	QString strQss;
	strQss = qssFile.readAll();
	this->setStyleSheet(strQss);
}

void ZHPlayerBaseUI::UpdateSearchMusicInfo(std::vector<tagMusicInfo> vMusicInfo)
{
	ui.m_pListSearchResult->clear();
	for (auto musicInfo : vMusicInfo)
	{
		QListWidgetItem* pListItem = new QListWidgetItem();
		char szSongInfo[128];
		memset(szSongInfo, 0, sizeof(szSongInfo));
		snprintf(szSongInfo, sizeof(szSongInfo), "%s ---- %s", musicInfo.strSongName.c_str(), musicInfo.strSingerName.c_str());
		pListItem->setText(szSongInfo);
		QString strSongID = musicInfo.strSongID.c_str();
		pListItem->setData(Qt::UserRole, strSongID);
		ui.m_pListSearchResult->addItem(pListItem);
	}
}

void ZHPlayerBaseUI::UpdateMusicList()
{
	if (m_pMusicManager != nullptr)
	{
		for (std::vector<QUrl*>::iterator iter = m_pMusicManager->m_vecMusic.begin(); iter != m_pMusicManager->m_vecMusic.end(); iter++)
		{
			QListWidgetItem* pListItem = new QListWidgetItem((*iter)->toString());
			ui.m_pListWidgetMusic->addItem(pListItem);
		}
	}
}
void ZHPlayerBaseUI::UpdatePlayStatus()
{
	ChangeType type = m_pMusicManager->GetChangType();
	QString strStatus = u8"顺序";
	switch (type)
	{
	case enChange_Type_Normal:
		strStatus = u8"顺序";
		break;
	case enChange_Type_OnleOne:
		strStatus = u8"单曲";
		break;
	case enChange_Type_Rand:
		strStatus = u8"随机";
		break;
	default:
		strStatus = u8"无效";
		break;
	}

	if (ui.m_pBtnChangeType != nullptr)
	{
		ui.m_pBtnChangeType->setText(strStatus);
	}
}

void ZHPlayerBaseUI::InitConfig()
{
	int nVolume = m_pMusicManager->GetVoice();
	ui.m_pSliderVoice->setValue(nVolume);
	m_pMusicPlayer->setVolume(nVolume);
	UpdatePlayStatus();
	//更新歌曲列表
	UpdateMusicList();
	//ui.m_pLabelType->setText(u8"顺");
}

ZHPlayerBaseUI::~ZHPlayerBaseUI()
{
	//if (nullptr != m_pMusicManager)
	//{
	//	m_pMusicManager->SetVoice(ui.m_pSliderVoice->value());
	//}
}

void ZHPlayerBaseUI::OnTouchGetMusicPath()
{
	QString strFile = QFileDialog::getOpenFileName(nullptr, QString(u8"打开"), nullptr, "*.mp3");
	m_pMusicManager->SetMusicPath(strFile);
	UpdateMusicList();
}

void ZHPlayerBaseUI::OnUpdateDuration(qint64 nDuration)
{
	ui.m_pSlider->setRange(0, nDuration);
}

//搜索结果
void ZHPlayerBaseUI::OnSearchResult(std::vector<tagMusicInfo> vMusicInfo)
{
	//for (auto i : vMusicInfo)
	//{
	//	std::string strName = i.strSingerName;
	//}
	UpdateSearchMusicInfo(vMusicInfo);
}

//搜索按钮
void ZHPlayerBaseUI::OnTouchSearch()
{
	if (nullptr == m_pMusicSearch)
	{
		return;
	}
	QString strSearchInfo = ui.m_pEditMusic->text();
	if (strSearchInfo.isEmpty())
	{
		return;
	}
	m_pMusicSearch->Search(strSearchInfo);
	//m_pMusicSearch->Search(u8"烟火");
}

//搜索列表双击
void ZHPlayerBaseUI::OnSearchItemDoubleClicked(QListWidgetItem *item)
{
	if (m_pSongSrcGetter != nullptr)
	{
		m_pSongSrcGetter->GetSongBySongID(item->data(Qt::UserRole).toString());
	}
}

void ZHPlayerBaseUI::GetSongSrcFinish(SongInfo pSongInfo)
{
	//if (pSongInfo != nullptr && pSongInfo->pSrcUrl != nullptr)
	{
		m_pMusicPlayer->setMedia(pSongInfo.pSrcUrl);
		m_pMusicPlayer->play();
	}
	//m_pMusicManager->SetMusicPath(pSongInfo->pSrcUrl->toString());
	//UpdateMusicList();
	//m_pMusicManager->SetCurrentMusicByName(pSongInfo->pSrcUrl->toString());
	//OnTouchPlay();
}

void ZHPlayerBaseUI::OnItemDoubleClicked(QListWidgetItem *item)
{
	if (m_pMusicManager != nullptr)
	{
		m_pMusicManager->SetCurrentMusicByName(item->text());
		OnTouchPlay();
	}
}

void ZHPlayerBaseUI::OnSliderVoiceMoved()
{
	int nVolume = ui.m_pSliderVoice->value();
	if (nullptr != m_pMusicPlayer)
	{
		m_pMusicPlayer->setVolume(nVolume);
	}
	if (nullptr != m_pMusicManager)
	{
		m_pMusicManager->SetVoice(nVolume);
	}
}
void ZHPlayerBaseUI::OnSliderPositionMoved()
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

void ZHPlayerBaseUI::OnTouchPlayType()
{
	if (m_pMusicManager != nullptr)
	{
		m_pMusicManager->GetNextType();
	}
	UpdatePlayStatus();
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

void ZHPlayerBaseUI::OnTouchVolume()
{
	ui.m_pSliderVoice->setVisible(!ui.m_pSliderVoice->isVisible());
}

void ZHPlayerBaseUI::OnTouchPlay()
{
	if (m_pMusicPlayer != nullptr && m_pMusicManager != nullptr && m_pMusicManager->GetCurrentMusic())
	{
		QUrl* pUrl = m_pMusicManager->GetCurrentMusic();
		m_pMusicPlayer->setMedia(*pUrl);
		//m_pMusicPlayer->setMedia(QUrl("http://zhangmenshiting.qianqian.com/data2/music/692a14470c187015824937e46dce707c/599636438/235725248400320.mp3?xcode=f3801dd3e9ffcb1de9c5304b21fec782"));
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
	QObject::connect(ui.m_pBtnVolue, SIGNAL(clicked()), this, SLOT(OnTouchVolume()));
	QObject::connect(ui.m_pBtnChangeType, SIGNAL(clicked()), this, SLOT(OnTouchPlayType()));

	QObject::connect(m_pMusicPlayer, &QMediaPlayer::positionChanged, this, &ZHPlayerBaseUI::OnUpdatePosition);
	QObject::connect(m_pMusicPlayer, &QMediaPlayer::durationChanged, this, &ZHPlayerBaseUI::OnUpdateDuration);
	QObject::connect(ui.m_pSlider, &QSlider::sliderMoved, this, &ZHPlayerBaseUI::OnSliderPositionMoved);
	QObject::connect(ui.m_pSliderVoice, &QSlider::sliderMoved, this, &ZHPlayerBaseUI::OnSliderVoiceMoved);
	QObject::connect(ui.m_pListWidgetMusic, &QListWidget::itemDoubleClicked, this, &ZHPlayerBaseUI::OnItemDoubleClicked);
	QObject::connect(m_pSongSrcGetter, &SongSrcGetter::GetSongSrcFinish, this, &ZHPlayerBaseUI::GetSongSrcFinish);
	QObject::connect(ui.m_pListSearchResult, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(OnSearchItemDoubleClicked(QListWidgetItem *)));

	QObject::connect(ui.m_pBtnSearch, SIGNAL(clicked()), this, SLOT(OnTouchSearch()));
	QObject::connect(m_pMusicSearch, SIGNAL(SearchFinish(std::vector<tagMusicInfo>)), this, SLOT(OnSearchResult(std::vector<tagMusicInfo>)));
}



