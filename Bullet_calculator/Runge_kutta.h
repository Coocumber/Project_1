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

struct State 
{
    maths::vec3 coordinates{};
    maths::vec3 velocity{};
};

// Правые части уравнений dY/dt = f(t, Y)
State derivatives(double t, const State& s, double g, double k, double m) 
{
    return 
    {
        {s.velocity.x, s.velocity.y, s.velocity.z},  // dx/dt = V
        {-k/m * maths::length(s.velocity) * s.velocity.x, // dvx/dt = -k/m*V*vx 
        -g - k/m * maths::length(s.velocity) * s.velocity.y, 0}  // dvy/dt = -g - k/m*V*vy
    };
}

State rk4_step(double t, const State& s, double dt, double g, double k, double m) 
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