#ifndef HASANOGLUDOGAN_HASANOGLU_DOGANCAN_BOARD_H
#define HASANOGLUDOGAN_HASANOGLU_DOGANCAN_BOARD_H
#include<iostream>
using namespace std;

class Board
{
public:
	Board();
	void displayBoard() const;
	char getOwner (int , int ) const;
	void setOwner (int ,int, char);
	bool isFull () const;
	int countOwnedCells (char) const;


private:
	char myboard [2][6];

};

#endif

