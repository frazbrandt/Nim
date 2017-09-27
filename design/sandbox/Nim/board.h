/*
 * board.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Brandt Frazier
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>
#include <stdexcept>

#define MAXHEAPS 7
#define MINHEAPS 5

enum GameMode {NORMAL, MISERE};
enum PlayerTurn {PLAYER1, PLAYER2};
enum GameState {IN_PROGRESS, WIN_NORMAL, WIN_MISERE};

class Heap {
public:
	void removePawn();
	int getNumPawns();
	int getHeapNum();
	Heap(int _heapNum);
private:
	int heapNum;
	int numPawns;
};

class Board {
public:
	Heap *getHeap(int _heapNum);
	PlayerTurn getPlayerTurn();
	void nextTurn();
	int getNumPawns();
	int getNumHeaps();
	GameState getState();
	Board(int _numheaps, GameMode _mode, PlayerTurn _pturn);
private:
	GameMode mode;
	GameState state;
	PlayerTurn turn;
	std::vector<Heap> heaps;

};

#endif /* BOARD_H_ */
