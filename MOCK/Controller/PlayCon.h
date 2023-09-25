#ifndef PLAYCON_H
#define PLAYCON_H

#include<iostream>
#include<vector>
#include"..\Model\Board.h"
#include"..\Model\Player.h"
#include"..\View\PlayUI.h"

class PlayCon
{
    private:
        PlayUI playUI;
        Board board;
        Player player1;
        Player player2;
        std::vector<Player> playerlist;
    public:
        PlayCon();

        void Run();

        bool WinCondition();

        bool IsExist(int row, int column);

        bool IsLegal(int row, int column);

        void ReadPlayerInfo();

        void WritePlayerInfo();

        void SaveInfo(int count);
};

#endif // PLAYCON_H
