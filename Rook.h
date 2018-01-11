//
// Created by romzats on 1/16/17.
//

#ifndef EX2_ROOK_H
#define EX2_ROOK_H

#include "Chessmen.h"

/**
 *
 */
class Rook : public ChessMen
{
    std::string _type = ROOK;
public:
    /**
     * rook constructor
     * @param location
     * @param color
     * @param arrPos
     */
    Rook(std::string location, Color color, int arrPos);

    /**
     * getter
     * @return
     */
    virtual std::string getType();

    /**
     * rook implementation of isMoveValid
     * @param move
     * @return
     */

    virtual bool isMoveValid(std::string move);

};

#endif //EX2_ROOK_H
