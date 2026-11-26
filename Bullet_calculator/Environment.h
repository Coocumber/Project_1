#pragma once

#include <iostream>
#include <string>

struct Environment
{
    std::string name;      // Название средыы
    double wind_speed;     // скорость ветра в м/с
    double wind_direction; // задаётся градусом относительно оси вдоль которой летит пуля по часовой стрелке
    double g;              // ускорение свободного падения
    Environment();
    Environment(std::string name, double wind_speed_, double wind_direction_, double g_);

    friend std::ostream &operator<<(std::ostream &stream, const Environment &rhs);
};
