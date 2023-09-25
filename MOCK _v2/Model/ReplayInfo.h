#ifndef REPLAYINFO_H
#define REPLAYINFO_H

#include<iostream>

class ReplayInfo
{
    private:
        std::string Name1;
        std::string Name2;
        std::string Time;
    public:
        ReplayInfo();

        void SetName1(std::string _Name1);

        std::string GetName1();

        void SetName2(std::string _Name2);

        std::string GetName2();

        void SetTime(std::string _Time);

        std::string GetTime();
};

#endif // REPLAYINFO_H
