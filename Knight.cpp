//
// Created by romzats on 1/16/17.
//

#include "Knight.h"

/**
     * Knight constructor
     * @param location
     * @param color
     * @param arrPos
     */
Knight::Knight(std::string location, Color color, int arrPos) : ChessMen(location, color, arrPos)
{
}

/**
 * getter
 * @return
 */
std::string Knight::getType()
{
    return _type;
}

/**
 * Knight implementation of isMoveValid
 * @param move
 * @return
 */
bool Knight::isMoveValid(std::string move)
{
    return ((abs(move.at(1) - move.at(3)) + abs(move.at(0) - move.at(2)) == 3) &&
            ((abs(move.at(0) - move.at(2)) == 2) || (abs(move.at(1) - move.at(3)) == 2)));

}