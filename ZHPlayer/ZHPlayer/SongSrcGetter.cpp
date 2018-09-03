#include "SongSrcGetter.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>

SongSrcGetter::~SongSrcGetter()
{

}

SongSrcGetter::SongSrcGetter()
{
	m_strBaseUrl = "http://music.taihe.com/data/music/fmlink?type=mp3&rate=320&songIds=";
	m_pAccessManager = new QNetworkAccessManager;
	m_pRequest = new QNetworkRequest;
	QObject::connect(m_pAccessManager, &QNetworkAccessManager::finished, this, &SongSrcGetter::replyFinish);
}

void SongSrcGetter::GetSongBySongID(QString strSongID)
{
	if (nullptr == m_pAccessManager || nullptr == m_pRequest)
	{
		return;
	}
	QString strUrl = m_strBaseUrl + strSongID;
	m_pRequest->setUrl(QUrl(strUrl));
	m_pAccessManager->get(*m_pRequest);
}

void SongSrcGetter::replyFinish(QNetworkReply* reply)
{
	//处理得到资源url
	QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = reply->readAll();
		//获取url信息
		//QJsonArray* pJsonArray = new QJsonArray()
		QJsonParseError error;
		QJsonDocument jsonDoc(QJsonDocument::fromJson(bytes, &error));
		QJsonObject rootObj = jsonDoc.object();
		QJsonObject data = rootObj.value("data").toObject();
		QJsonArray songList = data.value("songList").toArray();
		QJsonObject info = songList[0].toObject();
		SongInfo songInfo;
		memset(&songInfo, 0, sizeof(songInfo));
		QString str = info.value("songLink").toString();
		songInfo.pSrcUrl = QUrl(info.value("songLink").toString());
		emit(GetSongSrcFinish(songInfo));
	}
}



