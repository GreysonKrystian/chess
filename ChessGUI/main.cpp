#include "ChessGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessGUI w;
    w.show();
    return a.exec();
}
