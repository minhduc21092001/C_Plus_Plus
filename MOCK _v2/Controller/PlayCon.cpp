#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include"PlayCon.h"

PlayCon::PlayCon()
{
    ReadPlayerInfo();
}

void PlayCon::Run()
{
    steplist.clear(); // capacity isn't setted to zero only size
    board = {}; //reset board
    playUI.Prompt("Player1 Name: ");
    std::string name1 = playUI.InputString();
    player1.SetName(name1);

    playUI.Prompt("Player2 Name: ");
    std::string name2 = playUI.InputString();
    player2.SetName(name2);

    int count = 1;
    std::string s1x = player1.GetName() + " turn x: ";
    std::string s1y = player1.GetName() + " turn y: ";
    std::string s2x = player2.GetName() + " turn x: ";
    std::string s2y = player2.GetName() + " turn y: ";
    std::string s1win = player1.GetName() + " win\n";
    std::string s2win = player2.GetName() + " win\n";
    std::string sdraw = player1.GetName() + " vs " + player2.GetName() + " draw\n";
    playUI.ShowBoard(board);

    while(count <= 100)
    {
        playUI.Prompt(s1x);
        int row = playUI.InputInteger();
        playUI.Prompt(s1y);
        int column = playUI.InputInteger();
        while(!IsLegal(row, column))
        {
            playUI.Prompt("The typed position is illegal! Please retype\n");
            playUI.Prompt(s1x);
            row = playUI.InputInteger();
            playUI.Prompt(s1y);
            column = playUI.InputInteger();
        }
        while(IsExist(row - 1, column - 1))
        {
            playUI.Prompt("Position has been marked! Please retype\n");
            playUI.Prompt(s1x);
            row = playUI.InputInteger();
            playUI.Prompt(s1y);
            column = playUI.InputInteger();
            while(!IsLegal(row, column))
            {
                playUI.Prompt("The typed position is illegal! Please retype\n");
                playUI.Prompt(s1x);
                row = playUI.InputInteger();
                playUI.Prompt(s1y);
                column = playUI.InputInteger();
            }
        }
        board.SetBoard(row - 1, column - 1, 'X'); // player view
        steplist.push_back(Step{row, column}); // for replaying
        playUI.ShowBoard(board);
        if(WinCondition())
        {
            playUI.Prompt(s1win); // player 1 win
            break;
        }

        playUI.Prompt(s2x);
        row = playUI.InputInteger();
        playUI.Prompt(s2y);
        column = playUI.InputInteger();
        while(!IsLegal(row, column))
        {
            playUI.Prompt("The typed position is illegal! Please retype\n");
            playUI.Prompt(s2x);
            row = playUI.InputInteger();
            playUI.Prompt(s2y);
            column = playUI.InputInteger();
        }
        while(IsExist(row - 1, column -1))
        {
            playUI.Prompt("Position has been marked! Please retype!\n");
            playUI.Prompt(s2x);
            row = playUI.InputInteger();
            playUI.Prompt(s2y);
            column = playUI.InputInteger();
            while(!IsLegal(row, column))
            {
                playUI.Prompt("The typed position is illegal! Please retype\n");
                playUI.Prompt(s1x);
                row = playUI.InputInteger();
                playUI.Prompt(s1y);
                column = playUI.InputInteger();
            }
        }
        board.SetBoard(row - 1, column - 1, 'O');
        steplist.push_back(Step{row, column}); // for replaying
        playUI.ShowBoard(board);
        if(WinCondition())
        {
            playUI.Prompt(s2win); // player 2 win
            break;
        }
    }
    
    if(count == 100)
    {
        playUI.Prompt(sdraw); // player 1 draw player 2
    }

    SaveInfo(count);
    WritePlayerInfo();
    WriteReplayInfo();
    playUI.Prompt("Enter anything to quit: ");
    playUI.InputString();
}

