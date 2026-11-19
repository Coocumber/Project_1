#include "Utils.h"

struct Task_param
{
public:
    double start_speed;     // начальная скорость пули
    double angle;           // угол наклона ствола в градусах
    double target_distance; // дистанция до цели в метрах
    Task_param(double start_speed_, double angle_, double target_distance_)
        : start_speed(start_speed_), angle(angle_), target_distance(target_distance_) {}
};
