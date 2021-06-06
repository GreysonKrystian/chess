#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qpushbutton.h>
#include <QEvent>
#include <array>
#include <QMouseEvent>
#include <QtWidgets/QMainWindow>
#include "ui_ChessGUIV3.h"
#include "../GameEngine/Game.h"
#include <Windows.h>

class ChessGUIV3 : public QMainWindow
{
    Q_OBJECT

public:
    QIcon WRook;
    QIcon WBishop;
    QIcon WKnight;
    QIcon WKing;
    QIcon WPawn;
    QIcon WQueen;
    QIcon BRook;
    QIcon BBishop;
    QIcon BKnight;
    QIcon BKing;
    QIcon BPawn;
    QIcon BQueen;
    ChessGUIV3(QWidget* parent = Q_NULLPTR);
    void setup_figures();
    void current_turn();

   
private:
    Ui::ChessGUIV3Class ui;
    std::array<std::array <QPushButton*, 8>, 8> fields;
    Game game;
    Figure* clicked_figure = nullptr;
    QIcon choose_figure(std::string figure_type, int color);
    void show_possible_moves_for_figure(Figure* figure);
    void hide_possible_moves_for_figure(Figure* figure);
    void make_move();
    void disconnect_all();
    void connect_all();
    void display_whose_turn();
};
