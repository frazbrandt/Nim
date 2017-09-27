/*
 * main.cpp
 *
 *  Created on: Sep 26, 2017
 *      Author: Brandt Frazier
 */

#include <iostream>
#include <cstdio>
#include <string>

#include "board.h"
#include "player.h"

void draw_frame(Board *Game, std::string message, std::string prompt);

int main()
{
	try {
		GameMode mode;
		PlayerTurn first_turn;
		int selection, numheaps;

		std::string message("[1] Misere [2] Normal");
		std::string prompt("Select game mode [1-2]: ");
		draw_frame(nullptr, message, prompt);
		std::cin >> selection;
		if (selection == 1)
			mode = MISERE;
		else if (selection == 2)
			mode = NORMAL;
		else
			throw std::runtime_error("Bad selection.");

		message = "[1] Player 1 (human) vs Player 2 (human)\n[2] Player 1 (human) vs Player 2 (AI)";
		prompt = "Select opponent [1-2]: ";
		draw_frame(nullptr, message, prompt);
		std::cin >> selection;
		// TODO: Add AI controller and play mode

		message = " ";
		prompt = "Set number of heaps [";
		prompt += std::to_string(MINHEAPS);
		prompt += "-";
		prompt += std::to_string(MAXHEAPS);
		prompt += "]: ";
		draw_frame(nullptr, message, prompt);
		std::cin >> numheaps;
		if (numheaps < MINHEAPS || numheaps > MAXHEAPS)
			throw std::runtime_error("Bad number of heaps.");

		message = "Player [1] or Player [2]";
		prompt = "Who takes the first turn [1-2]: ";
		draw_frame(nullptr, message, prompt);
		std::cin >> selection;
		if (selection == 1)
			first_turn = PLAYER1;
		else if (selection == 2)
			first_turn = PLAYER2;
		else
			throw std::runtime_error("Bad player number.");

		Board Game(numheaps, mode, first_turn);
		Player Player1(&Game);
		Player Player2(&Game);

		prompt = " ";
		message = " ";
		int heapSelected, numPawnsSelected;
		while (Game.getState() == IN_PROGRESS) {
			Game.nextTurn();

			prompt = (Game.getPlayerTurn() == PLAYER1 ? "Player 1" : "Player 2");
			prompt += ", Select Heap [1-";
			prompt += std::to_string(Game.getNumHeaps());
			prompt += "]: ";
			draw_frame(&Game, message, prompt);
			std::cin >> heapSelected;

			message = (Game.getPlayerTurn() == PLAYER1 ? "Player 1" : "Player 2");
			message += " selected Heap #";
			message += std::to_string(heapSelected);

			prompt = (Game.getPlayerTurn() == PLAYER1 ? "Player 1" : "Player 2");
			prompt += ", enter number of pawns to remove [1-";
			prompt += std::to_string(Game.getHeap(heapSelected)->getNumPawns());
			prompt += "]: ";
			draw_frame(&Game, message, prompt);
			std::cin >> numPawnsSelected;

			Game.getPlayerTurn() == PLAYER1 ? Player1.takeTurn(heapSelected, numPawnsSelected) : Player2.takeTurn(heapSelected, numPawnsSelected);

			message = (Game.getPlayerTurn() == PLAYER1 ? "Player 1" : "Player 2");
			message += " removed ";
			message += std::to_string(numPawnsSelected);
			message += " pawns from Heap #";
			message += std::to_string(heapSelected);


		}

		prompt = (Game.getPlayerTurn() == PLAYER1 ? "Player 1" : "Player 2");
		prompt += " wins a game of Nim!";
		draw_frame(&Game, message, prompt);
		std::cout << std::endl;

	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}

void draw_frame(Board *Game, std::string message, std::string prompt)
{
	system("clear");
	std::cout << "A Game of Nim" << std::endl;
	std::cout << std::endl;
	if (Game) {
		for (int i = 1; i <= Game->getNumHeaps(); i++) {
			std::cout << "[" << i << "] ";
			for (int j = Game->getNumHeaps() - i; j > 0; j--)
				std::cout << " ";
			for (int j = 0; j < Game->getHeap(i)->getNumPawns(); j++)
				std::cout << "* ";
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << message << std::endl;
	std::cout << prompt;


}
