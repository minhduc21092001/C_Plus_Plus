#ifndef STEP_H
#define STEP_H

#include<iostream>

class Step
{
    private:
        int Row;
        int Column;
    public:
        Step();

        Step(int _Row, int _Column);

        void SetRow(int _Row);

        int GetRow();

        void SetColumn(int _Column);

        int GetColumn();
};

#endif // STEP_H