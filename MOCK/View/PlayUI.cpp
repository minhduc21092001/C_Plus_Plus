#include<iostream>
#include"PlayUI.h"
#include<cstdlib>

void PlayUI::Prompt(std::string s)
{
    std::cout << s;
}

void PlayUI::Prompt(int i)
{
    std::cout << i;
}

void PlayUI::ShowBoard(Board b)
{
    std::cout << "Player 1<X> - Player 2 <O>" << std::endl;
    for(int i = 0; i < 10 ; i++)
    {
        for(int j = 0; j < 10 ; j++)
        {
            if(j != 9)
            {
                std::cout << " " << b.GetBoard(i, j) << " " << "|";
            }
            else
            {
                std::cout << " " << b.GetBoard(i, j) << std::endl;
                std::cout << "---------------------------------------" << std::endl;
            }
        }
    }
}

void PlayUI::ClearScr()
{
    std::system("cls");
}

std::string PlayUI::InputString()
{
    std::string s;
    std::getline(std::cin, s);
    return s;
}

int PlayUI::InputInteger()
{
    int i;
    std::cin >> i;
    std::cin.ignore();
    return i;
}

void PlayUI::MainMenu()
{
    std::cout << "==========Welcome to Gomoku Game==========" << std::endl;
    std::cout << "1. Play Game" << std::endl;
    std::cout << "2. Search by name" << std::endl;
    std::cout << "3. Relay games" << std::endl;
    std::cout << "Your choice: ";
}
