#pragma once
#include <QtCore>
#include <QtGui>
#include <QGraphicsView>
#include <QtWidgets/QMainWindow>

class GraphicsView : public QGraphicsView
{
	void PressEvent(QMouseEvent* event)
	{
		this->PressEvent(event);

	}

};