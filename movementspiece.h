#ifndef MOVEMENTSPIECE_H
#define MOVEMENTSPIECE_H

#include "piece.h"
#include "maingui.h"

#include <vector>

#include <QColor>

namespace chess_game { namespace graphics {class MainGui;}}
namespace chess_game{ namespace logics{ class Piece;}}

namespace chess_game {
    namespace logics {
        class MovementsPiece
        {
        public:
            MovementsPiece(Piece* piece);
            void moves(graphics::MainGui* mainGui);

        private:
            void movesKing(graphics::MainGui* mainGui);
            void findRiskyDisplacements(graphics::MainGui* mainGui);
            Piece* piece_;

        };
    }

}

#endif // MOVEMENTSPIECE_H
