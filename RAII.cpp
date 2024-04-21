#include "RAII.h"
#include <iostream>
using namespace std;

MouvmentRaii::MouvmentRaii(Piece& piece, std::unique_ptr<chess_game::logics::SquareBox>& destination) : piece_(piece), destination_(destination) {

}


MouvmentRaii::~MouvmentRaii() {
	piece_.mort = true;
	destination_->piece_ = nullptr;
	cout << "L'objet est détruit" << endl;
}
