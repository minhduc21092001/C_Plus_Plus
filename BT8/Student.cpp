#include "Student.h"

Student::Student(std::string _Name, int _Age, std::string _Class) : Name(_Name), Age(_Age), Class(_Class) {}

Student::~Student() {}

void  Student::GetInformation() const
{
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Age: " << Age << std::endl;
    std::cout << "Class: " << Class << std::endl;
    std::cout << "Makefile" << std::endl;
}
