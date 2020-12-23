#ifndef HASANOGLUDOGAN_HASANOGLU_DOGANCAN_PLAYER_H
#define HASANOGLUDOGAN_HASANOGLU_DOGANCAN_PLAYER_H

#include "hasanogludogan_hasanoglu_dogancan_board.h"
using namespace std;

class Player
{
private:
	Board & board;
	char id;
	int coorx;
	int coory;
	int direction;

public:
	Player(Board & b, char ch, int x) ;
	void move (int);
	void claimOwnership();
	bool wins();
	int getRow();
	int getCol();

};


#endif
