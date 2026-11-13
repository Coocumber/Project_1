/*
Пример вычисление диффура dy/dt = y - t^2 + 1 методом Рунге-Кутты 4 порядка
x0 = 0, y(x0) = 0.5
Аналитическое решение: (t + 1)^2 - 0.5*e^t
По алгоритму y(2) = 5.30161
Точное значение y(2) = (2 + 1)^2 - 0.5 * e^2 = 5.30547
*/

#include <iostream>

template <typename Func>
void rungeKutta4(Func f, double t0, double y0, double dt, double t_end) 
{
    double t = t0;
    double y = y0;

    std::cout << "t = " << t << ", y = " << y << "\n";

    while (t < t_end) 
    {
        if (t + dt > t_end) 
        {
            dt = t_end - t;
        }

        double k1 = f(t, y);
        double k2 = f(t + 0.5 * dt, y + 0.5 * dt * k1);
        double k3 = f(t + 0.5 * dt, y + 0.5 * dt * k2);
        double k4 = f(t + dt, y + dt * k3);

        y += (dt / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        t += dt;

        std::cout << "t = " << t << ", y = " << y << "\n";
    }
}

// Обычная функция
double myEquation(double t, double y) 
{
    return y - t * t + 1;
}

int main() 
{
    rungeKutta4(myEquation, 0.0, 0.5, 0.5, 2.0);

    return 0;
}