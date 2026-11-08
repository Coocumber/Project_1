#include <string>
#include <iostream>

struct Bullet
{
public:
    double weight;    // масса пули в мг
    std::string form; // возможна замена на name
    double ballistic_coefficient;
    double start_speed;
    double x, y, z; // Z - координата вдоль оси стрельбы
    // X, Y - декартова координаты с центром в точке прицеливания

    Bullet(double weight_, double start_speed, double x_finish, double y_finish, double z_finish);
    Bullet(double weight_, double start_speed, double ballistic_coefficient);

    friend std::ostream &operator<<(std::ostream &stream, const Bullet &rhs);
};
