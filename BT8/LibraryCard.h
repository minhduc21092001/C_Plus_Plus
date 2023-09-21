#pragma once

#include<iostream>
#include<string>
#include"Student.h"

class LibraryCard
{
    private:
        Student student;
        int CardNumber;
        std::string StartDate;
        std::string EndDate;
        int BookNumber;
    public:
        LibraryCard(Student _student, int _CardNumber, std::string _StartDate, std::string _EndDate, int _BookNumber);
        ~LibraryCard();
        void GetInformation() const;
        int GetCardNumber();
};
