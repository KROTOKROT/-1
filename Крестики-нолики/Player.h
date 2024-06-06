#pragma once

#include "Board.h"

class Player {
public:
    virtual ~Player() {}
    virtual char getSymbol() const = 0;
    virtual void makeMove(Board& board) const = 0;
};
