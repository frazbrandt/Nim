/*
 * player.cpp
 *
 *  Created on: Sep 26, 2017
 *      Author: Brandt Frazier
 */


#include "player.h"

Player::Player(Board *_game) {
	if (_game)
		Game = _game;
	else
		throw std::runtime_error("Couldn't find game instance.");
}

void Player::takeTurn(int _heapNum, int _numPawns) {
	if (_heapNum < 0 || _heapNum > Game->getNumHeaps())
		throw std::runtime_error("Bad heap number.");
	if (_numPawns < 0 || _numPawns > Game->getNumPawns())
		throw std::runtime_error("Bad number of pawns.");

	for (int i = 0; i < _numPawns; i++)
		Game->getHeap(_heapNum)->removePawn();
}
