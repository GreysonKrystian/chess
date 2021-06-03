#include "ChessGUIV3.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessGUIV3 w;
    w.setup_figures();
    w.show();
    return a.exec();
}
