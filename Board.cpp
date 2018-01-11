#include "Board.h"

/**
* draws the board
*/
void Board::drawBoard()
{
    int counter = 0;
    bool isBlue = true;
    std::cout << "\33[2J" << LETTERS;
    for (int i = 8; i > 0; --i)
    {
        std::cout << i << " ";
        isBlue = !isBlue;
        for (int j = 0; j < 8; ++j)
        {
            printSquare(isBlue, counter);
            isBlue = !isBlue;
            counter++;
        }
        std::cout << " " << i;
        std::cout << EMPTY_LINE;
    }
    std::cout << "\n" << LETTERS;
}

/**
* remove a chessman
* @param toRemove - the chessman
*/
void Board::removeFromBoard(ChessMen *toRemove)
{
    _myChessMen[toRemove->getPos()] = nullptr;
    delete (toRemove);
}

/**
* initialize the board and the king pointers
*/
void Board::initializeBoard()
{
    _myChessMen[48] = new Pawn("A2", WHITE, 48);
    _myChessMen[49] = new Pawn("B2", WHITE, 49);
    _myChessMen[50] = new Pawn("C2", WHITE, 50);
    _myChessMen[51] = new Pawn("D2", WHITE, 51);
    _myChessMen[52] = new Pawn("E2", WHITE, 52);
    _myChessMen[53] = new Pawn("F2", WHITE, 53);
    _myChessMen[54] = new Pawn("G2", WHITE, 54);
    _myChessMen[55] = new Pawn("H2", WHITE, 55);
    _myChessMen[56] = new Rook("A1", WHITE, 56);
    _myChessMen[57] = new Knight("B1", WHITE, 57);
    _myChessMen[58] = new Bishop("C1", WHITE, 58);
    _myChessMen[59] = new Queen("D1", WHITE, 59);
    _myChessMen[60] = new King("E1", WHITE, 60);
    _myChessMen[61] = new Bishop("F1", WHITE, 61);
    _myChessMen[62] = new Knight("G1", WHITE, 62);
    _myChessMen[63] = new Rook("H1", WHITE, 63);
    _myChessMen[0] = new Rook("A8", BLACK, 0);
    _myChessMen[1] = new Knight("B8", BLACK, 1);
    _myChessMen[2] = new Bishop("C8", BLACK, 2);
    _myChessMen[3] = new Queen("D8", BLACK, 3);
    _myChessMen[4] = new King("E8", BLACK, 4);
    _myChessMen[5] = new Bishop("F8", BLACK, 5);
    _myChessMen[6] = new Knight("G8", BLACK, 6);
    _myChessMen[7] = new Rook("H8", BLACK, 7);
    _myChessMen[8] = new Pawn("A7", BLACK, 8);
    _myChessMen[9] = new Pawn("B7", BLACK, 9);
    _myChessMen[10] = new Pawn("C7", BLACK, 10);
    _myChessMen[11] = new Pawn("D7", BLACK, 11);
    _myChessMen[12] = new Pawn("E7", BLACK, 12);
    _myChessMen[13] = new Pawn("F7", BLACK, 13);
    _myChessMen[14] = new Pawn("G7", BLACK, 14);
    _myChessMen[15] = new Pawn("H7", BLACK, 15);
    _bKingP = _myChessMen[4];
    _wKingP = _myChessMen[60];
    for (int i = 16; i < 48; ++i)
    {
        _myChessMen[i] = NULL;
    }
}

/**
* print a singal squre
* @param isBlue is the squre blue
* @param counter - pos counter
*/
void Board::printSquare(bool isBlue, int counter)
{
    if (_myChessMen[counter] != NULL)
    {
        std::string type = _myChessMen[counter]->getType();
        Color color = _myChessMen[counter]->getColor();
        std::string colorstr;
        if (color == BLACK)
        { colorstr = "30"; }
        else
        { colorstr = "37"; }
        std::string yellow = "\33[" + colorstr + ";42m" + type + "\33[0m";
        std::string green = "\33[" + colorstr + ";46m" + type + "\33[0m";
        isBlue ? (std::cout << yellow) : (std::cout << green);
    }
    else
    {
        isBlue ? (std::cout << "\33[0;42m \33[0m") : (std::cout << "\33[0;46m \33[0m");
    }
}

