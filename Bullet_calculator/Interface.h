#include "Bullet.h"
#include "Environment.h"
#include "Calculator.h"

class Interface
{
public:
    void input_bullet_data(Bullet &bullet);
    void input_env_data(Environment &env);

    void calc_out(Calculator &calc);
};