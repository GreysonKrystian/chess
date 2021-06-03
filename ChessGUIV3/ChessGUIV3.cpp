#include "ChessGUIV3.h"

ChessGUIV3::ChessGUIV3(QWidget *parent)
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
    //connect(fields[i][j], &QPushButton::clicked, this, [=]() {fields[i][j]->setIcon(choose_figure(figure->get_type(), figure->get_color())); });
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (game.get_board().get_figure(i, j) != nullptr)
            {
                connect(fields[i][j], &QPushButton::clicked, this, [=]()
                    {show_possible_moves_for_figure(game.get_board().get_figure(i, j));
                    });
            }
        }
    }
}

QIcon ChessGUIV3::choose_figure(std::string figure_type, int color)
{
    if (color == 0)
    {
        if (figure_type == "K")
            return BKing;
        if (figure_type == "B")
            return BBishop;
        if (figure_type == "N")
            return BKnight;
        if (figure_type == "R")
            return BRook;
        if (figure_type == "P")
            return BPawn;
        if (figure_type == "Q")
            return BQueen;
    }
    else
    {
        if (figure_type == "K")
            return WKing;
        if (figure_type == "B")
            return WBishop;
        if (figure_type == "N")
            return WKnight;
        if (figure_type == "R")
            return WRook;
        if (figure_type == "P")
            return WPawn;
        if (figure_type == "Q")
            return WQueen;
    }

}

void ChessGUIV3::setup_figures() // dodaje ikony poczatkowe
{
    for (int i = 0; i < 8; i++) // mozna to ogarniczyc tylko do 4 rzedow
    {
        for (int j = 0; j < 8; j++)
        {
            if (game.get_board().get_figure(i,j) != nullptr)
            {
                Figure* figure = game.get_board().get_figure(i, j);
                fields[i][j]->setIcon(choose_figure(figure->get_type(), figure->get_color()));
            }
               
        }
    }
}

void ChessGUIV3::show_possible_moves_for_figure(Figure* figure)
{
    auto pos = figure->get_possible_positions();
    for (auto it = pos.begin(); it != pos.end(); ++it)
    {
        auto cur_pos = *it;
        fields[cur_pos[0]][cur_pos[1]]->setStyleSheet("background-color: red; border: 1px solid black");
    }
}

void ChessGUIV3::hide_possible_moves_for_figure(Figure* figure)
{
    auto pos = figure->get_possible_positions();
    for (auto it = pos.begin(); it != pos.end(); ++it)
    {
        auto cur_pos = *it;
        if (((cur_pos[0] % 2 == 0) && (cur_pos[1] % 2 == 0)) || ((cur_pos[0] % 2 == 1) && (cur_pos[1] % 2 == 1)))
        {
            fields[cur_pos[0]][cur_pos[1]]->setStyleSheet("background-color: red; border: 5px solid #ff0000;");
        }
        else
        {
            fields[cur_pos[0]][cur_pos[1]]->setStyleSheet("background-color: red; border: 5px solid #ff0000;");
        }

    }
}