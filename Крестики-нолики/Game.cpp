#include "Game.h"
#include <iostream>

Game::Game(Player& human, Player& ai, Board& board)
    : humanPlayer(human), aiPlayer(ai), board(board), winner(""), numMoves(0) {}

std::string Game::getWinner() const {
    return winner;
}

int Game::getNumMoves() const {
    return numMoves;
}

void Game::start() {
    Player* currentPlayer = (humanPlayer.getSymbol() == 'X') ? &humanPlayer : &aiPlayer; 
    while (!board.isFull() && board.getWinner() == ' ') {
        board.print();
        std::cout << std::endl;
        currentPlayer->makeMove(board);
        currentPlayer = (currentPlayer == &humanPlayer) ? &aiPlayer : &humanPlayer; 
    }
    char winner = board.getWinner();
    if (winner != ' ') {
        std::cout << "Победил игрок с символом: " << winner << std::endl;
    }
    else {
        std::cout << "Ничья" << std::endl;
    }
}