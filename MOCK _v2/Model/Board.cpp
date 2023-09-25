#include<iostream>
#include"Board.h"

Board::Board()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            board[i][j] = ' ';
        }
    }
}

Board::~Board() {}

void Board::SetBoard(int row, int column, char piece)
{
    board[row][column] = piece;
}

char Board::GetBoard(int row, int column)
{
    return board[row][column];
}
