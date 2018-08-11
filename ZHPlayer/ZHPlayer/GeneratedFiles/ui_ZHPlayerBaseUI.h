/********************************************************************************
** Form generated from reading UI file 'ZHPlayerBaseUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHPLAYERBASEUI_H
#define UI_ZHPLAYERBASEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZHPlayerBaseUIClass
{
public:
    QWidget *centralWidget;
    QPushButton *m_pBtnLastMusic;
    QPushButton *m_pBtnNextMusic;
    QPushButton *m_pBtnPlay;
    QSlider *m_pSlider;
    QLabel *m_pLabelMusicName;
    QPushButton *m_pBtnVolue;
    QPushButton *m_pBtnChangeType;
    QPushButton *m_pBtnOpen;
    QLabel *m_pLabelTatalTime;
    QSlider *m_pSliderVoice;
    QLabel *m_pLabelType;

    void setupUi(QMainWindow *ZHPlayerBaseUIClass)
    {
        if (ZHPlayerBaseUIClass->objectName().isEmpty())
            ZHPlayerBaseUIClass->setObjectName(QStringLiteral("ZHPlayerBaseUIClass"));
        ZHPlayerBaseUIClass->resize(528, 102);
        ZHPlayerBaseUIClass->setWindowOpacity(1);
        centralWidget = new QWidget(ZHPlayerBaseUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        m_pBtnLastMusic = new QPushButton(centralWidget);
        m_pBtnLastMusic->setObjectName(QStringLiteral("m_pBtnLastMusic"));
        m_pBtnLastMusic->setGeometry(QRect(10, 50, 51, 31));
        m_pBtnNextMusic = new QPushButton(centralWidget);
        m_pBtnNextMusic->setObjectName(QStringLiteral("m_pBtnNextMusic"));
        m_pBtnNextMusic->setGeometry(QRect(120, 50, 51, 31));
        m_pBtnPlay = new QPushButton(centralWidget);
        m_pBtnPlay->setObjectName(QStringLiteral("m_pBtnPlay"));
        m_pBtnPlay->setGeometry(QRect(70, 50, 41, 31));
        m_pSlider = new QSlider(centralWidget);
        m_pSlider->setObjectName(QStringLiteral("m_pSlider"));
        m_pSlider->setGeometry(QRect(190, 40, 201, 19));
        m_pSlider->setOrientation(Qt::Horizontal);
        m_pLabelMusicName = new QLabel(centralWidget);
        m_pLabelMusicName->setObjectName(QStringLiteral("m_pLabelMusicName"));
        m_pLabelMusicName->setGeometry(QRect(190, 60, 81, 16));
        m_pBtnVolue = new QPushButton(centralWidget);
        m_pBtnVolue->setObjectName(QStringLiteral("m_pBtnVolue"));
        m_pBtnVolue->setGeometry(QRect(410, 30, 35, 61));
        m_pBtnChangeType = new QPushButton(centralWidget);
        m_pBtnChangeType->setObjectName(QStringLiteral("m_pBtnChangeType"));
        m_pBtnChangeType->setGeometry(QRect(490, 30, 35, 61));
        m_pBtnOpen = new QPushButton(centralWidget);
        m_pBtnOpen->setObjectName(QStringLiteral("m_pBtnOpen"));
        m_pBtnOpen->setGeometry(QRect(450, 30, 35, 61));
        m_pLabelTatalTime = new QLabel(centralWidget);
        m_pLabelTatalTime->setObjectName(QStringLiteral("m_pLabelTatalTime"));
        m_pLabelTatalTime->setGeometry(QRect(330, 60, 54, 12));
        m_pSliderVoice = new QSlider(centralWidget);
        m_pSliderVoice->setObjectName(QStringLiteral("m_pSliderVoice"));
        m_pSliderVoice->setGeometry(QRect(410, 5, 111, 19));
        m_pSliderVoice->setOrientation(Qt::Horizontal);
        m_pLabelType = new QLabel(centralWidget);
        m_pLabelType->setObjectName(QStringLiteral("m_pLabelType"));
        m_pLabelType->setGeometry(QRect(497, 50, 21, 21));
        ZHPlayerBaseUIClass->setCentralWidget(centralWidget);

        retranslateUi(ZHPlayerBaseUIClass);

        QMetaObject::connectSlotsByName(ZHPlayerBaseUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *ZHPlayerBaseUIClass)
    {
        ZHPlayerBaseUIClass->setWindowTitle(QApplication::translate("ZHPlayerBaseUIClass", "ZHPlayer", nullptr));
        m_pBtnLastMusic->setText(QApplication::translate("ZHPlayerBaseUIClass", "\344\270\212\344\270\200\351\246\226", nullptr));
        m_pBtnNextMusic->setText(QApplication::translate("ZHPlayerBaseUIClass", "\344\270\213\344\270\200\351\246\226", nullptr));
        m_pBtnPlay->setText(QApplication::translate("ZHPlayerBaseUIClass", "\346\222\255\346\224\276", nullptr));
        m_pLabelMusicName->setText(QApplication::translate("ZHPlayerBaseUIClass", "music", nullptr));
        m_pBtnVolue->setText(QApplication::translate("ZHPlayerBaseUIClass", "\351\237\263\351\207\217", nullptr));
        m_pBtnChangeType->setText(QString());
        m_pBtnOpen->setText(QApplication::translate("ZHPlayerBaseUIClass", "\346\211\223\345\274\200", nullptr));
        m_pLabelTatalTime->setText(QApplication::translate("ZHPlayerBaseUIClass", "0:00", nullptr));
        m_pLabelType->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ZHPlayerBaseUIClass: public Ui_ZHPlayerBaseUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHPLAYERBASEUI_H
