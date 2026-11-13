#pragma once

#include <string>
#include <iostream>
#include "Utils.h"

struct Bullet
{
public:
    double mass;           // масса пули в мг
    std::string form_name; // возможна замена на name
    double ballistic_coefficient;
    maths::vec3 coordinates; // координаты пули в полёте x, y, z
    // Полёт вдоль oX, oY || g  и направлен вверх, oZ вправо по направлению полёта пули

    Bullet(std::string form_name, double mass_);
    Bullet(std::string form_name, double mass_, double ballistic_coefficient_);

    friend std::ostream &operator<<(std::ostream &stream, const Bullet &rhs);
};

inline Bullet::Bullet(std::string form_name, double mass_)
    : form_name(form_name), mass(mass_), coordinates({0, 0, 0})
{
}

Bullet::Bullet(std::string form_name, double mass_, double ballistic_coefficient_)
    : form_name(form_name), mass(mass_), ballistic_coefficient(ballistic_coefficient_)
{
}

std::ostream &operator<<(std::ostream &stream, const Bullet &rhs)
{
    stream << "Bullet: " << rhs.form_name << " | ";
    stream << "Mass " << rhs.mass * 1000 << "mg" << " | ";
    stream << "Ballistic_coefficient: " << rhs.ballistic_coefficient;
    return stream;
}
