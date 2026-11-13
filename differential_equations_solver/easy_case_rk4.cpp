/*
dx/dt = vx
dy/dt = vy
dvx/dt = 0
dvy/dt = -g
Система уравнений вида Y' = F(t, Y)
К каждому применяем РК4
*/

#include <iostream>
#include <cmath>

struct State 
{
    double x, y, vx, vy;
};

// Правые части уравнений dY/dt = f(t, Y)
State derivatives(double t, const State& s, double g) 
{
    return 
    {
        s.vx,   // dx/dt = vx
        s.vy,   // dy/dt = vy
        0.0,    // dvx/dt = 0
        -g      // dvy/dt = -g
    };
}

// Шаг метода Рунге-Кутты 4-го порядка
State rk4_step(double t, const State& s, double dt, double g) 
{
    State k1 = derivatives(t, s, g);
    
    State s2 = 
    {
        s.x  + 0.5 * dt * k1.x,
        s.y  + 0.5 * dt * k1.y,
        s.vx + 0.5 * dt * k1.vx,
        s.vy + 0.5 * dt * k1.vy
    };

    State k2 = derivatives(t + 0.5 * dt, s2, g);
    
    State s3 = 
    {
        s.x  + 0.5 * dt * k2.x,
        s.y  + 0.5 * dt * k2.y,
        s.vx + 0.5 * dt * k2.vx,
        s.vy + 0.5 * dt * k2.vy
    };

    State k3 = derivatives(t + 0.5 * dt, s3, g);
    
    State s4 = 
    {
        s.x  + dt * k3.x,
        s.y  + dt * k3.y,
        s.vx + dt * k3.vx,
        s.vy + dt * k3.vy
    };

    State k4 = derivatives(t + dt, s4, g);
    
    return 
    {
        s.x  + (dt / 6.0) * (k1.x  + 2.0 * k2.x  + 2.0 * k3.x  + k4.x),
        s.y  + (dt / 6.0) * (k1.y  + 2.0 * k2.y  + 2.0 * k3.y  + k4.y),
        s.vx + (dt / 6.0) * (k1.vx + 2.0 * k2.vx + 2.0 * k3.vx + k4.vx),
        s.vy + (dt / 6.0) * (k1.vy + 2.0 * k2.vy + 2.0 * k3.vy + k4.vy)
    };
}

int main() {
    double v0 = 50.0;              // Начальная скорость (м/с)
    double angle_deg = 45.0;       // Угол броска к горизонту (градусы)
    double g = 9.81;               // Ускорение свободного падения (м/с²)
    
    double dt = 0.05;              // Шаг интегрирования (с)
    double t = 0.0;
    
    double angle_rad = angle_deg * M_PI / 180.0;
    State state = 
    {
        0.0, 
        0.0, 
        v0 * std::cos(angle_rad), 
        v0 * std::sin(angle_rad)
    };
    
    //std::cout << "t\tx\ty\tvx\tvy\n";
    
    // Интегрируем, пока тело находится над землей (y >= 0)
    while (state.y >= 0.0) 
    {
        std::cout << "(" << state.x << ", " << state.y << ")\n";
    
        state = rk4_step(t, state, dt, g);
        t += dt;
    }
    
    return 0;
}