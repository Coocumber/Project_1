#include "Calculator.h"

Calculator::Calculator(Bullet &bullet_, Environment &environment_,
     Task_param &start_params_, Target &target_) : 
     bullet(bullet_), environment(environment_), 
     start_params(start_params_), target(target_)
{
}

void Calculator::process_bullet_motion(double dt)
{

}
