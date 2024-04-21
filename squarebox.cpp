#include "squarebox.h"

using namespace chess_game::logics;

SquareBox::SquareBox(QGraphicsItem* graphicsItem): QGraphicsRectItem(graphicsItem){
    piece_ = nullptr;
    isOccupied_ = false;

    setRect(0,0,100,100);
    brush_.setStyle(Qt::SolidPattern);
    setZValue(-1);
}

void SquareBox::setIsOccupied(bool boolean){
    isOccupied_ = boolean;
}


bool SquareBox::isOccupied() {
    return isOccupied_;
}

void SquareBox::resetBox(){
    piece_ = nullptr;
    isOccupied_ = false;
}

void SquareBox::setPiece(Piece* piece){
    piece->setPos(x()+50- piece->pixmap().width()/2  ,y()+50-piece->pixmap().width()/2);
    piece->setBox(this);
    isOccupied_ = true;
    piece_ = piece;
}

Piece* SquareBox::getPiece(){
    return piece_;
}

void SquareBox::setBrushColor(QColor color){
    brush_.setColor(color);
    setBrush(brush_);
}

void SquareBox::setColor(QColor color){
    intialColor_ = color;
    setBrushColor(color);
}

int SquareBox::getRow(){
    return row_;
}

int SquareBox::getColunm(){
    return column_;
}

void SquareBox::setRow(int row){
    row_ = row;
}

void SquareBox::setColumn(int column){
    column_ = column;
}

