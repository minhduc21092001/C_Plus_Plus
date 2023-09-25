#include<iostream>
#include"Player.h"

Player::Player() : Name(""), Win(0), Lose(0), Draw(0) {}

Player::~Player() {}

void Player::SetName(std::string _Name)
{
    Name = _Name;
}

std::string Player::GetName()
{
    return Name;
}

void Player::SetWin(int _Win)
{
    Win = _Win;
}

int Player::GetWin()
{
    return Win;
}

void Player::SetLose(int _Lose)
{
    Lose = _Lose;
}

int Player::GetLose()
{
    return Lose;
}

void Player::SetDraw(int _Draw)
{
    Draw = _Draw;
}

int Player::GetDraw()
{
    return Draw;
}
