/*
 * board.cpp
 *
 *  Created on: Sep 26, 2017
 *      Author: Brandt Frazier
 */

#include "board.h"

// Heap
void Heap::removePawn() {
	numPawns--;
}

int Heap::getNumPawns() {
	return numPawns;
}

int Heap::getHeapNum() {
	return heapNum;
}

Heap::Heap(int _heapNum) {
	heapNum = _heapNum;
	numPawns = _heapNum;
}

// Board
Heap *Board::getHeap(int _heapNum) {
	if (_heapNum < 1 || _heapNum > getNumHeaps())
		throw std::runtime_error("Bad heap number.");

	return &heaps[getNumHeaps()-_heapNum];
}

PlayerTurn Board::getPlayerTurn() {
	return turn;
}

void Board::nextTurn() {
	turn = (turn == PLAYER1 ? PLAYER2 : PLAYER1);
}

int Board::getNumPawns() {
	int numPawns = 0;

	for (Heap h : heaps)
		numPawns += h.getNumPawns();

	return numPawns;
}

int Board::getNumHeaps() {
	return heaps.size();
}

GameState Board::getState() {
	if (mode == MISERE) {
		if (getNumPawns() == 1)
			state = WIN_MISERE;
	} else {
		if (getNumPawns() == 0)
			state = WIN_NORMAL;
	}

	return state;
}

Board::Board(int _numheaps, GameMode _mode, PlayerTurn _pturn) {
	if (_numheaps < MINHEAPS || _numheaps > MAXHEAPS)
		throw std::runtime_error("Bad number of heaps.");

	turn = (_pturn == PLAYER1 ? PLAYER2 : PLAYER1);
	mode = _mode;
	state = IN_PROGRESS;

	for (int i = _numheaps; i > 0; i--) {
		heaps.push_back(Heap(i));
	}
}
