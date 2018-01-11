//
// Created by romzats on 1/16/17.
//

#ifndef EX2_KNIGHT_H
#define EX2_KNIGHT_H

#include "Chessmen.h"

/**
 *
 */
class Knight : public ChessMen
{
    std::string _type = KNIGHT;
    bool _firstMoveState = false;

public:
    /**
     * knight constructor
     * @param location
     * @param color
     * @param arrPos
     */
    Knight(std::string location, Color color, int arrPos);

    /**
     * getter
     * @return
     */
    virtual std::string getType();

    /**
     * knight implementation of isMoveValid
     * @param move
     * @return
     */
    virtual bool isMoveValid(std::string move);

};

#endif //EX2_KNIGHT_H
