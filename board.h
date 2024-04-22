#ifndef BOARD_H
#define BOARD_H

#include "raii_initialposition.h"
#include "squarebox.h"
#include "piece.h"
#include "chessgameexception.h"
#include "maingui.h"

#include <QGraphicsRectItem>
#include <QList>

namespace chess_game { namespace graphics {class MainGui;}}
namespace chess_game { namespace logics {class InitialPosition;}}


namespace chess_game{
    namespace graphics{
        class Board
        {


        public:
            Board();

            void setBoard(int x, int y, MainGui* mainGui);
            void addPieces(MainGui* mainGui);

            void initGame();
            void restartGame();
            void appendWhitePiecesToQList();
            void appendBlackPiecesToQList();

            void verificationKingsInstantiation();
            void addingBlackPiece(int index,MainGui* gui, logics::SquareBox* squareBox);
            void addingWhitePiece(int index,  MainGui* gui, logics::SquareBox* squareBox);


            const int ROW = 8;
            const int COL = 8;
            const int SQUARE_BOX_SIZE = 100;

        private:
            void deleteKings();
            void deleteBlackKings();
            void deleteWhiteKings();

            QList <logics::Piece*> whitePieces_;
            QList <logics::Piece*> blackPieces_;

            logics::InitialPosition* initialPosition_ = nullptr;

        };

    }

}


#endif // BOARD_H
