#pragma once
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDomElement>
#include <vector>

struct tagMusicInfo
{
	std::string					strSongID;
	std::string					strSongName;
	std::string					strSingerName;
};

class SearchMusic : public QObject
{
	Q_OBJECT
public:
	SearchMusic();
	~SearchMusic();
	void Search(QString strSearchInfo);
	//void GetMusicUrl(const QDomElement & element);
	//void GetOneMusicUrl(const QDomElement & element);
	void GetMusicInfoByRegExp(QString strSearchHtml);
	std::string GetSongIDByRegExp(QString strInfo);
	std::string GetSingerNameByRegExp(QString strInfo);
	std::string GetEmByRegExp(QString strInfo);
public slots:
	void replyFinished(QNetworkReply* reply);
private:
	QString						m_strSearchBaseUrl;
	QNetworkAccessManager*		m_pAccessManager;
	QNetworkRequest*			m_pRequest;
	std::vector<std::string>	m_vMusicUrl;
	std::vector<tagMusicInfo>	m_vMusicInfo;
};



