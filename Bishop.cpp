//
// Created by romzats on 1/16/17.
//

#include "Bishop.h"



/**
     * Bishop constructor
     * @param location
     * @param color
     * @param arrPos
     */
Bishop::Bishop(std::string location, Color color, int arrPos) : ChessMen(location, color, arrPos)
{
}

/**
 * getter
 * @return
 */
std::string Bishop::getType()
{
    return _type;
}

bool Bishop::isMoveValid(std::string move)
{
    int oldPlaceInArr = (((8 - (move.at(1) - '0')) * 8) + (move.at(0)) - 64) - 1;
    int newPlaceInArr = (((8 - (move.at(3) - '0')) * 8) + (move.at(2)) - 64) - 1;
    long check = abs(move.at(1) - move.at(3)) - abs(move.at(2) - move.at(0));
    return (((abs(oldPlaceInArr - newPlaceInArr) % 7 == 0) ||
             (abs(oldPlaceInArr - newPlaceInArr) % 9 == 0)) && check == 0);
}
