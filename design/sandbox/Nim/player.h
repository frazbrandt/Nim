/*
 * player.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Brandt Frazier
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "board.h"

//class Board;	// forward declaration

class Player {
public:
	void takeTurn(int _heapNum, int _numPawns);
	Player(Board *_game);
private:
	Board *Game;
};

#endif /* PLAYER_H_ */