/**
* the main check move method
* @param move -the move
* @param curPlayer - cur player
* @param isCheck -is it a check state
* @return
*/
bool Board::checkMove(std::string move, Player curPlayer, bool isCheck)
{
    std::string king = KING;
    std::string pawn = PAWN;
    std::string knight = KNIGHT;
    //check for input pattern
    if (move.compare(LONG_CASTLING) == 0 || move.compare(SHORT_CASTLING) == 0)
    {
        return curPlayer.getMoveState() ? castlingCheck(curPlayer, move) && !isCheck : false;
    }
    else if ((move.length() == 4 && isValidLetter(move.at(0)) && isValidLetter(move.at(2))
             && isValidNumber(move.at(3)) && isValidNumber(move.at(1))))
    {
        int oldPlaceInArr = (((8 - (move.at(1) - '0')) * 8) + (move.at(0)) - 64) - 1;
        int newPlaceInArr = (((8 - (move.at(3) - '0')) * 8) + (move.at(2)) - 64) - 1;
        long pawnCheck = abs(oldPlaceInArr - newPlaceInArr);
        //if there is a right color piece in the selected place
        if (_myChessMen[oldPlaceInArr] != NULL && oldPlaceInArr != newPlaceInArr &&
            _myChessMen[oldPlaceInArr]->getColor() == curPlayer.getColor() &&
            kingMoveHelper(move, curPlayer))
        {
            //allow the pawn to move diagonally only when it eats another chessmen
            if ((pawn.compare(_myChessMen[oldPlaceInArr]->getType()) == 0) &&
                ((((pawnCheck == 8) || (pawnCheck == 16)) && _myChessMen[newPlaceInArr] != nullptr)
                || ((pawnCheck == 7 || pawnCheck == 9) && _myChessMen[newPlaceInArr] == nullptr)))
            { return false; }
            // if the path is clear, for all chessmen but knight and its not check situation
            if ((king.compare(_myChessMen[oldPlaceInArr]->getType()) != 0) && !isCheck &&
                (((knight.compare(_myChessMen[oldPlaceInArr]->getType()) == 0) ||
                isPathClear(move)) && _myChessMen[oldPlaceInArr]->isMoveValid(move)))
            {
                return !(_myChessMen[newPlaceInArr] != NULL &&
                         (_myChessMen[oldPlaceInArr]->getColor() ==
                          _myChessMen[newPlaceInArr]->getColor()));
            }
                // if it is a check! move
            else if (_myChessMen[oldPlaceInArr]->getType().compare(king) == 0 &&
                     _myChessMen[oldPlaceInArr]->isMoveValid(move))
            { return kingMoveHelper(move, curPlayer); }
            else
            { return false; }
        }
    }

    return false;
}

/**
* updates the board
* @param move - the movw
* @param player -cur player
* @param isCheck -is it a check state
*/
void Board::updateBoard(std::string move, Player &player, bool isCheck)
{
//check if castling is needed
    if (move.compare(LONG_CASTLING) == 0 || move.compare(SHORT_CASTLING) == 0)
    { updateCastling(move, player); }
    else
    {
        std::string tempNewPos = move.substr(2, 2);
        std::string tempOldPos = move.substr(0, 2);
        std::string rook = ROOK;
        std::string king = KING;
        std::string Pawn = PAWN;
        int oldPlaceInArr = (((8 - (move.at(1) - '0')) * 8) + (move.at(0)) - 64) - 1;
        int newPlaceInArr = (((8 - (move.at(3) - '0')) * 8) + (move.at(2)) - 64) - 1;
        if (_myChessMen[newPlaceInArr] != NULL &&
            (_myChessMen[oldPlaceInArr]->getColor() != _myChessMen[newPlaceInArr]->getColor()
            && !isCheck))
        { removeFromBoard(_myChessMen[newPlaceInArr]); }

        // change castling state for the player
        if (player.getMoveState() && ((_myChessMen[oldPlaceInArr]->getType().compare
            (rook) == 0) || (_myChessMen[oldPlaceInArr]->getType().compare(king) == 0)))
        { player.setMoveState(); }
        if (isCheck)
        {
            ChessMen *temp = _myChessMen[newPlaceInArr];
            _myChessMen[newPlaceInArr] = _myChessMen[oldPlaceInArr];
            _myChessMen[newPlaceInArr]->setLocation(tempNewPos);
            _myChessMen[oldPlaceInArr] = temp;
            if (temp != nullptr)
            { _myChessMen[oldPlaceInArr]->setLocation(tempOldPos); }
        }
        else
        {
            _myChessMen[newPlaceInArr] = _myChessMen[oldPlaceInArr];
            _myChessMen[newPlaceInArr]->setLocation(tempNewPos);
            _myChessMen[oldPlaceInArr] = nullptr;
        }
        if (Pawn.compare(_myChessMen[newPlaceInArr]->getType()) == 0 && !isCheck)
        { _myChessMen[newPlaceInArr]->changeMoveState(); }
    }
}

