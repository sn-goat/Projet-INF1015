#ifndef CHESSGAMEEXCEPTION_H
#define CHESSGAMEEXCEPTION_H

#include <stdexcept>
#include <QMessageBox>

class ChessGameException : public std::logic_error {
public:
    ChessGameException(const std::string& message) : std::logic_error(message) {}
};

class TooManyKingsException : public ChessGameException {
public:
    TooManyKingsException() : ChessGameException("Too many kings instantiated!") {}
};

class PieceNonexistentException: public ChessGameException {
public:
    PieceNonexistentException() : ChessGameException("The piece(s) that you tried to add is/are nonexistent!") {}
};


#endif // CHESSGAMEEXCEPTION_H
