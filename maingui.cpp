#include "maingui.h"

using namespace chess_game::graphics;
using namespace chess_game::logics;

MainGui::MainGui(QWidget* widget): QGraphicsView(widget) {
    scene_ = new QGraphicsScene();
    scene_->setSceneRect(0,0,1400,900);
    setFixedSize(1400,900);

    setScene(scene_);
    activePiece = nullptr;
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);

    turnDisplay_ = new QGraphicsTextItem();
    turnDisplay_->setPos(width()/2-100,10);
    turnDisplay_->setZValue(1);
    turnDisplay_->setDefaultTextColor(Qt::white);
    turnDisplay_->setFont(QFont("",18));
    turnDisplay_->setPlainText("Turn : WHITE");
}

void MainGui::drawBoard() {
    chessBoard_ = new Board();
    chessBoard_->addSquareBoxes(width()/2-400,50, this);
}


void MainGui::addElementScene(QGraphicsItem* graphicsItem) {
    scene_->addItem(graphicsItem);
}

void MainGui::removeElementScene(QGraphicsItem* graphicsItem) {
    scene_->removeItem(graphicsItem);
}

ColorPiece  MainGui::getTurn(){
    return turn_;
}

void MainGui::setTurn(ColorPiece turn){
    turn_ = turn;
}

void MainGui::changeTurn(){
    if(getTurn() == ColorPiece::WHITE){
        setTurn(ColorPiece::BLACK);
        turnDisplay_->setPlainText("Turn : BLACK");
    }
    else{
        setTurn(ColorPiece::WHITE);
        turnDisplay_->setPlainText("Turn : WHITE");
    }
}

void MainGui::startGame(){
    chessBoard_->addPieces(this);
}

void MainGui::restartGame(){
    activePieces.clear();
    chessBoard_->restartGame();
    setTurn(ColorPiece::WHITE);
}
