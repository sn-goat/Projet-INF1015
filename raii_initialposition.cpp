#include "raii_initialposition.h"

using namespace chess_game;
using namespace chess_game::graphics;
using namespace chess_game::logics;


InitialPosition::InitialPosition(MainGui* mainGui, Board* board) {
    mainGui_ = mainGui;
    board_ = board;
    for(int i = 0; i < board->ROW; ++i) {
        for(int j = 0; j < board->COL; ++j){

            SquareBox *squareBox = mainGui->allSquareBoxes[i][j];
            try
            {
                if(i == 0 && j == 1) {
                    board->addingBlackPiece(0, mainGui, squareBox);
                }
                if(i == 0 && j == 7) {
                    board->addingBlackPiece(1, mainGui, squareBox);
                }
                if(i == 0 && j == 4) {
                    board->addingBlackPiece(2, mainGui, squareBox);
                }
                if(i == 7 && j == 2) {
                    board->addingWhitePiece(0, mainGui, squareBox);
                }
                if(i == 7 && j == 3) {
                    board->addingWhitePiece(2, mainGui, squareBox);
                }
                if(i == 7 && j == 4) {
                    board->addingWhitePiece(1, mainGui, squareBox);
                }
            }
            catch(PieceNonexistentException& e){
                QMessageBox messageBox;
                messageBox.critical(0, "Error when adding a piece to the chess board", e.what());
            }


        }
    }
}

InitialPosition::~InitialPosition(){
    for(int i = 0; i < board_->ROW; ++i) {
        for(int j = 0; j < board_->COL; ++j){

            SquareBox* squareBox = mainGui_->allSquareBoxes[i][j];
            squareBox->resetBox();

            try
            {
                if(i == 0 && j == 1) {
                    board_->addingBlackPiece(0, mainGui_, squareBox);
                }
                if(i == 0 && j == 7) {
                    board_->addingBlackPiece(1, mainGui_, squareBox);
                }
                if(i == 0 && j == 4) {
                    board_->addingBlackPiece(2, mainGui_, squareBox);
                }
                if(i == 7 && j == 2) {
                    board_->addingWhitePiece(0, mainGui_, squareBox);
                }
                if(i == 7 && j == 3) {
                    board_->addingWhitePiece(2, mainGui_, squareBox);
                }
                if(i == 7 && j == 4) {
                    board_->addingWhitePiece(1, mainGui_, squareBox);
                }
            }
            catch(PieceNonexistentException& e){
                QMessageBox messageBox;
                messageBox.critical(0, "Error when adding a piece to the chess board", e.what());
            }


        }
    }
}
