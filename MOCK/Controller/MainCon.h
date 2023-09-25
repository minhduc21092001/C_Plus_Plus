#ifndef MAINCON_H
#define MAINCON_H

#include<iostream>
#include"PlayCon.h"
#include"..\View\PlayUI.h"
#include"SearchCon.h"

class MainCon
{
    private:
        PlayUI mainUI;
        PlayCon playcon;
        SearchCon searchcon;
    public:
        void Run();
};

#endif // MAINCON_H
