#include "ZHPlayerBaseUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ZHPlayerBaseUI w;
	w.show();
	return a.exec();
}
