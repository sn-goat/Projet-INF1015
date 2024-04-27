#ifndef BOARD_H
#define BOARD_H

#include "raii_initialposition.h"
#include "squarebox.h"
#include "piece.h"
#include "chessgameexception.h"
#include "maingui.h"

#include <vector>

#include <QGraphicsRectItem>
#include <QList>

namespace chess_game { namespace graphics {class MainGui;}}
namespace chess_game { namespace logics {class InitialPosition;}}
namespace chess_game { namespace logics{ class SquareBox;}}
namespace chess_game{ namespace logics{ class Piece;}}

namespace chess_game{
    namespace graphics{
        class Board
        {


        public:
            Board();

            void addSquareBoxes(int x, int y, MainGui* mainGui);
            void addPieces(MainGui* mainGui);

            void initGame();
            void restartGame();
            void appendToWhitePieces();
            void appendToBlackPieces();

            void verificationKingsInstantiation();
            void addingBlackPiece(int index,MainGui* MainGui, logics::SquareBox* squareBox);
            void addingWhitePiece(int index,  MainGui* MainGui, logics::SquareBox* squareBox);


            const int NLINES = 8;
            const int NCOLUMNS = 8;
            const int SQUARE_BOX_SIZE = 100;

        private:
            void deleteBlackKings();
            void deleteWhiteKings();

            std::vector<logics::Piece*> whitePieces_;
            std::vector<logics::Piece*> blackPieces_;

            logics::InitialPosition* initialPosition_ = nullptr;

        };

    }

}


#endif // BOARD_H
