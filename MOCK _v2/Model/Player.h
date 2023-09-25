#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>

class Player
{
    private:
        std::string Name;
        int Win;
        int Lose;
        int Draw;
    public:
        Player();

        ~Player();

        void SetName(std::string _Name);

        std::string GetName();

        void SetWin(int _Win);

        int GetWin();

        void SetLose(int _Lose);

        int GetLose();

        void SetDraw(int _Draw);

        int GetDraw();
};

#endif // PLAYER_H