/**
* check if the path is clear for all chessmen types
* @param move - the move
* @return true if clear
*/
bool Board::isPathClear(std::string move)
{
    int oldPlaceInArr = (((8 - (move.at(1) - '0')) * 8) + (move.at(0)) - 64) - 1;
    int newPlaceInArr = (((8 - (move.at(3) - '0')) * 8) + (move.at(2)) - 64) - 1;
    std::string king = KING;
    std::string rook = ROOK;

    // vertical move
    if ((move.at(1) != move.at(3) && move.at(2) == move.at(0)))
    {
        for (int i = (oldPlaceInArr >= newPlaceInArr ? newPlaceInArr : oldPlaceInArr) + 8;
             i < ((oldPlaceInArr >= newPlaceInArr) ? oldPlaceInArr : newPlaceInArr); i += 8)
        {
            if (_myChessMen[i] != NULL)
            { return false; }
        }
        return true;

    }
        // horizontal
    else if ((move.at(1) == move.at(3) && move.at(2) != move.at(0)))
    {
        for (int i = (oldPlaceInArr >= newPlaceInArr ? newPlaceInArr : oldPlaceInArr) + 1;
             i < ((oldPlaceInArr >= newPlaceInArr) ? oldPlaceInArr : newPlaceInArr); ++i)
        {
            // if the checked square is full and it is not castling
            if (_myChessMen[i] != NULL && ((!((_myChessMen[i]->getType().compare(king) == 0) &&
                _myChessMen[oldPlaceInArr]->getType().compare(rook) == 0)) ||
                !((_myChessMen[i]->getType().compare(rook) == 0) &&
                _myChessMen[oldPlaceInArr]->getType().compare(king) == 0)))
            { return false; }
        }
        return true;
    }
        //up-right diagonal
    else if (abs(oldPlaceInArr - newPlaceInArr) % 7 == 0)
    {
        for (int i = (oldPlaceInArr >= newPlaceInArr ? newPlaceInArr : oldPlaceInArr) + 7;
             i < ((oldPlaceInArr >= newPlaceInArr) ? oldPlaceInArr : newPlaceInArr); i += 7)
        {
            if (_myChessMen[i] != NULL)
            { return false; }
        }
        return true;

    }
        //down-right diagonal
    else if (abs(oldPlaceInArr - newPlaceInArr) % 9 == 0)
    {
        for (int i = (oldPlaceInArr >= newPlaceInArr ? newPlaceInArr : oldPlaceInArr) + 9;
             i < ((oldPlaceInArr >= newPlaceInArr) ? oldPlaceInArr : newPlaceInArr); i += 9)
        {
            if (_myChessMen[i] != NULL)
            { return false; }
        }
        return true;
    }
    return false;
}

/**
* constructor
*/
Board::Board()
{
    initializeBoard();
}

/**
* check if the ltr is in A-H in ascii
* @param ltr
* @return true if the ltr is in A-H in ascii
*/
bool Board::isValidLetter(char ltr)
{
    return ((ltr > 64) && ((ltr < 73)));
}

