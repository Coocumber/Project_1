#include "Task_param.h"

Task_param::Task_param()
    : start_speed(0), angle(0), target_distance(0)
{
}

Task_param::Task_param(double start_speed_, double angle_, double target_distance_)
    : start_speed(start_speed_), angle(angle_), target_distance(target_distance_)
{
}