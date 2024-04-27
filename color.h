#ifndef COLOR_H
#define COLOR_H


enum class ColorPiece {
    BLACK,
    WHITE,
    NONE

};

namespace chess_game {
    class Color
    {

    public:
        Color(ColorPiece color);
        Color();

        ColorPiece getColor();


    private:
        ColorPiece colorPiece_;
    };
}

#endif // COLOR_H

