#ifndef PIECE_H
#define PIECE_H


#include "color.h"
#include "piecetype.h"
#include "squarebox.h"


#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QColor>
#include <QList>
#include <QString>

namespace chess_game { namespace logics{ class SquareBox;}}

namespace chess_game {
    namespace logics{
        class Piece: public QGraphicsPixmapItem
        {
        public:
            Piece(Color colorPiece, PieceType typePiece, QGraphicsItem* graphicsItem = 0);

            ~Piece();

            Color getColor();
            PieceType getTypePiece();

            SquareBox* getSquareBox();
            void setBox(SquareBox* box);



            bool isKing();
            bool isWhite();


            bool getIsInSquareBox();
            void setIsInSquareBox(bool boolean);

            void setImage();

            static int getCounterWhiteKings();
            static int getCounterBlackKings();


        private:
            Color color_;
            PieceType pieceType_;

            bool isInSquareBox_;

            static int counterBlackKings_;
            static int counterWhiteKings_;

            bool firstMove_;

            SquareBox* box_;
            QList<SquareBox*> displacements_;


        };
    }
}

#endif // PIECE_H
