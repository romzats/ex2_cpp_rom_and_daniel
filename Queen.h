//
// Created by romzats on 1/16/17.
//

#ifndef EX2_QUEEN_H
#define EX2_QUEEN_H

#include "Chessmen.h"

/**
 *
 */
class Queen : public ChessMen
{
    std::string _type = QUEEN;
public:
    /**
     * queen constructor
     * @param location
     * @param color
     * @param arrPos
     */
    Queen(std::string location, Color color, int arrPos);

    /**
     * getter
     * @return
     */
    virtual std::string getType();

    /**
     * queen implementation of isMoveValid
     * @param move
     * @return
     */
    virtual bool isMoveValid(std::string move);

};

#endif //EX2_QUEEN_H
