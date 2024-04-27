#include "squarebox.h"

using namespace chess_game;
using namespace logics;
using namespace graphics;

extern MainGui* mainGui;

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

void SquareBox::setInitialColor(){
    setBrushColor(intialColor_);
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
void SquareBox::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(piece_ == mainGui->activePiece && piece_){
        piece_->mousePressEvent(event);
        return;
    }
    if(mainGui->activePiece){
        if(this->piece_->getColor().getColor() == mainGui->activePiece->getColor().getColor()){
            return;
        }
        std::vector<SquareBox*> changeDistinations = mainGui->activePiece->displacements;

        int nTimes;
        for(int i = 0; i < changeDistinations.size(); ++i){
            if(changeDistinations[i] == this){
                ++nTimes;
            }
        }
        if(nTimes){
            return;
        }
        mainGui->activePiece->setInitialColorDisplacements();
        mainGui->activePiece->InitialMove = false;

        if(this->isOccupied()){
            this->piece_->setIsInSquareBox(false);
            this->piece_->setBox(nullptr);

        }
        mainGui->activePiece->getSquareBox()->setIsOccupied(false);
        mainGui->activePiece->getSquareBox()->piece_ = nullptr;
        mainGui->activePiece->getSquareBox()->setInitialColor();
        setPiece(mainGui->activePiece);

        mainGui->activePiece = nullptr;
        mainGui->changeTurn();
    }
    else if(this->isOccupied())
    {
        this->getPiece()->mousePressEvent(event);
    }

}

