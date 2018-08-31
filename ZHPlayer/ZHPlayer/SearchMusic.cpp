#include "SearchMusic.h"
#include <QUrl>
//#include <QRegRxp>
//#include <QDomDocument>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

SearchMusic::SearchMusic()
{
	m_strSearchBaseUrl = "http://music.taihe.com/search?key=";
	m_pAccessManager = new QNetworkAccessManager;
	m_pRequest = new QNetworkRequest;
	QObject::connect(m_pAccessManager, &QNetworkAccessManager::finished, this, &SearchMusic::replyFinished);
}

SearchMusic::~SearchMusic()
{

}

void SearchMusic::Search(QString strSearchInfo)
{
	QString strUrl = m_strSearchBaseUrl + strSearchInfo;
	m_pRequest->setUrl(QUrl(strUrl));
	m_pAccessManager->get(*m_pRequest);
}

void SearchMusic::replyFinished(QNetworkReply* reply)
{
	QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = reply->readAll();
		QString strHtml(bytes);
		GetMusicInfoByRegExp(strHtml);
		//QDomDocument parse_document;

		//QString errorStr;
		//int errorLine;
		//int errorColumn;

		//if (!parse_document.setContent(bytes, false , &errorStr, &errorLine, &errorColumn))
		//{
		//	return;
		//}
		//QDomElement root = parse_document.documentElement();
		//GetMusicUrl(root);
	}
}

std::string SearchMusic::GetSongIDByRegExp(QString strInfo)
{
	//获取id
	QString strSongIDExp = "&quot;sid&quot;:(.+),&quot;author";
	//正则表达式
	QRegularExpression regularExpression(strSongIDExp);
	int nIndex = 0;
	QRegularExpressionMatch match;
	do
	{
		match = regularExpression.match(strInfo, nIndex);
		if (match.hasMatch())
		{
			nIndex = match.capturedEnd();
			return match.captured(1).toStdString();
		}
		else
		{
			break;
		}
	} while (nIndex < strInfo.length());
	return "";
}

std::string SearchMusic::GetSingerNameByRegExp(QString strInfo)
{
	//获取id
	//QString strSingerExp = "sname&quot;:&quot;(.+)&quot;,&quot;oid";
	QString strSingerExp = "sname&quot;:&quot;(.+)&quot;,&quot;oid";
	//正则表达式
	QRegularExpression regularExpression(strSingerExp);
	int nIndex = 0;
	QRegularExpressionMatch match;
	do
	{
		match = regularExpression.match(strInfo, nIndex);
		if (match.hasMatch())
		{
			nIndex = match.capturedEnd();
			return match.captured(1).toStdString();
		}
		else
		{
			break;
		}
	} while (nIndex < strInfo.length());
	return "";
}

std::string SearchMusic::GetEmByRegExp(QString strInfo)
{
	//获取id
	QString strSingerExp = "em&gt;(.+)&lt;.*\\}\\}";
	//正则表达式
	QRegularExpression regularExpression(strSingerExp);
	int nIndex = 0;
	QRegularExpressionMatch match;
	do
	{
		match = regularExpression.match(strInfo, nIndex);
		if (match.hasMatch())
		{
			nIndex = match.capturedEnd();
			return match.captured(1).toStdString();
		}
		else
		{
			break;
		}
	} while (nIndex < strInfo.length());
	return "";
}

void SearchMusic::GetMusicInfoByRegExp(QString strSearchHtml)
{
	m_vMusicInfo.clear();
	QString strSongInfoExp = "&quot;sid&quot;:.+\\}\\}";
	//QString strSongIDExp = "&quot;sid&quot;:(\\d+).*em&gt;(.+)&lt;.*sname&quot;:&quot;(.+)&quot;,&quot;oid.*\\}\\}";
	//QString strSongIDExp = "&quot;sid&quot;:(\\d+).+\\}\\}";
	//&quot;sid&quot;:(\d+).*em&gt;(.*)&lt;.*sname&quot;:&quot;(.*)&quot;,&quot;oid.*\}\}
	//QString strSongIDExp = "sid&quot;:(\\d+).+em&gt;(.+)&lt;.+sname&quot;:&quot;(.+)&quot;.*\\}\\}";
	//QString strSongIDExp = "em&gt;(.+)&.+sname&quot;:&quot;(.+)&.*oid&quot;:(.+),&";
	//获取id
	QString strSongIDExp = "&quot;sid&quot;:(.+),&.*\\}\\}";
	QString strEmExp = "em&gt;(.+)&lt;.*\\}\\}";
	QString strAuthorExp = "sname&quot;:&quot;(.+)&quot;,.*\\}\\}";
	//获取歌手
	//获取歌名
	//正则表达式
	QRegularExpression regularExpression(strSongInfoExp);
	int nIndex = 0;
	QRegularExpressionMatch match;
	do 
	{
		match = regularExpression.match(strSearchHtml, nIndex);
		if (match.hasMatch())
		{
			tagMusicInfo MusicInfo;
			memset(&MusicInfo, 0, sizeof(MusicInfo));
			nIndex = match.capturedEnd(); 
			QString strMusicInfo = match.captured(0);
			MusicInfo.strSongID = GetSongIDByRegExp(strMusicInfo);
			MusicInfo.strSingerName = GetSingerNameByRegExp(strMusicInfo);
			MusicInfo.strSongName = GetEmByRegExp(strMusicInfo);
			m_vMusicInfo.push_back(MusicInfo);
		}
		else
		{
			break;
		}
	} while (nIndex < strSearchHtml.length());
}

//void SearchMusic::GetMusicUrl(const QDomElement & element)
//{
//	m_vMusicUrl.clear();
//	GetOneMusicUrl(element);
//}
//void SearchMusic::GetOneMusicUrl(const QDomElement & element)
//{
//	if (element.tagName() == "li")
//	{
//		QString strSongData = element.toElement().attribute("data-songitem");
//		if (!strSongData.isEmpty())
//		{
//			std::string strStdSongData = strSongData.toStdString();
//			m_vMusicUrl.push_back(strStdSongData);
//			return;
//		}
//	}
//
//	QDomNode child = element.firstChild();
//	if (!child.isNull())
//	{
//		GetOneMusicUrl(child.toElement());
//		while (!child.nextSibling().isNull())
//		{
//			GetOneMusicUrl(child.nextSibling().toElement());
//			child = child.nextSibling();
//		}
//	}
//}

