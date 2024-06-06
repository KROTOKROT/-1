#pragma once

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(char symbol);
    char getSymbol() const override;
    void makeMove(Board& board) const override;
private:
    char symbol;
};
