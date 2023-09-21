#include<iostream>
#include"LibraryMS.h"

LibraryMS::LibraryMS() {}

LibraryMS::~LibraryMS() {}

void LibraryMS::Add(LibraryCard& temp)
{
    for(auto x : libraryMS)
    {
        if(x.GetCardNumber() == temp.GetCardNumber()) 
        {
            std::cout << "CardNumer has been exist!" << std::endl;
            return;
        }
    }
    libraryMS.push_back(temp);
    std::cout << "Add new card successfully!" << std::endl;
}

void LibraryMS::Show()
{
    if(libraryMS.size() == 0)
    {
        std::cout << "No information to show!" << std::endl;
            return;
    }
    else
    {
        int count = 1;
        for(auto x: libraryMS)
        {
            std::cout << "==========STT: " << count++ << "==========" << std::endl;
            x.GetInformation();
        }
    }
}
void LibraryMS::Erase(int CardNumber)
{
    for(auto x = libraryMS.begin(); x != libraryMS.end(); x++)
    {
        if((*x).GetCardNumber() == CardNumber)
        {
            libraryMS.erase(x);
            std::cout << "Delete successfully!" << std::endl;
            return;
        }
    }
    std::cout << "Can't find cardnumber!" << std::endl;
}