/**
* check if the ltr is in 1-8 in ascii
* @param ltr
* @return true if the ltr is in 0-8 in ascii
*/
bool Board::isValidNumber(char ltr)
{
    return ((ltr - '0' > 0) && ((ltr - '0' < 9)));
}

/**
*
* @return the white king
*/
ChessMen &Board::getWhiteKing()
{
    return *_wKingP;
}

/**
*
* @return the black king
*/
ChessMen &Board::getBlackKing()
{
    return *_bKingP;
}

/**
* main function to check if it is a check state
* @param checkKingPos - cur king position
* @return true if check
*/
bool Board::isCheckCheck(std::string checkKingPos, std::string checkPos, bool isCastling)
{
    for (ChessMen *squre:_myChessMen)
    {
        if (squre != nullptr && squre->getLocation().compare(checkPos) != 0)
        {
            std::string move = squre->getLocation() + checkKingPos;
            std::string reverse = move.substr(2, 3) + move.substr(0, 2);
            int oldPlaceInArr = (((8 - (move.at(1) - '0')) * 8) + (move.at(0)) - 64) - 1;
            int newPlaceInArr = (((8 - (move.at(3) - '0')) * 8) + (move.at(2)) - 64) - 1;
            std::string knight = KNIGHT;
            if (oldPlaceInArr != newPlaceInArr &&
                _myChessMen[oldPlaceInArr]->getColor() != _myChessMen[newPlaceInArr]->getColor()
                && ((_myChessMen[oldPlaceInArr]->isMoveValid(move) && (knight.compare
                (_myChessMen[oldPlaceInArr]->getType()) == 0 || isPathClear(move)))))
            {
                if (isCastling)
                {
                    return (isPathClear(reverse) && _myChessMen[newPlaceInArr]->isMoveValid
                            (reverse));
                }
                else
                {
                    return true;
                }
            }
        }
    }
    return false;
}


/**
* check if the given move is possiable for a king
* @param move - the move
* @param player - cur player
* @return - true if possiable
*/
bool Board::kingMoveHelper(std::string move, Player player)
{
    std::string reverse = move.substr(2, 3) + move.substr(0, 2);
    if (reverse.compare(move) == 0)
    { return false; }
    updateBoard(move, player, true);
    bool check;
    if (player.getColor() == WHITE)
    { check = isCheckCheck(getWhiteKing().getLocation(), move.substr(0, 2), false); }
    else
    { check = isCheckCheck(getBlackKing().getLocation(), move.substr(0, 2), false); }
    if (check)
    {
        updateBoard(reverse, player, true);
        return false;
    }
    updateBoard(reverse, player, true);
    return true;
}

/**
* check if castling is possible
* @param curPlayer -cur player
* @param move -thr move
* @return -true if possible
*/
bool Board::castlingCheck(Player curPlayer, std::string move)
{
    if (curPlayer.getMoveState())
    {
        int check = 0;
        int start = 1;
        if (curPlayer.getColor() == WHITE)
        {
            start += 56;
            check = start - 1;
        }
        int stop = start + 3;
        if (move.compare(SHORT_CASTLING) == 0)
        {
            start += 4;
            stop += 3;
            check = stop + 1;
        }
        if (_myChessMen[check] != nullptr)
        {
            for (int i = start; i < stop; ++i)
            {
                if (_myChessMen[i] != nullptr)
                { return false; }
            }
        }
        return true;
    }
    return false;
}

