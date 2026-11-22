#include"Interface.h"


Bullet Interface::input_bullet_data()
{
    Bullet bullet;
    int choice; 
    
    std::cout<< "Ballistic Calculator "<< '\n' <<"please enter the values: " << std::endl;
    
    
    while (true)
    {
        std::cout<< "Mass bullet = ";
        if ((std::cin >> bullet.mass)&& bullet.mass > 0) {
            break; 
        } 
        else{
            std::cout << "Error: Please enter a valid number!" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
    }

    std::cout<< "Name bullet = ";
    std::cin >> bullet.form_name;

    
    while (true)
    {
        std::cout << "Ballistic coefficient = ";
        if ((std::cin >> bullet.ballistic_coefficient) && (bullet.ballistic_coefficient < 1) && (bullet.ballistic_coefficient > 0)) {
            break; 
        } 
        else {
            std::cout << "Error: Please enter a valid number!" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    bool isRunning = true;

    std::cout << "Choose one environment:\n"
            << "1: Environment 1\n"
            << "2: Environment 2\n"
            << "3: Environment 3\n";

    while (isRunning) 
    {
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            std::cout << "Error: Please enter a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) 
        {
            case 1:
                std::cout << "You chose Environment 1\n";

                isRunning = false;
                break;
                
            case 2:
                std::cout << "You chose Environment 2\n";

                isRunning = false;
                break;
                
            case 3:
                std::cout << "You chose Environment 3\n";

                isRunning = false;
                break;
            default:
                std::cout << "Invalid environment! Please choose 1, 2, or 3.\n";

                break;
        }
    }

    std::cout <<'\n' <<"Name bullet = "<< bullet.form_name << std::endl;
    std::cout << "Mass bullet = "<< bullet.mass << std::endl;
    std::cout << "Ballistic coefficient = "<< bullet.ballistic_coefficient<<std::endl;
    std::cout << "Environment = "<< choice << std::endl;
    

    // while (true)
    // {
    //     std::cout<< "Name bullet = ";
    //     if (std::cin >> bullet.form_name) {
    //         break; 
    //     } 
    //     else{
    //         std::cout << "Error: Please enter a valid name!" << std::endl;
    //         std::cin.clear(); 
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //     }
        
    // }


    return bullet;
}