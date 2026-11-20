#include "Calculator.h"

Calculator::Calculator(Bullet &bullet_, Environment &environment_,
     Task_param &start_params_, Target &target_) : 
     bullet(bullet_), environment(environment_), 
     start_params(start_params_), target(target_)
{
    bullet.velocity = {start_params.start_speed * std::cos(maths::radians(start_params.angle)),
                       start_params.start_speed * std::sin(maths::radians(start_params.angle)),
                        0};
}

void Calculator::process_bullet_motion(double dt)
{
    State state{bullet.coordinates, bullet.velocity};

    while (state.coordinates.y >= 0)
    {
        state = rk4_step(0, state, dt, environment.g, 0, bullet.mass);

        std::cout << "(" << state.coordinates.x << ", " << 
                            state.coordinates.y << ")" << std::endl;
    }
}
