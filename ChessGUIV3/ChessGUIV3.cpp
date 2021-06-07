#include "ChessGUIV3.h"
#include <QMovie>
#include <Windows.h>


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
    
    /*QPixmap mateusz("om.png");
    mateusz = mateusz.scaled(ui.logo->size(), Qt::KeepAspectRatio);
    ui.logo->setPixmap(mateusz);*/

   QMovie* mateusz = new QMovie("3d1.gif");
   //mateusz = mateusz.scaled(ui.logo->size(), Qt::KeepAspectRatio);
   ui.logo->setMovie(mateusz);
   mateusz->start();

    QPixmap fight("fight.png");
    //fight = fight.scaled(ui.playbutton->size(), Qt::KeepAspectRatio);
    //ui.playbutton->setIconSize(ui.playbutton->size());
    ui.playbutton->setIcon(fight);


    //ui.playbutton->setEnabled(false);
    connect(ui.playbutton, &QPushButton::clicked, this, [=]() {ui.stackedWidget->setCurrentIndex(0); });
    
    connect_all();
    display_whose_turn();
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
    return QIcon();
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
    if (clicked_figure != nullptr)
    {
        hide_possible_moves_for_figure(clicked_figure); // usuniêcie podœwietlenia poprzedniej figury
    }
    
    auto pos = game.get_final_moves_for_figure(figure);
    
    if (figure->get_type() == "K" && game.get_checking_figures().size() == 0)
    {
        auto castling = game.get_castling_positions();
        pos.insert(pos.end(), castling.begin(), castling.end());
    }
    for (auto it = pos.begin(); it != pos.end(); ++it)
    {
        auto cur_pos = *it;
        fields[cur_pos[0]][cur_pos[1]]->setStyleSheet("background-color: rgb(44, 163, 44); border: 1px solid black");
    }
    
    clicked_figure = figure;
    make_move();
}

void ChessGUIV3::disconnect_all()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            fields[i][j]->disconnect();   
        }
    }
}

void ChessGUIV3::connect_all()
{
    auto figures_to_connect = game.get_player().get_player_figures();
    for (auto itr = figures_to_connect.begin(); itr != figures_to_connect.end(); ++itr)
    {
        int x = (*itr)->get_position()[0];
        int y = (*itr)->get_position()[1];
        connect(fields[x][y], &QPushButton::clicked, this, [=]()
        {show_possible_moves_for_figure(game.get_board().get_figure(x, y));
        });
    }
}



void ChessGUIV3::hide_possible_moves_for_figure(Figure* figure)
{
    auto pos = game.get_board().get_free_positions_for_figure(figure);
    if (figure->get_type() == "K" && game.get_checking_figures().size() == 0)
    {
        auto castling = game.get_castling_positions();
        pos.insert(pos.end(), castling.begin(), castling.end());
    }
    for (auto it = pos.begin(); it != pos.end(); ++it)
    {
        auto cur_pos = *it;
        if (((cur_pos[0] % 2 == 0) && (cur_pos[1] % 2 == 0)) || ((cur_pos[0] % 2 == 1) && (cur_pos[1] % 2 == 1)))
        {
            fields[cur_pos[0]][cur_pos[1]]->setStyleSheet("background-color: rgb(230,213,166); border: none");
        }
        else
        {
            fields[cur_pos[0]][cur_pos[1]]->setStyleSheet("background-color: rgb(150,75,0); border: none;");
        }

    }
    disconnect_all();
    connect_all();

}

void ChessGUIV3::make_move()
{
    auto moves_to_choose = game.get_final_moves_for_figure(clicked_figure);
    if (clicked_figure->get_type() == "K" && game.get_checking_figures().size() == 0)
    {
        auto castling = game.get_castling_positions();
        moves_to_choose.insert(moves_to_choose.end(), castling.begin(), castling.end());

    }
    for (auto it = moves_to_choose.begin(); it != moves_to_choose.end(); ++it)
    {
        int x = (*it)[0];
        int y = (*it)[1];
        int x_clicked = clicked_figure->get_position()[0];
        int y_clicked = clicked_figure->get_position()[1];

        connect(fields[x][y], &QPushButton::clicked, this, [=]()
                    {fields[x][y]->setIcon(choose_figure(clicked_figure->get_type(), clicked_figure->get_color()));
                    Sleep(100);
                    fields[x_clicked][y_clicked]->setIcon(QIcon());
                    Sleep(100);
                    hide_possible_moves_for_figure(clicked_figure);
                    if (clicked_figure->get_type() == "K")
                    {
                        auto castling_tiles = game.get_castling_positions();
                        for (auto iter = castling_tiles.begin(); iter != castling_tiles.end(); ++iter)
                        {
                            if ((x == (*iter)[0]) && (y == (*iter)[1]))
                            {
                                auto rook_coords = game.do_castling(x, y);
                                Sleep(100);
                                fields[rook_coords[2]][rook_coords[3]]->setIcon(choose_figure("R", clicked_figure->get_color()));
                                fields[rook_coords[0]][rook_coords[1]]->setIcon(QIcon());
                                Sleep(100);
                            }
                        }
                    }
                    game.make_move(clicked_figure, x, y);
                    if (clicked_figure->get_type() == "P")
                    {
                        if (game.check_promote_pawn(clicked_figure) == true)
                        {
                            clicked_figure = game.get_board().get_figure(x, y);
                            Sleep(100);
                            fields[x][y]->setIcon(choose_figure("Q", clicked_figure->get_color()));
                            Sleep(100);
                        }
                    }
                    game.change_turn();
                    if (game.check_stalemate_condition())
                    {
                        ui.display_win->setText("PAT");
                        ui.stackedWidget->setCurrentIndex(2);
                    }
                    else if (game.check_win_condition())
                    {
                        if (game.get_current_player())
                            ui.display_win->setText("CZARNE WYGRYWAJA !!!!!!!");
                        else
                            ui.display_win->setText("BIALE WYGRYWAJA !!!!!!!!");
                        ui.stackedWidget->setCurrentIndex(2);


                    }
                    display_whose_turn();
                    disconnect_all();
                    current_turn();
                    });
    }

}

void ChessGUIV3::display_whose_turn()
{
    if (game.get_current_player() == 1)
    {
        ui.turn->setText("Tura Bialych");
    }
    else
    {
        ui.turn->setText("Tura Czarnych");
    }
}


void ChessGUIV3::current_turn()
{
    connect_all();
   // make_move();
    //if (game.get_current_player() == true) // jesli bialy ma ruch 
    //{   
    //    auto king = game.player_white().get_king();
    //    game.player_white().get_player_figures();
    //}
    //else
    //{

    //}
}
