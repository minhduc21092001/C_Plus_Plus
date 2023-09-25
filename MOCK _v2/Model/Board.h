#ifndef BOARD_H
#define BOARD_H

#include<iostream>

class Board
{
    private:
        char board[10][10];
    public:
        Board();

        ~Board();

        void SetBoard(int row, int column, char piece);

        char GetBoard(int row, int column);
};

#endif // BOARD_H
