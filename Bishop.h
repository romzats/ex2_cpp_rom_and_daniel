//
// Created by romzats on 1/16/17.
//

#ifndef EX2_BISHOP_H
#define EX2_BISHOP_H

#include "Chessmen.h"

/**
 *
 */
class Bishop : public ChessMen
{
    std::string _type = BISHOP;
public:
    /**
     * bishop constructor
     * @param location
     * @param color
     * @param arrPos
     */
    Bishop(std::string location, Color color, int arrPos);

    /**
     * getter
     * @return
     */
    virtual std::string getType();

    /**
     * bishop implementation of isMoveValid
     * @param move
     * @return
     */
    virtual bool isMoveValid(std::string move);

};

#endif //EX2_BISHOP_H
