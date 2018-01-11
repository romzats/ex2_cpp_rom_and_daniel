//
// Created by romzats on 1/5/17.
//

#ifndef EX2_BOARD_H
#define EX2_BOARD_H


#include <stdlib.h>
#include "Player.h"

#define LETTERS "  ABCDEFGH\n\n"
#define LONG_CASTLING "0-0-0"
#define SHORT_CASTLING "0-0"
#define ILLEGAL_MOVE "\33[37;41millegal move\33[0m"
#define NULL_POS "Z9"
#define EMPTY_LINE "\n"
#define NUM_OF_SQUARES 64

/**
 * Board class
 */
class Board
{
private:
    ChessMen *_myChessMen[NUM_OF_SQUARES];
    ChessMen *_bKingP;
    ChessMen *_wKingP;

public:

    /**
    * constructor
    */
    Board();

    /**
     * destructor
     */
    ~Board();


    /**
    * draws the board
    */
    void drawBoard();

    /**
    * remove a chessman
    * @param toRemove - the chessman
    */
    void removeFromBoard(ChessMen *toRemove);

    /**
    * initialize the board and the king pointers
    */
    void initializeBoard();

    /**
    * the main check move method
    * @param move -the move
    * @param curPlayer - cur player
    * @param isCheck -is it a check state
    * @return
    */
    bool checkMove(std::string move, Player curPlayer, bool isCheck);

    /**
    * check if the ltr is in A-H in ascii
    * @param ltr
    * @return true if the ltr is in A-H in ascii
    */
    bool isValidLetter(char ltr);

    /**
    * check if the ltr is in 1-8 in ascii
    * @param ltr
    * @return true if the ltr is in 0-8 in ascii
    */
    bool isValidNumber(char ltr);

    /**
    * print a singal squre
    * @param isBlue is the squre blue
    * @param counter - pos counter
    */
    void printSquare(bool isBlue, int counter);

    /**
    * check if the path is clear for all chessmen types
    * @param move - the move
    * @return true if clear
    */
    bool isPathClear(std::string move);

    /**
    *
    * @return the black king
    */
    ChessMen &getBlackKing();

    /**
    *
    * @return the white king
    */
    ChessMen &getWhiteKing();

    /**
    * main function to check if it is a check state
    * @param checkKingPos - cur king position
    * @return true if check
    */
    bool isCheckCheck(std::string checkKingPos, std::string checkPos, bool isCastling);


    /**
    * updates the board
    * @param move - the movw
    * @param player -cur player
    * @param isCheck -is it a check state
    */
    void updateBoard(std::string move, Player &player, bool isCheck);


    /**
    * check if the given move is possiable for a king
    * @param move - the move
    * @param player - cur player
    * @return - true if possiable
    */
    bool kingMoveHelper(std::string move, Player player);

    /**
    * check if castling is possible
    * @param curPlayer -cur player
    * @param move -thr move
    * @return -true if possible
    */
    bool castlingCheck(Player curPlayer, std::string move);

    /**
    * update the board when casteling is called
    * @param move - the move
    * @param curPlayer  - curplayer
    */
    void updateCastling(std::string move, Player &curPlayer);

    /**
    * changes the pawn to a queen if it reaches the last row
    */
    void pawn2QueenChanger();

    /**
    * check if the game was ended e.g. chessmate
    * @param player -cur player
    * @param isCheck - is it a check state
    * @return true if chessmate
    */
    bool getEndGame(Player player, bool isCheck);


    /**
    * helper function for updateCastling()
    * @param kingNewPlace - where the king goes
    * @param kingOldPlace - where the king was
    * @param rookNewPlace - where the rook goes
    * @param rookOldPlace - where the rook was
    * @param tempKingPos - pos as string for insertion
    * @param tempRookPos - pos as string for insertion
    */
    void changePlaces(int kingNewPlace, int kingOldPlace, int rookNewPlace, int rookOldPlace,
                      std::string tempKingPos, std::string tempRookPos);
};


#endif //EX2_BOARD_H
