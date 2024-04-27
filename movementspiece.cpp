#include "movementspiece.h"

using namespace chess_game;
using namespace logics;
using namespace graphics;

MovementsPiece::MovementsPiece(Piece* piece) {
    piece_ = piece;
}


void MovementsPiece::movesKing(MainGui* mainGui){

    piece_->displacements.clear();

    const int row = piece_->getSquareBox()->getRow();
    const int col = piece_->getSquareBox()->getColunm();
    ColorPiece teamColor = piece_->getColor().getColor();

    if((col > 0) && (row > 0) && !(mainGui->allSquareBoxes[row-1][col-1]->getPiece()->getColor().getColor() == teamColor)) {
        piece_->displacements.push_back(mainGui->allSquareBoxes[row-1][col-1]);
        mainGui->allSquareBoxes[row-1][col-1]->setBrushColor(Qt::darkRed);
        if(piece_->displacements[0]->isOccupied()){
            piece_->displacements[0]->setBrushColor(Qt::red);
        }
    }
    if((col < 7) && (row > 0) && !(mainGui->allSquareBoxes[row-1][col+1]->getPiece()->getColor().getColor() == teamColor)) {
        piece_->displacements.push_back(mainGui->allSquareBoxes[row-1][col-1]);
        mainGui->allSquareBoxes[row-1][col+1]->setBrushColor(Qt::darkRed);
        if(piece_->displacements[0]->isOccupied()){
            piece_->displacements[0]->setBrushColor(Qt::red);
        }
    }
    if((row > 0) && !(mainGui->allSquareBoxes[row-1][col]->getPiece()->getColor().getColor() == teamColor)) {
        piece_->displacements.push_back(mainGui->allSquareBoxes[row-1][col]);
        mainGui->allSquareBoxes[row-1][col]->setBrushColor(Qt::darkRed);
        if(piece_->displacements[0]->isOccupied()){
            piece_->displacements[0]->setBrushColor(Qt::red);
        }
    }
    if((row < 7) && !(mainGui->allSquareBoxes[row+1][col]->getPiece()->getColor().getColor() == teamColor)) {
        piece_->displacements.push_back(mainGui->allSquareBoxes[row+1][col]);
        mainGui->allSquareBoxes[row+1][col]->setBrushColor(Qt::darkRed);
        if(piece_->displacements[0]->isOccupied()){
            piece_->displacements[0]->setBrushColor(Qt::red);
        }
    }
    if((col < 7) && !(mainGui->allSquareBoxes[row][col+1]->getPiece()->getColor().getColor() == teamColor)) {
        piece_->displacements.push_back(mainGui->allSquareBoxes[row][col+1]);
        mainGui->allSquareBoxes[row][col+1]->setBrushColor(Qt::darkRed);
        if(piece_->displacements[0]->isOccupied()){
            piece_->displacements[0]->setBrushColor(Qt::red);
        }
    }
    if((col > 0) && (row < 7) && !(mainGui->allSquareBoxes[row+1][col-1]->getPiece()->getColor().getColor() == teamColor)) {
        piece_->displacements.push_back(mainGui->allSquareBoxes[row+1][col-1]);
        mainGui->allSquareBoxes[row+1][col-1]->setBrushColor(Qt::darkRed);
        if(piece_->displacements[0]->isOccupied()){
            piece_->displacements[0]->setBrushColor(Qt::red);
        }
    }
    if((col < 7) && (row < 7) && !(mainGui->allSquareBoxes[row+1][col+1]->getPiece()->getColor().getColor() == teamColor)) {
        piece_->displacements.push_back(mainGui->allSquareBoxes[row+1][col+1]);
        mainGui->allSquareBoxes[row+1][col+1]->setBrushColor(Qt::darkRed);
        if(piece_->displacements[0]->isOccupied()){
            piece_->displacements[0]->setBrushColor(Qt::red);
        }
    }
    findRiskyDisplacements(mainGui);

}

void MovementsPiece::findRiskyDisplacements(MainGui* mainGui){

    std::vector<Piece*> alivePiece = mainGui->activePieces;

    for(int i = 0; i < alivePiece.size(); ++i){
        if(alivePiece[i]->getColor().getColor() != piece_->getColor().getColor()){

            std::vector<SquareBox*> disPlacementsPieces = alivePiece[i]->displacements;

            for(int j = 0; j < disPlacementsPieces.size(); ++j ){
                for(int k = 0; k < piece_->displacements.size(); k++) {
                    if(disPlacementsPieces[j] == piece_->displacements[k]) {
                        piece_->displacements[k]->setBrushColor(Qt::blue);
                    }
                }

            }
        }
    }

}

void MovementsPiece::moves(MainGui* mainGui){
    switch (piece_->getTypePiece().getType()) {
        case TypePiece::KING:
            movesKing(mainGui);
            break;
        case TypePiece::QUEEN:
            break;
        case TypePiece::KNIGHT:
            break;
        case TypePiece::NONE:
            break;
    }
}


