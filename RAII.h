#include "color.h"
#include "piecetype.h"
#include "squarebox.h"
#include "piece.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QColor>
#include <QList>
#include <QString>
//using namespace chess_game;

class MouvmentRaii {

public:
	MouvmentRaii(chess_game::logics::Piece& piece, std::unique_ptr<chess_game::logics::SquareBox>& destination);
	~MouvmentRaii();

 private:
	chess_game::logics::Piece& piece_;
	std::unique_ptr<chess_game::logics::SquareBox>& destination_;




};
