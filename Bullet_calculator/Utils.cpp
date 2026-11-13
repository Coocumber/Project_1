#include "Utils.h"

maths::vec3::vec3(std::initializer_list<double> elements)
{
    if (elements.size() < 3 || elements.size() > 3)
    {
        throw std::out_of_range("vec3 constructor requires 3 params");
    }
    
    x = *elements.begin();
    y = *(elements.begin() + 1);
    z = *(elements.end() - 1);
}

maths::vec3::vec3() : x(0), y(0), z(0)
{
}

maths::vec3::vec3(const vec3 &other)
{
    x = other.x, y = other.y, z = other.z;
}

maths::vec3 &maths::vec3::operator=(const vec3 &other)
{
    *this = vec3(other);
    return *this;
}

maths::vec3 &maths::vec3::operator+=(const vec3 &rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

maths::vec3 &maths::vec3::operator-=(const vec3 &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

maths::vec3 &maths::vec3::operator*=(double number)
{
    x *= number;
    y *= number;
    z *= number;
    return *this;
}

maths::vec3 maths::operator+(vec3 lhs, const vec3 &rhs)
{
    lhs += rhs;
    return lhs;
}

maths::vec3 maths::operator-(vec3 lhs, const vec3 &rhs)
{
    lhs -= rhs;
    return lhs;
}

double maths::operator*(const vec3 &lhs, const vec3 &rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

maths::vec3 maths::operator*(vec3 vec, double number)
{
    vec *= number;
    return vec;
}

double maths::length(const vec3 &vec)
{
    return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}