#ifndef PLAYUI_H
#define PLAYUI_H

#include<iostream>
#include"..\Model\Board.h"
#include"..\Model\Player.h"

enum CHOICE
{
    PLAYGAME = 1,
    SEARCHBYNAME,
    REPLAY,
    EXIT
};

class PlayUI
{
    public:
        void Prompt(std::string s);

        void Prompt(int i);

        void ShowBoard(Board b);

        void ClearScr();

        std::string InputString();

        int InputInteger();

        void MainMenu();   

        void ShowPlayer(Player Player);
};

#endif // PLAYUI_H
