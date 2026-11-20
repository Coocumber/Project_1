#pragma once

/*
dx/dt = vx
dy/dt = vy
dz/dt = vz
dvx/dt = -k/m*v*vx, Fсопр = -Fсопр*V/v=-kv^2*V/v=-k*v*V
dvy/dt = -g-k/m*v*vy
dvz/dt = 0;
Система уравнений вида Y' = F(t, Y)
К каждому применяем РК4
*/

#include <iostream>
#include <cmath>
#include "Utils.h"

/**
 * @brief Состояние системы в данный момент времени
 * 
 */
struct State 
{
    maths::vec3 coordinates{};
    maths::vec3 velocity{};
};

/**
 * @brief Правые части уравнений dY/dt = f(t, Y)
 * 
 * @param t момент времени
 * @param s состояние системы
 * @param g ускорение свободного падения
 * @param k коэффициент сопротивления
 * @param m масса пули
 * @return State производные состояния системы
 */
State derivatives(double t, const State& s, double g, double k, double m) ;

/**
 * @brief Один шаг метода РК4
 * 
 * @param t начальное время
 * @param s состояние системы
 * @param dt малый шаг времени в секундах
 * @param g ускорение свободного падения
 * @param k коэффициент сопротивления
 * @param m масса
 * @return State состояние системы после шага
 */
State rk4_step(double t, const State& s, double dt, double g, double k, double m) ;