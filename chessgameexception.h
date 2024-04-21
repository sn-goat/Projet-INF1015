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

class PieceNoneExistingException : public ChessGameException {
public:
    PieceNoneExistingException() : ChessGameException("The piece(s) that you tried to add is nonexistent!") {}
};


#endif // CHESSGAMEEXCEPTION_H
