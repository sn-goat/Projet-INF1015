#include "color.h"

using namespace chess_game;

Color::Color(ColorPiece color) : colorPiece_(color) {}

Color::Color(){
    colorPiece_ = ColorPiece::NONE;
}

ColorPiece Color::getColor(){
    return colorPiece_;
}

char* Color::toString(){
    switch (colorPiece_) {
        case ColorPiece::BLACK: return "BLACK";
        case ColorPiece::WHITE: return "WHITE";
        case ColorPiece::NONE: return "NONE";
            \
    }

}
