#include "SearchMusic.h"
#include <QUrl>
//#include <QRegRxp>
//#include <QDomDocument>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
//#include <QTextCodec>

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
	//QString strSongIDExp = "&quot;sid&quot;:.*(\\u[\w]{4}).*,&quot;author";
	//QString strSongIDExp = "&quot;sid&quot;:.*([\d]+).*,&quot;author";
	QString strSongIDExp = "&quot;sid&quot;:(.*),&quot;author";
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
	QString strSingerExp = "author&quot;:&quot;(.+)&quot;,&quot;sname";
	//QString strSingerExp = "author&quot;:&quot;.*(\\u\\w+).*&quot;,&quot;sname";
	//QString strSingerExp = "author&quot;:&quot;.*((\\w{5})+).*&quot;,&quot;sname";
	//正则表达式
	QRegularExpression regularExpression(strSingerExp);
	int nIndex = 0;

	QString strError = regularExpression.errorString();


	QRegularExpressionMatch match;
	do
	{
		match = regularExpression.match(strInfo, nIndex);
		if (match.hasMatch())
		{
			nIndex = match.capturedEnd();
			QString strSearch = match.captured(0);
			return GetUTF8Info(strSearch);
		}
		else
		{
			break;
		}
	} while (nIndex < strInfo.length());
	return "";
}

QString SearchMusic::ConverHtmlToUTF8(QString strInfo)
{
	QString strRet = strInfo;
	do 
	{
		int nIdx = strRet.indexOf("\\u");
		QString strHex = strRet.mid(nIdx, 6);
		strHex = strHex.replace("\\u", QString());
		int nHex = strHex.toInt(0, 16);
		strRet.replace(nIdx, 6, QChar(nHex));
	} while (strRet.indexOf("\\u") != -1);
	return strRet;
}

std::string SearchMusic::GetUTF8Info(QString strInfo)
{
	//提取编码
	QString strExstractExp = "(\\\\(\\w){5})+";
	QRegularExpression regularExtract(strExstractExp);
	int nIndex = 0;
	QRegularExpressionMatch match;
	do 
	{
		match = regularExtract.match(strInfo, nIndex);
		if (match.hasMatch())
		{
			nIndex = match.capturedEnd();
			QString str = match.captured(0);
			str = ConverHtmlToUTF8(str);
			return str.toStdString();
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
	QString strSingerExp = "sname&quot;:&quot;.+&quot;,";
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
			QString strInfo = match.captured(0);
			return GetUTF8Info(strInfo);
			//return match.captured(1).toStdString();
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
	emit SearchFinish(m_vMusicInfo);
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

