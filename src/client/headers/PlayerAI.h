#ifndef PLAYERAI_H_
#define PLAYERAI_H_
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Rules.h"
using namespace std;
/*
 * An AI player that uses a minmax algorithm to choose its moves.
 */
class PlayerAI : public Player {
public:
	PlayerAI(Rules* rules, Board* board, int player_color);
	virtual ~PlayerAI();
	int GetMove(int* moves);
	int PrintActions();
	void AcknowledgeMove(int x, int y);
	int getColor();
private:
	Board* b;
	Rules* r;
	int color;
	int BestMoveScore(int* moves, Board* board, Rules* rules, int player);
};

#endif /* PLAYERAI_H_ */
