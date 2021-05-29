#pragma once

#include "../GameEngine/Game.h"
#include <QtCore>
#include <QtGui>

#include <QGraphicsView>
#include <QtWidgets/QMainWindow>
#include "ui_ChessGUI.h"

class ChessGUI : public QMainWindow
{
    Q_OBJECT

public:
    ChessGUI(QWidget* parent = Q_NULLPTR);

private:
    Ui::ChessGUIClass ui;

    /*void set_figures();*/
    std::array<std::array <QGraphicsScene*, 8>, 8> fields;
    Game my_game;
};