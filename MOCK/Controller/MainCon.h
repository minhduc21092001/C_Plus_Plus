#ifndef MAINCON_H
#define MAINCON_H

#include<iostream>
#include"PlayCon.h"
#include"..\View\PlayUI.h"
#include"SearchCon.h"
#include"ReplayCon.h"

class MainCon
{
    private:
        PlayUI mainUI;
        PlayCon playcon;
        SearchCon searchcon;
        ReplayCon replaycon;
    public:
        void Run();
};

#endif // MAINCON_H
