#include "board.h"

using namespace chess_game;
using namespace chess_game::graphics;
using namespace chess_game::logics;

Board::Board() {
    initGame();
}

void Board::addSquareBoxes(int x, int y, MainGui* mainGui){
    for(int i = 0; i < NLINES; ++i){
        for(int j = 0; j < NCOLUMNS; ++j){
            SquareBox* squareBox = new SquareBox();

            mainGui->allSquareBoxes[i][j] = squareBox;
            squareBox->setRow(i);
            squareBox->setColumn(j);
            squareBox->setPos(x + SQUARE_BOX_SIZE*j,y + SQUARE_BOX_SIZE*i);


            if( (i+j) % 2 == 0){
                squareBox->setColor(QColorConstants::Svg::beige);
            }
            else{
                squareBox->setColor(QColorConstants::Svg::darkgreen);
            }

            mainGui->addElementScene(squareBox);
        }
    }
}


void Board::appendToWhitePieces(){
    Piece* piece;


    piece = new Piece(ColorPiece::WHITE, TypePiece::KING);
    whitePieces_.push_back(piece);


}

void Board::appendToBlackPieces(){
    Piece* piece;

    piece = new Piece(ColorPiece::BLACK, TypePiece::KING);
    blackPieces_.push_back(piece);


}

void Board::verificationKingsInstantiation(){
    try
    {
        for(size_t i = 0; i < whitePieces_.size(); ++i){
            if(whitePieces_[i]->isKing()){
                if(whitePieces_[i]->getCounterWhiteKings() > 1){
                    deleteWhiteKings();
                    throw TooManyKingsException();
                    break;
                }
            }
        }
        for(size_t j = 0; j < blackPieces_.size(); ++j){
            if(blackPieces_[j]->isKing()){
                if(blackPieces_[j]->getCounterBlackKings() > 1){
                    deleteBlackKings();
                    throw TooManyKingsException();
                    break;
                }
            }
        }
    }
    catch(TooManyKingsException& e){
        QMessageBox messageBox;
        messageBox.critical(0, "Error when adding a piece to the piece's QList", e.what());
    }

}

void Board::deleteWhiteKings(){
    Color color;
    PieceType pieceType;
    Piece piece(color, pieceType);

    int kingsRemoved = 0;
    int counter = piece.getCounterWhiteKings() - 1;

    for(auto it = whitePieces_.begin(); it != whitePieces_.end();){
        if((*it)->isKing()){
            it = whitePieces_.erase(it);
            ++kingsRemoved;
            if(kingsRemoved == counter){
                break;
            }
        }
        else{
            ++it;
        }
    }

}

void Board::deleteBlackKings(){
    Color color;
    PieceType pieceType;
    Piece piece(color, pieceType);

    int kingsRemoved = 0;
    int counter = piece.getCounterBlackKings() - 1;

    for(auto it = blackPieces_.begin(); it != blackPieces_.end();){
        if((*it)->isKing()){
            it = blackPieces_.erase(it);
            ++kingsRemoved;
            if(kingsRemoved == counter){
                break;
            }
        }
        else{
            ++it;
        }
    }
}


void Board::addingBlackPiece(int index, MainGui* mainGui, SquareBox* squareBox){
    if(index > (blackPieces_.size() - 1)){
        throw PieceNonexistentException();
        return;
    }
    squareBox->setPiece(blackPieces_[index]);
    mainGui->addElementScene(blackPieces_[index]);

}

void Board::addingWhitePiece(int index, MainGui* mainGui, SquareBox* squareBox){
    if(index > (whitePieces_.size() - 1)){
        throw PieceNonexistentException();
        return;
    }
    squareBox->setPiece(whitePieces_[index]);
    mainGui->addElementScene(whitePieces_[index]);

}

void Board::addPieces(MainGui* mainGui){
    initialPosition_ = new InitialPosition(mainGui, this);
}

void Board::restartGame(){
    delete initialPosition_;
}

void Board::initGame(){
    appendToWhitePieces();
    appendToBlackPieces();
    verificationKingsInstantiation();
}





