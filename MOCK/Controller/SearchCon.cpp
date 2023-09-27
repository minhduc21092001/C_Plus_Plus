#include<iostream>
#include<algorithm>
#include<fstream>
#include"SearchCon.h"

void SearchCon::Run()
{
    playerlist.clear(); // for updating a new playerlist
    ReadPlayerInfo(); // load data to playerlist
    std::sort(playerlist.begin(), playerlist.end(), [&](Player& a, Player& b){return Evaluate(a) < Evaluate(b);}); // sorting vector
    searchUI.ClearScr();
    searchUI.Prompt("Enter name to search: ");
    std::string s = searchUI.InputString();
    for(std::vector<Player>::iterator it = playerlist.begin(); it != playerlist.end(); it++)
    {
        if((*it).GetName() == s)
        {
            searchUI.ShowPlayer(*it);
            searchUI.Prompt("==========Worthy Rival==========\n");
            if(it + 1 == playerlist.end()) // if it is last element, taking previous element
            {
                searchUI.ShowPlayer(*(it - 1));
            }
            else
            {
                searchUI.ShowPlayer(*(it + 1)); // if it is not last element, taking next element
            }
            searchUI.Prompt("Enter anything to quit: ");
            searchUI.InputString();
            return;
        }
    }
    searchUI.Prompt("Can't find!\n");
    searchUI.Prompt("Enter anything to quit: ");
    searchUI.InputString();
}

void SearchCon::ReadPlayerInfo()
{
    Player temp;
    std::ifstream file("Players.ini");
    if(!file.is_open())
    {
        searchUI.Prompt("Error: Could not open file for reading.\n");
        return;
    }

    std::string line;
    while(std::getline(file, line))
    {
        if(line.find("[Player") != std::string::npos) // std::string::npos = not found
        {
            if (!temp.GetName().empty())
            {
                playerlist.push_back(temp);
            }
            temp = {}; // assign to default constructor
        }
        else
        {
            if(line.find("Name=") != std::string::npos)
            {
                std::string s = line.substr(line.find('=') + 1);
                temp.SetName(s);
            } 
            else
            {
                if(line.find("Win=") != std::string::npos)
                {
                    int i = std::stoi(line.substr(line.find('=') + 1));
                    temp.SetWin(i);
                }
                else
                {
                    if(line.find("Lose=") != std::string::npos)
                    {
                        int i = std::stoi(line.substr(line.find('=') + 1));
                        temp.SetLose(i);
                    }
                    else 
                    {
                        if(line.find("Draw=") != std::string::npos)
                        {
                            int i = std::stoi(line.substr(line.find('=') + 1));
                            temp.SetDraw(i);
                        }
                    }
                }
            }
        }
    }

    // Add the last player
    if (!temp.GetName().empty())
    {
        playerlist.push_back(temp);
    }

    file.close();
}

int SearchCon::Evaluate(Player player)
{
    int points;
    points = (player.GetWin() * 2) + player.GetDraw() - player.GetLose();
    return points;
}
