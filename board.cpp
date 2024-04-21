#include "board.h"

using namespace chess_game;
using namespace chess_game::graphics;
using namespace chess_game::logics;

Board::Board() {
    initGame();
}

void Board::setBoard(int x, int y, MainGui* mainGui){
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COL; ++j){
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

            mainGui->addToScene(squareBox);
        }
    }
}


void Board::appendWhitePiecesToQList(){
    Piece* piece;

    piece = new Piece(ColorPiece::WHITE, TypePiece::KNIGHT);
    whitePieces_.append(piece);

    piece = new Piece(ColorPiece::WHITE, TypePiece::QUEEN);
    whitePieces_.append(piece);

    piece = new Piece(ColorPiece::WHITE, TypePiece::KING);
    whitePieces_.append(piece);



}

void Board::appendBlackPiecesToQList(){
    Piece* piece;

    piece = new Piece(ColorPiece::BLACK, TypePiece::KNIGHT);
    blackPieces_.append(piece);

    piece = new Piece(ColorPiece::BLACK, TypePiece::QUEEN);
    blackPieces_.append(piece);

    piece = new Piece(ColorPiece::BLACK, TypePiece::KING);
    blackPieces_.append(piece);

}

void Board::verificationKingsInstantiation(){
    try
    {
        for(size_t i = 0; i < whitePieces_.size(); ++i){
            if(whitePieces_[i]->isKing()){
                if(whitePieces_[i]->getCounterWhiteKings() > 1){
                    throw TooManyKingsException();
                    break;
                }
            }
        }
        for(size_t j = 0; j < blackPieces_.size(); ++j){
            if(blackPieces_[j]->isKing()){
                if(blackPieces_[j]->getCounterBlackKings() > 1){
                    throw TooManyKingsException();
                    break;
                }
            }
        }
    }
    catch(TooManyKingsException& e){
        deleteKings();
        QMessageBox messageBox;

        messageBox.critical(0, "Error when adding a piece to the piece's QList", e.what());
    }

}

void Board::deleteWhiteKings(){
    Color color;
    PieceType pieceType;
    Piece piece(color, pieceType);

    size_t i = 0;
    while(i != (whitePieces_.size() - 1)){
        if(whitePieces_[i]->isKing()){
            whitePieces_.remove(i);
            if(piece.getCounterWhiteKings() < 2){
                break;
            }
        }
        else{
            ++i;
        }
    }
}

void Board::deleteBlackKings(){
    Color color;
    PieceType pieceType;
    Piece piece(color, pieceType);

    size_t i = 0;
    while(i != (blackPieces_.size() - 1)){
        if(blackPieces_[i]->isKing()){
            blackPieces_.remove(i);
            if(piece.getCounterBlackKings() < 2){
                break;
            }
        }
        else{
            ++i;
        }


    }
}

void Board::deleteKings(){
    deleteBlackKings();
    deleteWhiteKings();
}

void Board::addingBlackPiece(int index, MainGui* mainGui, SquareBox* squareBox){
    if(index > (blackPieces_.size() - 1)){
        throw PieceNoneExistingException();
        return;
    }
    squareBox->setPiece(blackPieces_[index]);
    mainGui->addToScene(blackPieces_[index]);

}

void Board::addingWhitePiece(int index, MainGui* mainGui, SquareBox* squareBox){
    if(index > (whitePieces_.size() - 1)){
        throw PieceNoneExistingException();
        return;
    }
    squareBox->setPiece(whitePieces_[index]);
    mainGui->addToScene(whitePieces_[index]);

}

void Board::addPieces(MainGui* mainGui){
    for(int i = 0; i < ROW; ++i) {
        for(int j = 0; j < COL; ++j){

            SquareBox *squareBox = mainGui->allSquareBoxes[i][j];
            try
            {
                if(i == 0 && j == 1) {
                    addingBlackPiece(0, mainGui, squareBox);
                }
                if(i == 0 && j == 7) {
                    addingBlackPiece(1, mainGui, squareBox);
                }
                if(i == 0 && j == 4) {
                    addingBlackPiece(2, mainGui, squareBox);
                }
                if(i == 7 && j == 2) {
                    addingWhitePiece(2, mainGui, squareBox);
                }
                if(i == 7 && j == 3) {
                    addingWhitePiece(1, mainGui, squareBox);
                }
                if(i == 7 && j == 4) {
                    addingWhitePiece(0, mainGui, squareBox);
                }
            }
            catch(PieceNoneExistingException& e){
                QMessageBox messageBox;
                messageBox.critical(0, "Error when adding a piece to the chess board", e.what());
            }


        }
    }
}

void Board::initGame(){
    appendWhitePiecesToQList();
    appendBlackPiecesToQList();
    verificationKingsInstantiation();
}





