#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qpushbutton.h>
#include <QEvent>
#include <array>
#include <QMouseEvent>
#include "ui_ChessGUIv2.h"
#include "../GameEngine/Game.h"

class ChessGUIv2 : public QMainWindow
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
    ChessGUIv2(QWidget *parent = Q_NULLPTR);

private:
    Ui::ChessGUIv2Class ui;
    std::array<std::array <QPushButton*, 8>, 8> fields;
    void eventFilter(QMouseEvent* event, QPushButton* button);
    //Game game;
    void handlebutton(QPushButton* button);

 
    
};

