//
// Created by romzats on 1/5/17.
//

#include "Chessmen.h"



/**
* input constructor
* @param Location -location on board
* @param Color - color
* @param arrPos - array position
*/
ChessMen::ChessMen(std::string Location, Color color, int arrPos) : _location(Location), _color
        (color), _arrPos(arrPos)
{
}


/**
 * getter
 * @return
 */
std::string ChessMen::getLocation()
{
    return this->_location;
}
/**
    * setter
    * @param newLocation
    */
void ChessMen::setLocation(std::string newLocation)
{
    this->_location = newLocation;
}

/**
 * getter
 * @return
 */
Color ChessMen::getColor()
{
    return this->_color;
}

/**
 * getter
 * @return
 */
int ChessMen::getPos()
{
    return this->_arrPos;
}

/**
 * getter
 * @return
 */
std::string ChessMen::getType()
{
    return std::string();
}

/**
 * dstructor
 */
ChessMen::~ChessMen()
{

}

/**
 * updates if the chessman moved
 */
void ChessMen::changeMoveState()
{
    return;
}

