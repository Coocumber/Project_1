#pragma once

#include <iostream>
#include <string>

struct Environment
{
    std::string name;
    double wind_speed;     // скорость ветра в м/с
    double wind_direction; // задаётся градусом относительно оси вдоль которой летит пуля по часовой стрелке
    double g;              // ускорение свободного падения

    Environment(std::string name, double wind_speed_, double wind_direction_, double g_);

    friend std::ostream &operator<<(std::ostream &stream, const Environment &rhs);
};

inline Environment::Environment(std::string name_, double wind_speed_, double wind_direction_, double g_)
    : name(name), wind_speed(wind_speed_), wind_direction(wind_direction_), g(g_) {}

std::ostream &operator<<(std::ostream &stream, const Environment &rhs)
{
    stream << "Environment: " << rhs.name << " | ";
    stream << "Wind speed: " << rhs.wind_speed << "m/s" << " | ";
    stream << "Wind direction: " << rhs.wind_direction << "*";
    return stream;
}
