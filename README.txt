Chess Game: Livrable 1 et TD6
Livrable 1:
This project aims to create a chess game interface using Qt, featuring a
chessboard and three pieces of each color: one king, one queen, and one knight.
Additionally, users have the capability to add several pieces onto the chessboard.

TD6:
1. Namespacing:
The project utilizes the following namespaces for organization:
chess_game for the overall chess game.
chess_game::logics for handling game logic.
chess_game::graphics for managing graphics-related functionalities throughout
the project.

2. King Instance Counter:
To ensure game integrity, there is a counter implemented for king instances.
If there are more than two kings on the board, an error is triggered. This
error is handled using a custom ChessGameException, which prompts a QMessageBox
to notify the user. The relevant files involved in this implementation are:
chessgameexception.h
piece.cpp
raii_initialposition.cpp
board.cpp

3. RAII Class for Initialization:
An RAII (Resource Acquisition Is Initialization) class is employed to handle the
initialization of pieces on the chessboard. This class ensures that the pieces are
correctly placed and managed during initialization. The relevant files for this feature are:
raii_initialposition.cpp
board.cpp

WARNING:
It is mandatory to utilize your own absolute directory for storing the chess piece images.
Ensure that the directory path is correctly configured to avoid any issues related to image
loading during runtime.
