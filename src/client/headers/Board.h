#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
using namespace std;
#define BLACK 2
#define WHITE 1
/*
 *The board the game will be played on.
 */
class Board {
	public:
		Board* SimBoard();
		Board(int width, int height);
		virtual ~Board();
		void SetUpGame();
		int get(int x, int y);
		void set(int x, int y, int value);
		int getWidth();
		int getHeight();
	private:
		int** b;
		int width;
		int height;
};

#endif /* BOARD_H_ */
