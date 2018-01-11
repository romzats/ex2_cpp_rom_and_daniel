//
// Created by romzats on 1/16/17.
//

#ifndef EX2_PAWN_H
#define EX2_PAWN_H
#include "Chessmen.h"

/**
 * pawn class
 */
class Pawn : public ChessMen
{

    std::string _type = PAWN;
    bool didItMove = false;
public:
    /**
     * pawn constructor
     * @param location
     * @param color
     * @param arrPos
     */
    Pawn(std::string location, Color color, int arrPos);

    /**
     * getter
     * @return
     */
    virtual std::string getType();

    /**
     * pawn implementation of isMoveValid
     * @param move
     * @return
     */
    virtual bool isMoveValid(std::string move);

    /**
     * updates if the chessman moved
     */
    void changeMoveState();
};



#endif //EX2_PAWN_H
