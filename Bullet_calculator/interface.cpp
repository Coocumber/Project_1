#include"Interface.h"


Bullet Interface::input_bullet_data()
{
    Bullet bullet;
    
    std::cout<< "Ballistic Calculator "<< '\n' <<"please enter the values: " << std::endl;
    
    
    while (true)
    {
        std::cout<< "Mass bullet = ";
        if (std::cin >> bullet.mass) {
            break; 
        } 
        else{
            std::cout << "Error: Please enter a valid number!" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
    }

    while (true)
    {
        std::cout<< "Name bullet = ";
        if (std::cin >> bullet.form_name) {
            break; 
        } 
        else{
            std::cout << "Error: Please enter a valid name!" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
    }
    


    return bullet;
}




Bullet::Bullet(std::string form_name, double mass_)
    : form_name(form_name), mass(mass_), coordinates({0, 0, 0})
{
}

Bullet::Bullet(std::string form_name, double mass_, double ballistic_coefficient_)
    : form_name(form_name), mass(mass_), ballistic_coefficient(ballistic_coefficient_)
{
}

std::ostream &operator<<(std::ostream &stream, const Bullet &rhs)
{
    stream << "Bullet: " << rhs.form_name << " | ";
    stream << "Mass " << rhs.mass * 1000 << "mg" << " | ";
    stream << "Ballistic_coefficient: " << rhs.ballistic_coefficient;
    return stream;
}