/**
* update the board when casteling is called
* @param move - the move
* @param curPlayer  - curplayer
*/
void Board::updateCastling(std::string move, Player &curPlayer)
{
    int kingOldPlace;
    int rookOldPlace;
    std::string tempKingPos;
    std::string tempRookPos;
    (curPlayer.getColor() == BLACK) ? kingOldPlace = 4, rookOldPlace = 0 : kingOldPlace = 60,
                                      rookOldPlace = 56;
    int rookNewPlace = rookOldPlace + 3;
    int kingNewPlace = kingOldPlace;
    (move.compare(SHORT_CASTLING) == 0) ? kingNewPlace += 2, rookOldPlace += 7, rookNewPlace += 2
                                        : kingNewPlace -= 2;
    tempKingPos = (char) (65 + kingNewPlace % 8) + std::to_string(8 - kingNewPlace / 8);
    tempRookPos = (char) (65 + rookNewPlace % 8) + std::to_string(8 - rookNewPlace / 8);
    std::string oldKingPo = _myChessMen[kingOldPlace]->getLocation();
    std::string oldRookPo = _myChessMen[rookOldPlace]->getLocation();
    changePlaces(kingNewPlace, kingOldPlace, rookNewPlace, rookOldPlace, tempKingPos, tempRookPos);
    if (isCheckCheck(tempKingPos, NULL_POS, true) || isCheckCheck(tempRookPos, NULL_POS, true))
    {
        changePlaces(kingOldPlace, kingNewPlace, rookOldPlace, rookNewPlace, oldKingPo, oldRookPo);
        std::cout << ILLEGAL_MOVE << std::endl;
    }
    curPlayer.setMoveState();
}

/**
* helper function for updateCastling()
* @param kingNewPlace - where the king goes
* @param kingOldPlace - where the king was
* @param rookNewPlace - where the rook goes
* @param rookOldPlace - where the rook was
* @param tempKingPos - pos as string for insertion
* @param tempRookPos - pos as string for insertion
*/
void Board::changePlaces(int kingNewPlace, int kingOldPlace, int rookNewPlace, int rookOldPlace,
                         std::string tempKingPos, std::string tempRookPos)
{
    _myChessMen[kingNewPlace] = _myChessMen[kingOldPlace];
    _myChessMen[kingNewPlace]->setLocation(tempKingPos);
    _myChessMen[kingOldPlace] = nullptr;
    _myChessMen[rookNewPlace] = _myChessMen[rookOldPlace];
    _myChessMen[rookNewPlace]->setLocation(tempRookPos);
    _myChessMen[rookOldPlace] = nullptr;
}

/**
* changes the pawn to a queen if it reaches the last row
*/
void Board::pawn2QueenChanger()
{
    std::string pawn = PAWN;
    for (int j = 0; j < 57; j += 56)
    {
        for (int i = 0; i < 8; ++i)
        {
            if (_myChessMen[i + j] != nullptr && pawn.compare(_myChessMen[i + j]->getType()) == 0)
            {
                std::string loc = _myChessMen[i + j]->getLocation();
                Color col = _myChessMen[i + j]->getColor();
                removeFromBoard(_myChessMen[i + j]);
                _myChessMen[i + j] = new Queen(loc, col, i + j);
            }
        }
    }
}

/**
* check if the game was ended e.g. chessmate
* @param player -cur player
* @param isCheck - is it a check state
* @return true if chessmate
*/
bool Board::getEndGame(Player player, bool isCheck)
{

    if (!isCheck)
    {
        return false;
    }
    std::string kingLoc = getBlackKing().getLocation();
    if (player.getColor() == BLACK)
    { kingLoc = getBlackKing().getLocation(); }
    else
    { kingLoc = getWhiteKing().getLocation(); }
    std::string check;
    int horizontal[3] = {kingLoc[0] - 1, kingLoc[0] + 1, kingLoc[0]};
    int vertical[3] = {kingLoc[1] + 1, kingLoc[1] - 1, kingLoc[1]};
    for (int hor :horizontal)
    {
        for (int ver:vertical)
        {
            if (ver <= 56 && ver >= 49 && hor <= 72 && hor >= 65 &&
                !(kingLoc[0] == ver && kingLoc[1] == hor))
            {
                char x = (char) hor;
                char y = (char) ver;
                check = kingLoc + x + y;
                int PlaceInArr = (((8 - (ver - '0')) * 8) + hor - 64) - 1;
                if (kingMoveHelper(check, player) && (_myChessMen[PlaceInArr] == NULL ||
                    _myChessMen[PlaceInArr]->getColor() != player.getColor()))
                { return false; }
            }
        }
    }
    return true;
}

/**
* destructor
*/
Board::~Board()
{
    for (ChessMen *toDelete:_myChessMen)
    {
        if (toDelete != NULL)
        { delete (toDelete); }
    }
}