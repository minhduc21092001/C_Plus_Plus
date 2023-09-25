#include<iostream>
#include<fstream>
#include"ReplayCon.h"
#include<windows.h>

void ReplayCon::Run()
{
    replaylist.clear();
    steplist.clear();
    board = {};
    ReadReplayInfo();
    int count = 1;
    replayUI.ClearScr();
    for(ReplayInfo& it : replaylist)
    {
        replayUI.Prompt(count);
        replayUI.Prompt(". ");
        replayUI.Prompt(it.GetName1());
        replayUI.Prompt(" vs ");
        replayUI.Prompt(it.GetName2());
        replayUI.Prompt(" ");
        replayUI.Prompt("(");
        replayUI.Prompt(it.GetTime());
        replayUI.Prompt(")\n");
        count++;
    }

    replayUI.Prompt("Your choice: ");
    int ch = replayUI.InputInteger(); // user view
    while(ch > replaylist.size() || ch < 1)
    {
        replayUI.Prompt("Your choice is incorrect! Please retype...\n");
        replayUI.Prompt("Your choice: ");
        ch = replayUI.InputInteger();
    }
    std::string name1 = replaylist[ch-1].GetName1();
    std::string name2 = replaylist[ch-1].GetName2();
    ReadStepInfo(replaylist[ch-1].GetTime());
    count = 1;
    replayUI.ShowBoard(board);
    Sleep(1000);
    for(Step& it : steplist)
    {
        replayUI.ShowBoard(board);
        if(count % 2 != 0) // player 1
        {
            board.SetBoard(it.GetRow() - 1, it.GetColumn() - 1 , 'X');
            replayUI.ShowBoard(board);
            replayUI.Prompt(name1);
            replayUI.Prompt(" turn x: ");
            replayUI.Prompt(it.GetRow());
            replayUI.Prompt("\n");
            replayUI.Prompt(name1);
            replayUI.Prompt(" turn y: ");
            replayUI.Prompt(it.GetRow());
            replayUI.Prompt("\n");
            Sleep(1000);
        }
        else
        {
            board.SetBoard(it.GetRow() - 1, it.GetColumn() - 1, 'O');
            replayUI.ShowBoard(board);
            replayUI.Prompt(name2);
            replayUI.Prompt(" turn x: ");
            replayUI.Prompt(it.GetRow());
            replayUI.Prompt("\n");
            replayUI.Prompt(name2);
            replayUI.Prompt(" turn y: ");
            replayUI.Prompt(it.GetRow());
            replayUI.Prompt("\n");
            Sleep(1000);
        }
        count++;
    }
    if(steplist.size() == 100)
    {
        replayUI.Prompt(name1);
        replayUI.Prompt(" draw ");
        replayUI.Prompt(name2);
        replayUI.Prompt("\n");
    }
    else
    {
        if(steplist.size() % 2 != 0)
        {
            replayUI.Prompt(name1);
            replayUI.Prompt(" win\n");
        }
        else
        {
            replayUI.Prompt(name2);
            replayUI.Prompt(" win\n");           
        }
    }
    replayUI.Prompt("Enter anything to quit: ");
    replayUI.InputString();
}

void ReplayCon::ReadReplayInfo()
{
    ReplayInfo temp;
    std::ifstream file("Replays.ini");
    if(!file.is_open())
    {
        replayUI.Prompt("Error: Could not open file for reading.\n");
        return;
    }

    std::string line;
    while(std::getline(file, line))
    {
        if(line.find("[Replay]") != std::string::npos) // std::string::npos = not found
        {
            if (!temp.GetName1().empty())
            {
                replaylist.push_back(temp);
            }
            temp = {}; // assign to default constructor
        }
        else
        {
            if(line.find("Name1=") != std::string::npos)
            {
                std::string s = line.substr(line.find('=') + 1);
                temp.SetName1(s);
            } 
            else
            {
                if(line.find("Name2=") != std::string::npos)
                {
                    std::string s = line.substr(line.find('=') + 1);
                    temp.SetName2(s);
                }
                else
                {
                    if(line.find("Time=") != std::string::npos)
                    {
                        std::string s = line.substr(line.find('=') + 1);
                        temp.SetTime(s);
                    }
                }
            }
        }
    }

    // Add the last element
    if (!temp.GetName1().empty())
    {
        replaylist.push_back(temp);
    }

    file.close();
}

void ReplayCon::ReadStepInfo(std::string time) // time is only one
{
    Step temp;
    std::ifstream file("Replays.ini");
    if(!file.is_open())
    {
        replayUI.Prompt("Error: Could not open file for reading.\n");
        return;
    }

    std::string line;
    bool found = false;
    while(std::getline(file, line))
    {
        if(line.find(time) != std::string::npos) // std::string::npos = not found
        {
            found = true; // found match
            continue;
        }
        if(found)
        {
            if(line.find("Step") != std::string::npos)
            {
                std::string s = line.substr(line.find("=") + 1);
                int srow = std::stoi(s.substr(0, s.find(" ")));
                int scolumn = std::stoi(s.substr(s.find(" ")));
                temp.SetRow(srow);
                temp.SetColumn(scolumn);
                steplist.push_back(temp);
            }
            else
            {
                found = false;
                file.close();
                return;
            }
        }
    }

    file.close();
}