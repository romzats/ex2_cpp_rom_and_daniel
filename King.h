//
// Created by romzats on 1/16/17.
//

#ifndef EX2_KING_H
#define EX2_KING_H

#include  "Chessmen.h"

/**
 *
 */
class King : public ChessMen
{
    std::string _type = KING;


public:
    /**
     * king constructor
     * @param location
     * @param color
     * @param arrPos
     */
    King(std::string location, Color color, int arrPos);

    /**
     * getter
     * @return
     */
    virtual std::string getType();

    /**
     * king implementation of isMoveValid
     * @param move
     * @return
     */

    virtual bool isMoveValid(std::string move);

};

#endif //EX2_KING_H
