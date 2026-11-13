#pragma once

#include "Bullet.h"
#include "Environment.h"
#include "Task_param.h"

/**
 * @brief Класс вычислений. Хранит ссылки на пулю, среду и условия задачи,
 *
 *
 */
class Calculator
{
private:
    Bullet bullet;
    Environment environment;
    Task_param start_params;

public:
    /**
     * @brief Создаёт объект типа Calculator.
     *
     * @param bullet пуля
     * @param env среда
     */
    Calculator(Bullet &bullet_, Environment &environment_, Task_param &start_params_);

    /**
     * @brief Рассчитывает движение пули за промежуток времени dt.
     * Меняет состояние пули!
     *
     * @param dt шаг времени в мс
     */
    void process_bullet_motion(double dt);
};