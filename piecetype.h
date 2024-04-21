#ifndef PIECETYPE_H
#define PIECETYPE_H


enum class TypePiece {
    KING,
    QUEEN,
    KNIGHT,
    NONE
};


namespace chess_game {
    class PieceType
    {
    public:
        PieceType(TypePiece typePiece);
        PieceType();

        TypePiece getType();

        char* toString();

    private:
        TypePiece typePiece_;
    };
}

#endif // PIECETYPE_H
