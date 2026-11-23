#pragma once

#include "Bullet.h"
#include "Environment.h"
#include "Calculator.h"

class Interface
{
public:
    Bullet input_bullet_data();
    // void input_env_data(Environment &env);
    Environment input_env_data();
    Task_param input_task_param_data();
    void SelectCalculate();
};