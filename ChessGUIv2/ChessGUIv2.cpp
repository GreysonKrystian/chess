#include "ChessGUIv2.h"

ChessGUIv2::ChessGUIv2(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    fields[0] = { ui.field00, ui.field01, ui.field02, ui.field03, ui.field04, ui.field05, ui.field06, ui.field07 };
    fields[1] = { ui.field10, ui.field11, ui.field12, ui.field13, ui.field14, ui.field15, ui.field16, ui.field17 };
    fields[2] = { ui.field20, ui.field21, ui.field22, ui.field23, ui.field24, ui.field25, ui.field26, ui.field27 };
    fields[3] = { ui.field30, ui.field31, ui.field32, ui.field33, ui.field34, ui.field35, ui.field36, ui.field37 };
    fields[4] = { ui.field40, ui.field41, ui.field42, ui.field43, ui.field44, ui.field45, ui.field46, ui.field47 };
    fields[5] = { ui.field50, ui.field51, ui.field52, ui.field53, ui.field54, ui.field55, ui.field56, ui.field57 };
    fields[6] = { ui.field60, ui.field61, ui.field62, ui.field63, ui.field64, ui.field65, ui.field66, ui.field67 };
    fields[7] = { ui.field70, ui.field71, ui.field72, ui.field73, ui.field74, ui.field75, ui.field76, ui.field77 };
    QPixmap w_knight("wN.png");
    QPixmap w_rook("wR.png");
    QPixmap w_bishop("wB.png");
    QPixmap w_king("wK.png");
    QPixmap w_pawn("wP.png");
    QPixmap w_queen("wQ.png");
    QPixmap b_knight("bN.png");
    QPixmap b_rook("bR.png");
    QPixmap b_bishop("bB.png");
    QPixmap b_king("bK.png");
    QPixmap b_pawn("bP.png");
    QPixmap b_queen("bQ.png");
    WRook.addPixmap(w_rook);
    WBishop.addPixmap(w_bishop);
    WKnight.addPixmap(w_knight);
    WKing.addPixmap(w_king);
    WPawn.addPixmap(w_pawn);
    WQueen.addPixmap(w_queen);
    BRook.addPixmap(b_rook);
    BBishop.addPixmap(b_bishop);
    BKnight.addPixmap(b_knight);
    BKing.addPixmap(b_king);
    BPawn.addPixmap(b_pawn);
    BQueen.addPixmap(b_queen);
    ui.field00->setIcon(WRook);
    ui.field00->setIconSize(w_rook.rect().size());
    ui.field01->setIcon(BRook);
    ui.field01->setIconSize(QSize(100, 100));
    //connect(ui.field00, SIGNAL(clicked()), &ui.field00, SLOT(setIcon(BKing)));
    for (int i = 0; i < 6; i++)
{
	for (int j = 0; j < 6; j++)
	{
		    connect(fields[i][j], SIGNAL(clicked()), fields[i+1][j+1], SLOT(setIcon(BKing)));
	}
}

}
void ChessGUIv2::handlebutton(QPushButton* button)
    {
        button->setIcon(BKing);
    }
