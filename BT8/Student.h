#pragma once

#include<iostream>
#include<string>

class Student
{
    private:
        std::string Name;
        int Age;
        std::string Class;
    public:
        Student(std::string _Name, int _Age, std::string _Class);
        ~Student();
        void  GetInformation() const;
};
