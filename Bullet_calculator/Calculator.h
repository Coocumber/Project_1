#include "Bullet.h"
#include "Environment.h"

class Calculator
{
private:
    // Параметры пули
    double weight;    // масса пули в мг
    std::string form; // возможна замена на name
    double ballistic_coefficient;
    double start_speed;
    double x, y, z; // Z - координата вдоль оси стрельбы

    // Параметры среды
    double wind_speed;
    double wind_direction;  // задаётся градусом относительно оси Z по часовой стрелке
    double g;               // ускорение свободного падения
    double target_distance; // дистанция до цели в метрах

    // Параметры для подсчетов
    // --------------------------

public:
    Calculator(Bullet &bullet, Environment &env); // По идее просто переписывем параметры в private
};