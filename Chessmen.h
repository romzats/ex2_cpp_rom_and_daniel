//
// Created by romzats on 1/5/17.
//

#ifndef EX2_PIECE_H
#define EX2_PIECE_H

#include <iostream>

#define KING "\u265A";
#define QUEEN "\u265B";
#define KNIGHT "\u265E";
#define ROOK "\u265C";
#define BISHOP "\u265D";
#define PAWN "\u265F";
/**
 *
 */
enum Color
{
    BLACK = 30,
    WHITE = 37
};

/**
 *
 */
class ChessMen
{
protected:
    std::string _location;
    Color _color;
    int _arrPos;
    std::string _type;

public:
    /**
     * constructor
     */
    ChessMen()
    {
    }

    /**
     * dstructor
     */
    virtual ~ChessMen();

    /**
     * input constructor
     * @param Location -location on board
     * @param Color - color
     * @param arrPos - array position
     */
    ChessMen(std::string Location, Color Color, int arrPos);

    /**
     * getter
     * @return
     */
    virtual std::string getLocation();

    /**
     * setter
     * @param newLocation
     */
    virtual void setLocation(std::string newLocation);

    /**
     * getter
     * @return
     */
    virtual Color getColor();

    /**
     * getter
     * @return
     */
    virtual int getPos();

    /**
     * pure virtual getter
     * @return
     */
    virtual std::string getType() = 0;

    /**
     * pure virtual to check if the move is valid for each kind of chessmen
     * @param move - the move
     * @return - true if valid
     */
    virtual bool isMoveValid(std::string move) = 0;

    /**
     * updates if the chessman moved
     */
    virtual void changeMoveState();

};





#endif //EX2_PIECE_H
