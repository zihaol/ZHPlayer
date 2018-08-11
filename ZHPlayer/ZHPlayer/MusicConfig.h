#pragma once
#include <QSettings>

enum ChangeType
{
	enChange_Type_Normal = 0,
	enChange_Type_Rand = 1,
	enChange_Type_OnleOne = 2,
	enChange_Type_TypeNum = 3,
};

struct tagPlayConfig
{
	ChangeType		enChangeType;					//�л�ģʽ
	int				nCurrentMusic;					//��ǰ����
	int				nVolueNum;						//����
};

class CMusicConfig
{
public:
	CMusicConfig();
	~CMusicConfig();
	void LoadConfig();
	void SavePlayConfig();
	tagPlayConfig* GetPlayConfig();
	ChangeType GetPlayType();
	void SetPlayType(ChangeType enType);
	void SetCurrentMusicIndex(int nIndex);
	void SetVolueNum(int nVolue);
	QString GetMusic(int nIndex);
	void SaveMusic(int nIdex, QString strMusicName);

private:
	QSettings*					m_pConfigFile;
	tagPlayConfig*				m_pPlayConfig;
};



