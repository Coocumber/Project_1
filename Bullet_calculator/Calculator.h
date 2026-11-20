#pragma once

#include "Bullet.h"
#include "Environment.h"
#include "Task_param.h"
#include "Target.h"
#include "Runge_kutta.h"

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

public:
    /**
     * @brief Создаёт объект типа Calculator.
     *
     * @param bullet_ пуля
     * @param environment_ среда
     * @param start_params_ начальные условия
     * @param target_ минещь
     */
    Calculator(Bullet &bullet_, Environment &environment_, Task_param &start_params_,
    Target& target_);

    /**
     * @brief Рассчитывает движение пули за промежуток времени dt.
     * Меняет состояние пули!
     *
     * @param dt шаг времени в мс
     */
    void process_bullet_motion(double dt);
};