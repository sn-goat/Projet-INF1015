#include "piecetype.h"

using namespace chess_game;

PieceType::PieceType(TypePiece type) : typePiece_(type) {}

PieceType::PieceType() {
    typePiece_ = TypePiece::NONE;
}
char* PieceType::toString(){
    switch (typePiece_) {
        case TypePiece::KING: return "King";
        case TypePiece::QUEEN: return "Queen";
        case TypePiece::KNIGHT: return "Knight";
        case TypePiece::NONE: return "NONE";
        \
    }
}

TypePiece PieceType::getType() {
    return typePiece_;
}
