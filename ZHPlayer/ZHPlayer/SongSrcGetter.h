#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonArray>

struct SongInfo
{
	QUrl				pSrcUrl;
	std::string			strSongName;
	std::string			strSangerName;
};

class SongSrcGetter : public QObject
{
	Q_OBJECT
public:
	~SongSrcGetter();
	SongSrcGetter();
	void GetSongBySongID(QString strSongID);
public slots:
	void replyFinish(QNetworkReply* reply);
signals:
	void GetSongSrcFinish(SongInfo pSongInfo);
private:
	QString				m_strBaseUrl;
	QNetworkAccessManager*	m_pAccessManager;
	QNetworkRequest*		m_pRequest;
};


