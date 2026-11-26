#include "Target.h"
Target::Target() : x(0), y(0)
{
}

Target::Target(double x_, double y_) : x(x_), y(y_)
{
}


std::ostream &operator<<(std::ostream &stream, const Target &rhs)
{
    stream << "Coordinat X: " << rhs.x << "|";
    stream << "Coordinat Y: " << rhs.y ;
    return stream;
}