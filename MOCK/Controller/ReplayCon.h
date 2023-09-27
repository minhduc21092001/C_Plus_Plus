#ifndef REPLAYCON_H
#define REPLAYCON_H

#include<iostream>
#include<vector>
#include"..\Model\ReplayInfo.h"
#include"..\Model\Step.h"
#include"..\Model\Board.h"
#include"..\View\PlayUI.h"

class ReplayCon
{
    private:
        PlayUI replayUI;
        std::vector<ReplayInfo> replaylist;
        std::vector<Step> steplist;
        Board board;
    public:
        void Run();

        void ReadReplayInfo();

        void ReadStepInfo(std::string time);
};

#endif // REPLAYCON_H