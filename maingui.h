#ifndef MAINGUI_H
#define MAINGUI_H

#include "piece.h"
#include "squarebox.h"
#include "board.h"

#include <vector>

#include <QGraphicsView>
#include <QGraphicsScene>

namespace chess_game{ namespace graphics {class Board;}}
namespace chess_game { namespace logics{ class SquareBox;}}
namespace chess_game{ namespace logics{ class Piece;}}

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
            std::vector<logics::Piece*> activePieces;

            logics::Piece* activePiece;

            ColorPiece  getTurn() ;
            void setTurn(ColorPiece turn);
            void changeTurn();

            void restartGame();
        public slots:
            void startGame();


        private:
            QGraphicsScene* scene_;
            Board* chessBoard_;
            std::vector<QGraphicsItem*> graphicsItems_;
            ColorPiece turn_;
            QGraphicsTextItem * turnDisplay_;
        };

    }
}

#endif // MAINGUI_H
