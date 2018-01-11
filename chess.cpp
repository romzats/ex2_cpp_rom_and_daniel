#include "chess.h"

/**
 * getter
 * @return
 */
Board *chess::getBoard()
{
    return board;
}

/**
 * dtor
 */
chess::~chess()
{

}
/**
 * ctor
 * @return
 */
chess::chess()
{
    board = new Board;
}


int main()
{
    std::string player1Name;
    std::string player2Name;
    chess *myChess = new chess();
    Board *b = myChess->getBoard();
    std::string move;
    std::cout << "Enter white player name:\n";
    std::cin >> player1Name;
    Player player1(player1Name, WHITE, b->getWhiteKing());
    std::cout << "Enter black player name:\n";
    std::cin >> player2Name;
    Player player2(player2Name, BLACK, b->getBlackKing());
    Player curPlayer = player1;
    bool isCheck = false;
    while (!b->getEndGame(curPlayer, isCheck))
    {
        b->drawBoard();
        if (isCheck && !b->getEndGame(curPlayer, isCheck))
        { std::cout << CHECK << std::endl; }
        std::cout << curPlayer.getName() << ": Please enter your move:\n";
        std::cin >> move;
        if (b->checkMove(move, curPlayer, isCheck))
        {
            isCheck = false;
            b->updateBoard(move, curPlayer, false);
            if (b->isCheckCheck(b->getWhiteKing().getLocation(), NULL_POS, false) ||
                b->isCheckCheck(b->getBlackKing().getLocation(), NULL_POS, false))
            { isCheck = true; }
            b->pawn2QueenChanger();
            if (curPlayer == player1)
            { curPlayer = player2; }
            else
            { curPlayer = player1; }
        }
        else
        {
            std::cout << ILLEGAL_MOVE << std::endl;
        }
    }
    if (curPlayer == player1)
    { curPlayer = player2; }
    else
    { curPlayer = player1; }
    b->drawBoard();
    std::cout << curPlayer.getName() << " won!" << std::endl;
    delete (b);
    delete (myChess);
    return 0;
}


