#include "piece.h"

using namespace chess_game;
using namespace logics;

int Piece::counterBlackKings_ = 0;
int Piece::counterWhiteKings_ = 0;

Piece::Piece(Color colorPiece, PieceType typePiece, QGraphicsItem *graphicsItem): QGraphicsPixmapItem(graphicsItem) {
    color_ = colorPiece;
    pieceType_ = typePiece;
    isInSquareBox_ = true;
    setImage();

    if(isKing()){
        if(isWhite()){
            ++counterWhiteKings_;
        }
        else{
            ++counterBlackKings_;
        }
    }

}

Piece::~Piece(){
    if(isKing()){
        if(isWhite()){
            --counterWhiteKings_;
        }
        else{
            --counterBlackKings_;
        }
    }
}

int Piece::getCounterWhiteKings(){
    return counterWhiteKings_;
}

int Piece::getCounterBlackKings(){
    return counterBlackKings_;
}



Color Piece::getColor(){
    return color_;
}

PieceType Piece::getTypePiece(){
    return pieceType_;
}


SquareBox* Piece::getSquareBox(){
    return box_;
}

void Piece::setBox(SquareBox* box){
    box_ = box;
}

bool Piece::isWhite(){
    return color_.getColor() == ColorPiece::WHITE;
}

bool Piece::isKing(){
    return pieceType_.getType() == TypePiece::KING;
}


bool Piece::getIsInSquareBox(){
    return isInSquareBox_;

}

void Piece::setIsInSquareBox(bool boolean){
    isInSquareBox_ = boolean;

}

void Piece::setImage(){
    switch(color_.getColor()){
        case ColorPiece::BLACK:
            switch (pieceType_.getType()) {
                case TypePiece::KING:
                setPixmap(QPixmap("/Users/sergilenyouvop/INF1015/Projet-H24/image_piece_type/BLACK_KING.png"));
                    break;
                case TypePiece::QUEEN:
                    setPixmap(QPixmap("/Users/sergilenyouvop/INF1015/Projet-H24/image_piece_type/BLACK_QUEEN.png"));
                    break;
                case TypePiece::KNIGHT:
                    setPixmap(QPixmap("/Users/sergilenyouvop/INF1015/Projet-H24/image_piece_type/BLACK_KNIGHT.png"));
                    break;
                case TypePiece::NONE:
                    break;
            }
            break;
        case ColorPiece::WHITE:
            switch (pieceType_.getType()) {
                case TypePiece::KING:
                    setPixmap(QPixmap("/Users/sergilenyouvop/INF1015/Projet-H24/image_piece_type/WHITE_KING.png"));
                    break;
                case TypePiece::QUEEN:
                    setPixmap(QPixmap("/Users/sergilenyouvop/INF1015/Projet-H24/image_piece_type/WHITE_QUEEN.png"));
                    break;
                case TypePiece::KNIGHT:
                    setPixmap(QPixmap("/Users/sergilenyouvop/INF1015/Projet-H24/image_piece_type/WHITE_KNIGHT.png"));
                        break;
                case TypePiece::NONE:
                    break;
                }
            break;
        case ColorPiece::NONE:
            break;
    }
}



