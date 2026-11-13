#include <iostream>
#include "Utils.h"

int main()
{
    maths::vec3 a{1, 0, 0};
    maths::vec3 b{1, 0, 1};

    std::cout << a * b << std::endl;

    auto c = a + b;

    c *= 2;
    std::cout << c.x << " " << c.y << " " << c.z << std::endl;

    c -= b;

    std::cout << c.x << " " << c.y << " " << c.z << std::endl;

    c.z = 4;

    std::cout << maths::length(c);

    return 0;
}