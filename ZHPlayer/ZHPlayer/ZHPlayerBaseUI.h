#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ZHPlayerBaseUI.h"

class ZHPlayerBaseUI : public QMainWindow
{
	Q_OBJECT

public:
	ZHPlayerBaseUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::ZHPlayerBaseUIClass ui;
};
