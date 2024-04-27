#include "color.h"

using namespace chess_game;

Color::Color(ColorPiece color) : colorPiece_(color) {}

Color::Color(){
    colorPiece_ = ColorPiece::NONE;
}

ColorPiece Color::getColor(){
    return colorPiece_;
}

