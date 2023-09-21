#include<iostream>
#include"Student.h"
#include"LibraryCard.h"
#include"LibraryMS.h"

enum CHOICE
{
    ADD = 1,
    SHOW,
    DELETE,
    EXIT
};

int main()
{
    LibraryMS libraryMS;
    int ch;
    do
    {
        std::cout << "========== Library Management System ==========" << std::endl;
        std::cout << "1. Add a new card" << std::endl;
        std::cout << "2. Show cards" << std::endl;
        std::cout << "3. Delete a card" << std::endl;
        std::cout << "4. Exit program" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> ch;
        switch(ch)
        {
            case ADD:
            {   
                std::string Name;
                int Age;
                std::string Address;
                int CardNumber;
                std::string StartDate;
                std::string EndDate;
                int BookNumber;
                std::cout << "Name: ";
                std::cin.ignore();
                std::getline(std::cin, Name);
                std::cout << "Age: ";
                std::cin >> Age;
                std::cout << "Addresss: ";
                std::cin.ignore();
                std::getline(std::cin, Address);
                std::cout << "CardNumber: ";
                std::cin >> CardNumber;
                std::cout << "StartDate: ";
                std::cin.ignore();
                std::getline(std::cin, StartDate);
                std::cout << "EndDate: ";
                getline(std::cin, EndDate);
                std::cout << "BookNumber: ";
                std::cin >> BookNumber;
                Student student(Name, Age, Address);
                LibraryCard libraryCard(student, CardNumber, StartDate, EndDate, BookNumber);
                libraryMS.Add(libraryCard);  
                break;
            }
            case SHOW:
                libraryMS.Show();
                break;
            case DELETE:
            {
                int CardNumber;
                std::cout << "Enter cardnumber which you want to delete: ";
                std::cin >> CardNumber;
                libraryMS.Erase(CardNumber);
                break;
            }
            default:
                std::cout << "Your choise is incorrect!" << std::endl;
                break;
        }
    } while(ch != EXIT);
    return 0;   
}