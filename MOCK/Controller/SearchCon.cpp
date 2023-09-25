#include<iostream>
#include<fstream>
#include"SearchCon.h"

void SearchCon::Run()
{
    playerlist.clear();
    ReadPlayerInfo(); // load to playerlist
    searchUI.Prompt("Enter name to search: ");
    std::string s = searchUI.InputString();
    for(Player& it : playerlist)
    {
        if(it.GetName() == s)
        {
            searchUI.Prompt("Name: ");
            searchUI.Prompt(it.GetName());
            searchUI.Prompt("\n");
            searchUI.Prompt("Win: ");
            searchUI.Prompt(it.GetWin());
            searchUI.Prompt("\n");
            searchUI.Prompt("Lose: ");
            searchUI.Prompt(it.GetLose());
            searchUI.Prompt("\n");
            searchUI.Prompt("Draw: ");
            searchUI.Prompt(it.GetDraw());
            searchUI.Prompt("\n");
            return;
        }
    }
    searchUI.Prompt("Can't find!\n");
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
