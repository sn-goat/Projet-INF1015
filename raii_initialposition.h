#ifndef RAII_INITIALPOSITION_H
#define RAII_INITIALPOSITION_H

#include "board.h"
#include "squarebox.h"
#include "chessgameexception.h"
#include "maingui.h"
#include "chessgameexception.h"

namespace chess_game { namespace graphics {class MainGui;}}
namespace chess_game{ namespace graphics {class Board;}}

namespace chess_game {
    namespace logics {
        class InitialPosition
        {
        public:
            InitialPosition(graphics::MainGui* mainGui, graphics::Board* board );
            ~InitialPosition();
        private:
            graphics::MainGui* mainGui_;
            graphics::Board* board_;
        };
    }

}


#endif // RAII_INITIALPOSITION_H
