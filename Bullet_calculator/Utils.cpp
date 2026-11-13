#include "Utils.h"

maths::vec3::vec3(std::initializer_list<double> elements)
{
    x = *elements.begin();
    y = *(elements.begin() + 1);
    z = *elements.end();
}

maths::vec3 maths::operator+(const vec3 &lhs, const vec3 &rhs)
{
    return vec3{lhs.x + rhs.x,
                lhs.y + rhs.y,
                lhs.z + rhs.z};
}

maths::vec3 maths::operator-(const vec3 &lhs, const vec3 &rhs)
{
    return vec3{lhs.x - rhs.x,
                lhs.y - rhs.y,
                lhs.z - rhs.z};
}

double maths::operator*(const vec3 &lhs, const vec3 &rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

double maths::length(const vec3 &vec)
{
    return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
