//
// Created by romzats on 1/5/17.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "Board.h"

#define CHECK "\33[37;41mCheck!\33[0m"

/**
 * Chess class
 */
class chess
{

private:
    Board *board;

public:
    /**
    * ctor
    * @return
    */
    chess();

    /**
    * dtor
    */
    ~chess();

    /**
    * getter
    * @return
    */
    Board *getBoard();

};

#endif //EX2_PLAYER_H
