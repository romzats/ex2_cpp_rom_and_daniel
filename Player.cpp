//
// Created by rom on 1/8/17.
//

#include "Player.h"

/**
 * getter
 * @return
 */
std::string Player::getName()
{
    return this->_Name;
}

/**
 * getter
 * @return
 */
Color Player::getColor()
{
    return this->_Color;
}

/**
 * normal = operator for player class
 * @param a
 * @return
 */
Player &Player::operator=(const Player &a)
{
    if (!(*this == a))
    {
        this->setColor(a._Color);
        this->setName(a._Name);
    }
    return *this;
}

/**
 * normal == operator for player class
 * @param a
 * @return yes if equal
 */
bool Player::operator==(const Player &a)
{
    return (this->getColor() == a._Color) && (this->getName() == a._Name);
}

/**
 * setter
 */
void Player::setName(std::string name)
{
    this->_Name = name;
}

/**
 * setter
 */
void Player::setColor(Color color)
{
    this->_Color = color;
}

/**
 * setter
 */
void Player::setMoveState()
{
    this->_firstMoveState = false;
}

/**
 * getter
 * @return
 */
bool Player::getMoveState()
{
    return _firstMoveState;
}
