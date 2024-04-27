#ifndef PIECE_H
#define PIECE_H


#include "color.h"
#include "piecetype.h"
#include "squarebox.h"
#include "movementspiece.h"
#include "maingui.h"

#include <vector>
#include <memory>

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QColor>

namespace chess_game { namespace logics{ class SquareBox;}}
namespace chess_game{ namespace logics{ class MovementsPiece;}}


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
            bool boxConfiguration(SquareBox* box);
            void setImage();

            bool isKing();
            bool isWhite();

            bool getIsInSquareBox();
            void setIsInSquareBox(bool boolean);

            void setInitialColorDisplacements();


            static int getCounterWhiteKings();
            static int getCounterBlackKings();

            void mousePressEvent(QGraphicsSceneMouseEvent* event);


            bool InitialMove;
            std::unique_ptr<MovementsPiece> movements;

            std::vector<SquareBox*> displacements;

        private:
            Color color_;
            PieceType pieceType_;

            bool isInSquareBox_;

            static int counterBlackKings_;
            static int counterWhiteKings_;

            SquareBox* box_;



        };
    }
}

#endif // PIECE_H
