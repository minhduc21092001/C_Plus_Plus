#include<iostream>
#include"Step.h"

Step::Step() : Row(0), Column(0) {}

Step::Step(int _Row, int _Column) : Row(_Row), Column(_Column) {}

void Step::SetRow(int _Row)
{
    Row = _Row;
}

int Step::GetRow()
{
    return Row;
}

void Step::SetColumn(int _Column)
{
    Column = _Column;
}

int Step::GetColumn()
{
    return Column;
}
