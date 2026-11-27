#include "Runge_kutta.h"
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
State derivatives(double t, const State& s, double g, double k, double m, const maths::vec3& wind) 
{
    maths::vec3 v_rel = s.velocity - wind;
    double v_rel_len = maths::length(v_rel);

    return 
    {
        {s.velocity.x, s.velocity.y, s.velocity.z},  // dx/dt = V
        {-k/m * maths::length(s.velocity) * s.velocity.x, // dvx/dt = -k/m*V*vx 
        -g - k/m * maths::length(s.velocity) * s.velocity.y, 0}  // dvy/dt = -g - k/m*V*vy
    };
}

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
State rk4_step(double t, const State& s, double dt, double g, double k, double m, const maths::vec3& wind) 
{
    State k1 = derivatives(t, s, g, k, m);
    State s2 = 
    {
        s.coordinates  + k1.coordinates * 0.5 * dt,
        s.velocity + k1.velocity * 0.5 * dt
    };

    State k2 = derivatives(t + 0.5 * dt, s2, g, k, m);
    State s3 = 
    {
        s2.coordinates  + k2.coordinates * 0.5 * dt,
        s2.velocity + k2.velocity * 0.5 * dt
    };

    State k3 = derivatives(t + 0.5 * dt, s3, g, k, m);
    State s4 = 
    {
        s3.coordinates  + k3.coordinates * 0.5 * dt,
        s3.velocity + k3.velocity * 0.5 * dt
    };

    State k4 = derivatives(t + dt, s4, g, k, m);
    
    return 
    {
        s.coordinates + (dt / 6.0) * (k1.coordinates + 2.0 * k2.coordinates +
        2.0 * k3.coordinates + k4.coordinates),
        s.velocity + (dt / 6.0) * (k1.velocity + 2.0 * k2.velocity +
        2.0 * k3.velocity + k4.velocity)
    };
}