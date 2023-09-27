#include<iostream>
#include"ReplayInfo.h"

ReplayInfo::ReplayInfo() : Name1(""), Name2(""), Time("") {}

void ReplayInfo::SetName1(std::string _Name1)
{
    Name1 = _Name1;
}

std::string ReplayInfo::GetName1()
{
    return Name1;
}

void ReplayInfo::SetName2(std::string _Name2)
{
    Name2 = _Name2;
}

std::string ReplayInfo::GetName2()
{
    return Name2;
}

void ReplayInfo::SetTime(std::string _Time)
{
    Time = _Time;
}

std::string ReplayInfo::GetTime()
{
    return Time;
}
