#pragma once

#include <limits>
#include <string>
#include <iostream>
#include "Utils.h"

struct Bullet
{
public:
    double mass;                  // масса пули в мг
    std::string form_name;        // возможна замена на name
    double ballistic_coefficient; // баллистичесаий коэффициент (БК)
    maths::vec3 coordinates;      // координата пули в данный момент времени
    maths::vec3 velocity;         // координаты пули в полёте x, y, z
    // Полёт вдоль oX, oY || g  и направлен вверх, oZ вправо по направлению полёта пули

    Bullet();
    Bullet(std::string form_name, double mass_);
    Bullet(std::string form_name, double mass_, double ballistic_coefficient_);

    friend std::ostream &operator<<(std::ostream &stream, const Bullet &rhs);
};