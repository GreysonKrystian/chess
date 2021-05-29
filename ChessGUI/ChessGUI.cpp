#include "ChessGUI.h"

ChessGUI::ChessGUI(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QGraphicsScene* WRook = new QGraphicsScene;
    QGraphicsScene* WBishop = new QGraphicsScene;
    QGraphicsScene* WKnight = new QGraphicsScene;
    QGraphicsScene* WKing = new QGraphicsScene;
    QGraphicsScene* WPawn = new QGraphicsScene;
    QGraphicsScene* WQueen = new QGraphicsScene;
    QGraphicsScene* BRook = new QGraphicsScene;
    QGraphicsScene* BBishop = new QGraphicsScene;
    QGraphicsScene* BKnight = new QGraphicsScene;
    QGraphicsScene* BKing = new QGraphicsScene;
    QGraphicsScene* BPawn = new QGraphicsScene;
    QGraphicsScene* BQueen = new QGraphicsScene;
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
    WRook->addPixmap(w_rook);
    WBishop->addPixmap(w_bishop);
    WKnight->addPixmap(w_knight);
    WKing->addPixmap(w_king);
    WPawn->addPixmap(w_pawn);
    WQueen->addPixmap(w_queen);
    BRook->addPixmap(b_rook);
    BBishop->addPixmap(b_bishop);
    BKnight->addPixmap(b_knight);
    BKing->addPixmap(b_king);
    BPawn->addPixmap(b_pawn);
    BQueen->addPixmap(b_queen);

    ui.field00->setScene(WRook);
    ui.field00->setScene(BRook);

    /* ui.field00->resetCachedContent();
     ui.field00->setScene(f00);*/


}