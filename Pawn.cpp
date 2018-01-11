//
// Created by romzats on 1/16/17.
//
#include "Pawn.h"


/**
 * Pawn constructor
 * @param location
 * @param color
 * @param arrPos
 */
Pawn::Pawn(std::string location, Color color, int arrPos) : ChessMen(location, color, arrPos)
{
}

/**
 * pawn implementation of isMoveValid
 * @param move
 * @return
 */
bool Pawn::isMoveValid(std::string move)
{
    int oldPlaceInArr = (((8 - (move.at(1) - '0')) * 8) + (move.at(0)) - 64) - 1;
    int newPlaceInArr = (((8 - (move.at(3) - '0')) * 8) + (move.at(2)) - 64) - 1;
    long diff = oldPlaceInArr - newPlaceInArr;
    if (this->_color == BLACK)
    {
        return didItMove ? (diff == -8 || diff == -7 || diff == -9) : (diff == -8 || diff == -7 ||
                                                                       diff == -9 || diff == -16);
    }
    else
    {
        return didItMove ? (diff == 8 || diff == 7 || diff == 9) : (diff == 8 || diff == 7 ||
                                                                    diff == 9 || diff == 16);
    }
}

/**
 * getter
 * @return
 */
std::string Pawn::getType()
{
    return _type;
}

/**
* updates if the chessman moved
*/
void Pawn::changeMoveState()
{
    didItMove = true;
}
