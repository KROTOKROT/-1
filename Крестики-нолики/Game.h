#pragma once

#include "Player.h"
#include "Board.h"
#include <string>

class Game {
public:
    Game(Player& human, Player& ai, Board& board);
    void start();
    std::string getWinner() const;
    int getNumMoves() const;
private:
    Board& board;
    Player& humanPlayer;
    Player& aiPlayer;
    std::string winner;
    int numMoves;
};