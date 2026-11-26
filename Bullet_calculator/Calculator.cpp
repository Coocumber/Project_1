#include "Calculator.h"

Calculator::Calculator(Bullet &bullet_, Environment &environment_,
     Task_param &start_params_) : 
     bullet(bullet_), environment(environment_), 
     start_params(start_params_)
{
    bullet.velocity = {start_params.start_speed * std::cos(maths::radians(start_params.angle)),
                       start_params.start_speed * std::sin(maths::radians(start_params.angle)),
                        0};
}

Target Calculator::process_bullet_motion(double dt)
{
    State state{bullet.coordinates, bullet.velocity};

    while (state.coordinates.y >= 0 && state.coordinates.x >= start_params.target_distance)
    {
        state = rk4_step(0, state, dt / 1000.0, environment.g, 0, bullet.mass);

        /*
        std::cout << "(" << state.coordinates.x << ", " << 
                            state.coordinates.y << ")" << std::endl;
        */

        trajectory.push_back(state.coordinates);
    }

    target.x = bullet.coordinates.z;
    target.y = bullet.coordinates.y;

    return target;
}
