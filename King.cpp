//
// Created by romzats on 1/16/17.
//

#include "King.h"


/**
     * King constructor
     * @param location
     * @param color
     * @param arrPos
     */
King::King(std::string location, Color color, int arrPos) : ChessMen(location, color, arrPos)
{
}


/**
 * getter
 * @return
 */
std::string King::getType()
{
    return _type;
}

bool King::isMoveValid(std::string move)
{
    int oldPlaceInArr = (((8 - (move.at(1) - '0')) * 8) + (move.at(0)) - 64) - 1;
    int newPlaceInArr = (((8 - (move.at(3) - '0')) * 8) + (move.at(2)) - 64) - 1;
    long diff = abs(oldPlaceInArr - newPlaceInArr);

    return (diff == 7 || diff == 9 || diff == 1 || diff == 8 || diff == 2);
}
