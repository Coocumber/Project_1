#pragma once

#include <iostream>

struct Environment
{
    double wind_speed;
    double wind_direction;  // задаётся градусом относительно оси Z по часовой стрелке
    double g;               // ускорение свободного падения
    double target_distance; // дистанция до цели в метрах

    Environment(double wind_speed_, double wind_direction_, double g_, double target_distance_)
        : wind_speed(wind_speed_), wind_direction(wind_direction_), g(g_), target_distance(target_distance_) {}

    friend std::ostream &operator<<(std::ostream &stream, const Environment &rhs);
};
