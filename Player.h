//
// Created by rom on 1/8/17.
//
#ifndef EX2_PLAYR_H
#define EX2_PLAYR_H

#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"
#include "Bishop.h"
#include "Pawn.h"

/**
 *
 */
class Player
{
private:

    std::string _Name;
    Color _Color;
    bool _firstMoveState = true;
    ChessMen &_kingRef;

public:
    /**
     * constructor
     * @param name - inputed name
     * @param color - inputed color
     * @param king - inputed king ref
     */
    Player(std::string name, Color color, ChessMen &king) : _Name(name), _Color(color),
                                                            _kingRef(king)
    {
    }

    /**
     *destructor
     */
    ~Player()
    {
    }

    /**
     * getter
     * @return
     */
    Color getColor();

    /**
     * getter
     * @return
     */
    std::string getName();

    /**
     * setter
     * @param color
     */
    void setColor(Color color);

    /**
     * setter
     * @param name
     */
    void setName(std::string name);

    /**
     * normal = operator for player class
     * @param a
     * @return
     */
    Player &operator=(const Player &a);

    /**
     * normal == operator for player class
     * @param a
     * @return yes if equal
     */
    bool operator==(const Player &a);

    /**
     * getter
     * @return
     */
    bool getMoveState();

    /**
     * setter
     */
    void setMoveState();


};


#endif //EX2_PLAYR_H