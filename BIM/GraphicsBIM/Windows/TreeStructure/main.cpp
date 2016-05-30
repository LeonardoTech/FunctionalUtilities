#include "treestructure.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TreeStructure w;
	w.show();
	return a.exec();
}
