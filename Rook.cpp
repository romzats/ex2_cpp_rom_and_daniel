//
// Created by romzats on 1/16/17.
//

#include "Rook.h"


/**
     * Rook constructor
     * @param location
     * @param color
     * @param arrPos
     */
Rook::Rook(std::string location, Color color, int arrPos) : ChessMen(location, color, arrPos)
{
}

/**
 * getter
 * @return
 */
std::string Rook::getType()
{
    return _type;
}

bool Rook::isMoveValid(std::string move)
{
    return move.at(1) == move.at(3) || move.at(2) == move.at(0);
}