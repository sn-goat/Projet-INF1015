#include "maingui.h"

using namespace chess_game::graphics;
using namespace chess_game::logics;

MainGui::MainGui(QWidget* widget): QGraphicsView(widget) {
    scene_ = new QGraphicsScene();
    scene_->setSceneRect(0,0,1400,900);
    setFixedSize(1400,900);

    setScene(scene_);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
}

void MainGui::drawBoard() {
    chessBoard_ = new Board();
    chessBoard_->setBoard(width()/2-400,50, this);
}


void MainGui::addElementScene(QGraphicsItem* graphicsItem) {
    scene_->addItem(graphicsItem);
}

void MainGui::removeElementScene(QGraphicsItem* graphicsItem) {
    scene_->removeItem(graphicsItem);
}

void MainGui::startGame(){
    chessBoard_->addPieces(this);
}

void MainGui::restartGame(){
    chessBoard_->restartGame();
}
