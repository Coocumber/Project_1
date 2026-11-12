#pragma once

#include "Bullet.h"
#include "Environment.h"

/**
 * @brief Класс вычислений. Хранит ссылки на пулю, среду и условия задачи,
 * 
 * 
 */
class Calculator
{
private:
    Bullet& bullet;
    Environment& environment;

public:
    /**
     * @brief Создаёт объект типа Calculator. 
     * 
     * @param bullet пуля
     * @param env среда
     */
    Calculator(Bullet &bullet, Environment &env);
    
    /**
     * @brief Рассчитывает движение пули за промежуток времени dt.
     * Меняет состояние пули!
     * 
     * @param dt шаг времени в мс
     */
    void process_bullet_motion(double dt);
};