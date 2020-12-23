#include "hasanogludogan_hasanoglu_dogancan_board.h"
#include "hasanogludogan_hasanoglu_dogancan_player.h"
#include <iostream>
using namespace std;

/**********************************************/
//All basic functions except the one which is move

Player::Player(Board &b, char ch, int x)   // initializes the character with coordinate (0,0)
	: board(b),coorx(0),coory(0),direction(x),id(ch)    //sets its direction, shares the board with reference
{}




void Player::move (int dice)   // I used a different approach which can be considered as a mathematical one
{                              // for loop could also be implemented but its runtime would be large 
	if(direction==1)           // this algorithm utilizes the modulus and it is based on the incrementation of column
	{                          // it increments the coory and then take modulus and sets the coorx and its direction according to that
		if(coorx==0)           // also I used abs() method because as long as you reduce the coory it cycles back to beginning, I made use of it
		{   coory=coory+dice;
			if (coory<=5)
			{   coorx=0;}
			else
			{	coorx=1;
				coory= 5 - (coory % 6);
			}
		}
		else if(coorx==1)
		{   coory=coory-dice;
			if (coory>=0)
			{   coorx=1;}
			else
			{
				coorx=0;
				coory=abs(coory)-1;
			}
		}
	}
	else
	{
		if(coorx==0)
		{   coory=coory-dice;
		    if (coory>=0)
			{coorx=0;}
			else
			{
				coorx=1;
				coory=abs(coory)-1;
			}
		}
		else if(coorx==1)
		{
			coory=coory+dice;
			if (coory<=5)
			{coorx=1;}
			else
			{coorx=0;
			coory=5 - (coory % 6);
			}
		}
	}
}
void Player::claimOwnership()  // if cell is vacant it sets the cell for owner
{
	if(board.getOwner(coorx,coory)=='-')
		board.setOwner(coorx,coory,id);
}
bool Player::wins()   // if any character gets to have more than 6 cells then it wins
{
	int count=board.countOwnedCells(id);
	if(count>6)
		return true;
	else 
		return false;
}
int Player:: getRow()
{
	return coorx;
}	
int Player::getCol()
{
	return coory;
}