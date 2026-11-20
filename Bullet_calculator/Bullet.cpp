#include "Bullet.h"

Bullet::Bullet()
    : form_name("bullet"), mass(0), coordinates({0, 0, 0})
{
}

Bullet::Bullet(std::string form_name, double mass_)
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