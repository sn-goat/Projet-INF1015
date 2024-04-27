#include "piecetype.h"

using namespace chess_game;

PieceType::PieceType(TypePiece type) : typePiece_(type) {}

PieceType::PieceType() {
    typePiece_ = TypePiece::NONE;
}

TypePiece PieceType::getType() {
    return typePiece_;
}
