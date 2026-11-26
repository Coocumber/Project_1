#pragma once
#include<iostream>

struct Target
{
    double x; // Координата смещения по горизонтали
    double y; // Координата смещения по вертикали

    Target();
    Target(double x_, double y_);
    friend std::ostream &operator<<(std::ostream &stream, const Target &rhs);
};
