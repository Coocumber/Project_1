#include "Interface.h"

Bullet Interface::input_bullet_data()
{
    Bullet bullet;

    std::cout << "Ballistic Calculator " << '\n'
              << "please enter the values: " << std::endl;

    while (true)
    {
        std::cout << "Mass bullet = ";
        if (std::cin >> bullet.mass)
        {
            break;
        }
        else
        {
            std::cout << "Error: Please enter a valid number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    while (true)
    {
        std::cout << "Name bullet = ";
        if (std::cin >> bullet.form_name)
        {
            break;
        }
        else
        {
            std::cout << "Error: Please enter a valid name!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return bullet;
}