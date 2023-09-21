#pragma once

#include<iostream>
#include<vector>
#include"LibraryCard.h"

class LibraryMS
{
    private:
        std::vector<LibraryCard> libraryMS;
    public:
        LibraryMS();
        ~LibraryMS();
        void Add(LibraryCard& temp);
        void Show();
        void Erase(int CardNumber);
        void hello();
};