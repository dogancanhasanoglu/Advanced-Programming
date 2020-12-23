#include "hasanogludogan_hasanoglu_dogancan_board.h"
#include <iostream>
using namespace std;

Board::Board()   //constrcutor initializes to "-"
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<6;j++)
		{
			myboard[i][j] = '-';
		}
	
	}
}

void Board::displayBoard() const     // displays the board
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<myboard[i][j]<<" ";
		}
	cout<<endl;
	}

}

char Board::getOwner (int x, int y) const   // gets the owner of called cell
{
	return myboard[x][y];


}

void Board::setOwner (int x,int y, char ch)   //assings the cell to its new owner
{
	myboard[x][y]=ch;
}

bool Board::isFull () const   //checks whether the board is full or not
{   bool check=true;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(myboard[i][j] == '-')
				check=false;
		}
	}
	return check;
}

int Board::countOwnedCells (char ch) const    //counts the owned cells for the given character
{
	int count=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(myboard[i][j] == ch)
				count++;
		}
	}
	return count;

}