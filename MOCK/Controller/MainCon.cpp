#include<iostream>
#include"MainCon.h"

void MainCon::Run()
{
    int ch;
    do
    {
        mainUI.MainMenu();
        ch = mainUI.InputInteger();
        switch(ch)
        {
            case PLAYGAME:
                playcon.Run();
                break;
            case SEARCHBYNAME:  
                searchcon.Run();
                break;
            case REPLAY:
                break;
            case EXIT:
                break;
            default:
                mainUI.Prompt("Your choice is incorrect! Please type again...\n");
                break;
        }
    } while(ch != EXIT);
}