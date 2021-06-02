#pragma once
#include <iostream>
#include "GraphicsView.h"
#include "../GameEngine/Game.h"
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets/QMainWindow>
#include "ui_ChessGUI.h"
#include <QMouseEvent>
#include <QPoint>

class ChessGUI : public QMainWindow
{
    Q_OBJECT

public:
    ChessGUI(QWidget* parent = Q_NULLPTR);

private:
    Ui::ChessGUIClass ui;

    /*void set_figures();*/
    std::array<std::array <QGraphicsScene*, 8>, 8> fields;
   // Game my_game;

    

    /*void mousePressEvent(QMouseEvent* event)
    {
        QPoint clickPos = event.pos();
        if (event->button() == Qt::LeftButton) {
            std::cout << "test";
        }
    }*/
};