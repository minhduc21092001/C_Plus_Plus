#ifndef SEARCHCON_H
#define SEARCHCON_H

#include<iostream>
#include<vector>
#include"..\Model\Player.h"
#include"..\View\PlayUI.h"

class SearchCon
{
    private:
        PlayUI searchUI;
        std::vector<Player> playerlist;
    public:
        void Run();

        void ReadPlayerInfo();

        int Evaluate(Player player);
};

#endif // SEARCHCON_H
