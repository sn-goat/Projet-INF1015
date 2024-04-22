#ifndef MAINGUI_H
#define MAINGUI_H

#include "piece.h"
#include "squarebox.h"
#include "board.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QList>

namespace chess_game{ namespace graphics {class Board;}}

namespace chess_game{
    namespace graphics {
        class MainGui : public QGraphicsView
        {
            Q_OBJECT
        public:

            MainGui(QWidget* widget = 0);

            void drawBoard();
            void addElementScene(QGraphicsItem* graphicsItem);
            void removeElementScene(QGraphicsItem *graphicsItem);

            logics::SquareBox* allSquareBoxes[8][8];

            void restartGame();
        public slots:
            void startGame();


        private:
            QGraphicsScene* scene_;
            Board* chessBoard_;
            QList <QGraphicsItem*> graphicsItems_;
        };

    }
}

#endif // MAINGUI_H