bool PlayCon::WinCondition()
{
    // horizontal check
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 7; j++)
        {
            if(board.GetBoard(i, j) != ' ')
            {
                if(board.GetBoard(i, j) == board.GetBoard(i, j + 1)
                    && board.GetBoard(i, j + 1) == board.GetBoard(i, j + 2)
                    && board.GetBoard(i, j + 2) == board.GetBoard(i, j + 3)) 
                {
                    return true;
                }
            }
        }
    }
    
    // vertical check
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(board.GetBoard(j, i) != ' ')
            {
                if(board.GetBoard(j, i) == board.GetBoard(j + 1, i)
                    && board.GetBoard(j + 1, i) == board.GetBoard(j + 2, i)
                    && board.GetBoard(j + 2, i) == board.GetBoard(j + 3, i))
                {
                    return true;
                }
            }
        }
    }
    
    // top-down diagonal
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(board.GetBoard(i, j) != ' ')
            {
                if(board.GetBoard(i, j) == board.GetBoard(i + 1, j + 1)
                    && board.GetBoard(i + 1, j + 1) == board.GetBoard(i + 2, j + 2)
                    && board.GetBoard(i + 2, j + 2) == board.GetBoard(i + 3, j + 3))
                {
                    return true;
                }
            }
        }
    }
    
    // down-top diagonal
    for(int i = 0; i < 7; i++)
    {
        for(int j = 9;  j > 2; j--)
        {
            if(board.GetBoard(i, j) != ' ')
            {
                if(board.GetBoard(i, j) == board.GetBoard(i + 1, j - 1)
                    && board.GetBoard(i + 1, j - 1) == board.GetBoard(i + 2, j -2)
                    && board.GetBoard(i + 2, j -2 ) == board.GetBoard(i + 3, j - 3))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool PlayCon::IsExist(int row, int column)
{
    if(board.GetBoard(row, column) != ' ')
    {
        return true;
    }
    return false;
}

bool PlayCon::IsLegal(int row, int column) // 1-10
{
    if((row > 0) && (row < 11) && (column > 0) && (column < 11))
    {
        return true;
    }
    return false;
}

void PlayCon::ReadPlayerInfo()
{
    Player temp;
    std::ifstream file("Players.ini");
    if(!file.is_open())
    {
        playUI.Prompt("Error: Could not open file for reading.\n");
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

void PlayCon::WritePlayerInfo()
{
    std::ofstream file("Players.ini");
    if(!file.is_open())
    {
        playUI.Prompt("Error: Could not open file for writing.\n"); // std::cerr
        return;
    }

    int count = 1;
    for (Player& it : playerlist)
    {
        file << "[Player" << count << "]\n";
        file << "Name=" << it.GetName() << "\n";
        file << "Win=" << it.GetWin() << "\n";
        file << "Lose=" << it.GetLose() << "\n";
        file << "Draw=" << it.GetDraw() << "\n";
        file << "\n";
        count++;
    }

    file.close();
}

void PlayCon::SaveInfo(int count)
{
    bool exist1 = false;
    bool exist2 = false;
    if(count == 100)
    {
        for(Player& it : playerlist)
        {
            if(it.GetName() == player1.GetName())
            {
                int i = it.GetDraw() + 1;
                it.SetDraw(i);
                exist1 = true;
            }
            else
            {
                if(it.GetName() == player2.GetName())
                {
                    int i = it.GetDraw() + 1;
                    it.SetDraw(i);
                    exist2 = true;
                }
            }
        }

        if(!exist1)
        {
            player1.SetDraw(1);
            playerlist.push_back(player1);
        }
        if(!exist2)
        {
            player2.SetDraw(1);
            playerlist.push_back(player2);
        }
    }
    else
    {
        if(count%2 != 0) // odd number so player 1 win
        {
            for(Player& it : playerlist)
            {
                if(it.GetName() == player1.GetName())
                {
                    int i = it.GetWin() + 1;
                    it.SetWin(i);
                    exist1 = true;
                }
                else
                {
                    if(it.GetName() == player2.GetName())
                    {
                        int i = it.GetLose() + 1;
                        it.SetLose(i);
                        exist2 = true;
                    }
                }
            }

            if(!exist1)
            {
                player1.SetWin(1);
                playerlist.push_back(player1);
            }
            if(!exist2)
            {
                player2.SetLose(1);
                playerlist.push_back(player2);
            }
        }
        else // even number so player 2 win
        {
            for(Player& it : playerlist)
            {
                if(it.GetName() == player2.GetName())
                {
                    int i = it.GetWin() + 1;
                    it.SetWin(i);
                    exist2 = true;
                }
                else
                {
                    if(it.GetName() == player1.GetName())
                    {
                        int i = it.GetLose() + 1;
                        it.SetLose(i);
                        exist1 = true;
                    }
                }
            }

            if(!exist1)
            {
                player1.SetLose(1);
                playerlist.push_back(player1);
            }
            if(!exist2)
            {
                player2.SetWin(1);
                playerlist.push_back(player2);
            }
        }
    }
}

void PlayCon::WriteReplayInfo()
{
    std::fstream file("Replays.ini", std::ios::app); // appending
    if(!file.is_open())
    {
        playUI.Prompt("Error: Could not open file for writing.\n"); // std::cerr
        return;
    }

    std::time_t currentTime = std::time(nullptr); // Get the current time
    std::string timeString = std::ctime(&currentTime); // Convert the time to a human-readable string
    
    file << "[Replay]\n";
    file << "Name1=" << player1.GetName() << "\n";
    file << "Name2=" << player2.GetName() << "\n";
    file << "Time=" << timeString;

    int count = 1;
    for(Step& it : steplist)
    {
        file << "Step" << count << "=" << it.GetRow() << " " << it.GetColumn() << "\n";
        count++;
    }
    file << "\n";
    file.close();
}
