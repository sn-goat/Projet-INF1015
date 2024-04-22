#ifndef SQUAREBOX_H
#define SQUAREBOX_H

#include "piece.h"

#include <QBrush>
#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

namespace chess_game{ namespace logics{ class Piece;}}

namespace chess_game{
    namespace logics{
        class SquareBox: public QGraphicsRectItem
        {
        public:
            SquareBox(QGraphicsItem* graphicsItem = 0);


            void setColor(QColor color);
            void setBrushColor(QColor color);

            Piece* getPiece();
            void setPiece(Piece* piece);

            bool isOccupied();
            void setIsOccupied(bool boolean);

            void resetBox();

            int getRow();
            void setRow(int row);

            int getColunm();
            void setColumn(int column);

        private:
            logics::Piece* piece_;
            bool isOccupied_;

            QBrush brush_;
            QColor intialColor_;

            int row_;
            int column_;




        };
    }
}

#endif // SQUAREBOX_H
