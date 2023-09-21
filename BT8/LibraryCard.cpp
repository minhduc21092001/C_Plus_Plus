#include<iostream>
#include"LibraryCard.h"

LibraryCard::LibraryCard(Student _student, int _CardNumber, std::string _StartDate, std::string _EndDate, int _BookNumber) : student(_student), CardNumber(_CardNumber), StartDate(_StartDate), EndDate(_EndDate), BookNumber(_BookNumber) {}

LibraryCard::~LibraryCard() {}

void LibraryCard::GetInformation() const
{
    student.GetInformation();
    std::cout << "CardNumber: " << CardNumber << std::endl;
    std::cout << "StartDate: " << StartDate << std::endl;
    std::cout << "EndDate: " << EndDate << std::endl;
    std::cout << "BookNumber: " << BookNumber << std::endl;
}

int LibraryCard::GetCardNumber()
{
    return CardNumber;
}
