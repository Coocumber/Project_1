#include "Utils.h"

struct Task_param
{
public:
    double start_speed; // начальная скорость пули
    double target_distance; // дистанция до цели в метрах
    maths::vec3 target_distance[3]; // дистанция до цели в метрах
};
