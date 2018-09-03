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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QListWidget *m_pListWidgetMusic;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_pEditMusic;
    QPushButton *m_pBtnSearch;
    QListWidget *m_pListSearchResult;

    void setupUi(QMainWindow *ZHPlayerBaseUIClass)
    {
        if (ZHPlayerBaseUIClass->objectName().isEmpty())
            ZHPlayerBaseUIClass->setObjectName(QStringLiteral("ZHPlayerBaseUIClass"));
        ZHPlayerBaseUIClass->resize(799, 301);
        ZHPlayerBaseUIClass->setWindowOpacity(1);
        centralWidget = new QWidget(ZHPlayerBaseUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        m_pBtnLastMusic = new QPushButton(centralWidget);
        m_pBtnLastMusic->setObjectName(QStringLiteral("m_pBtnLastMusic"));
        m_pBtnLastMusic->setGeometry(QRect(10, 10, 40, 39));
        m_pBtnNextMusic = new QPushButton(centralWidget);
        m_pBtnNextMusic->setObjectName(QStringLiteral("m_pBtnNextMusic"));
        m_pBtnNextMusic->setGeometry(QRect(105, 10, 40, 37));
        m_pBtnPlay = new QPushButton(centralWidget);
        m_pBtnPlay->setObjectName(QStringLiteral("m_pBtnPlay"));
        m_pBtnPlay->setGeometry(QRect(60, 12, 37, 37));
        m_pSlider = new QSlider(centralWidget);
        m_pSlider->setObjectName(QStringLiteral("m_pSlider"));
        m_pSlider->setGeometry(QRect(170, 10, 201, 19));
        m_pSlider->setOrientation(Qt::Horizontal);
        m_pLabelMusicName = new QLabel(centralWidget);
        m_pLabelMusicName->setObjectName(QStringLiteral("m_pLabelMusicName"));
        m_pLabelMusicName->setGeometry(QRect(170, 30, 81, 16));
        m_pBtnVolue = new QPushButton(centralWidget);
        m_pBtnVolue->setObjectName(QStringLiteral("m_pBtnVolue"));
        m_pBtnVolue->setGeometry(QRect(390, 30, 32, 32));
        m_pBtnChangeType = new QPushButton(centralWidget);
        m_pBtnChangeType->setObjectName(QStringLiteral("m_pBtnChangeType"));
        m_pBtnChangeType->setGeometry(QRect(480, 27, 35, 35));
        m_pBtnOpen = new QPushButton(centralWidget);
        m_pBtnOpen->setObjectName(QStringLiteral("m_pBtnOpen"));
        m_pBtnOpen->setGeometry(QRect(430, 25, 39, 39));
        m_pLabelTatalTime = new QLabel(centralWidget);
        m_pLabelTatalTime->setObjectName(QStringLiteral("m_pLabelTatalTime"));
        m_pLabelTatalTime->setGeometry(QRect(310, 30, 54, 12));
        m_pSliderVoice = new QSlider(centralWidget);
        m_pSliderVoice->setObjectName(QStringLiteral("m_pSliderVoice"));
        m_pSliderVoice->setGeometry(QRect(400, 5, 111, 19));
        m_pSliderVoice->setOrientation(Qt::Horizontal);
        m_pListWidgetMusic = new QListWidget(centralWidget);
        m_pListWidgetMusic->setObjectName(QStringLiteral("m_pListWidgetMusic"));
        m_pListWidgetMusic->setGeometry(QRect(3, 70, 521, 230));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(550, 10, 216, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        m_pEditMusic = new QLineEdit(layoutWidget);
        m_pEditMusic->setObjectName(QStringLiteral("m_pEditMusic"));

        horizontalLayout->addWidget(m_pEditMusic);

        m_pBtnSearch = new QPushButton(layoutWidget);
        m_pBtnSearch->setObjectName(QStringLiteral("m_pBtnSearch"));

        horizontalLayout->addWidget(m_pBtnSearch);

        m_pListSearchResult = new QListWidget(centralWidget);
        m_pListSearchResult->setObjectName(QStringLiteral("m_pListSearchResult"));
        m_pListSearchResult->setGeometry(QRect(540, 45, 256, 251));
        ZHPlayerBaseUIClass->setCentralWidget(centralWidget);

        retranslateUi(ZHPlayerBaseUIClass);

        QMetaObject::connectSlotsByName(ZHPlayerBaseUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *ZHPlayerBaseUIClass)
    {
        ZHPlayerBaseUIClass->setWindowTitle(QApplication::translate("ZHPlayerBaseUIClass", "ZHPlayer", nullptr));
        m_pBtnLastMusic->setText(QString());
        m_pBtnNextMusic->setText(QString());
        m_pBtnPlay->setText(QString());
        m_pLabelMusicName->setText(QApplication::translate("ZHPlayerBaseUIClass", "music", nullptr));
        m_pBtnVolue->setText(QString());
        m_pBtnChangeType->setText(QString());
        m_pBtnOpen->setText(QString());
        m_pLabelTatalTime->setText(QApplication::translate("ZHPlayerBaseUIClass", "0:00", nullptr));
        m_pBtnSearch->setText(QApplication::translate("ZHPlayerBaseUIClass", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ZHPlayerBaseUIClass: public Ui_ZHPlayerBaseUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHPLAYERBASEUI_H
