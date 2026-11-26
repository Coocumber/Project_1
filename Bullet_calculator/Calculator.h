#pragma once

#include "Bullet.h"
#include "Environment.h"
#include "Task_param.h"
#include "Target.h"
#include "Runge_kutta.h"
#include <cmath>
#include <vector>

/**
 * @brief Класс вычислений. Хранит ссылки на пулю, среду и условия задачи,
 *
 *
 */
class Calculator
{
private:
    Bullet& bullet;
    Environment environment;
    Task_param start_params;
    Target target;
    std::vector<maths::vec3> trajectory;

public:
    /**
     * @brief Создаёт объект типа Calculator.
     *
     * @param bullet_ пуля
     * @param environment_ среда
     * @param start_params_ начальные условия
     */
    Calculator(Bullet &bullet_, Environment &environment_, Task_param &start_params_);

    /**
     * @brief Рассчитывает движение пули за промежуток времени dt.
     * Меняет состояние пули! ВЫВОДИТ В КОНСОЛЬ КООРДИНАТЫ!!!
     *
     * @param dt шаг времени в мс
     * @return объект типа Target с координатами попадания пули
     */
    Target process_bullet_motion(double dt);
};