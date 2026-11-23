#include"Interface.h"


Bullet Interface::input_bullet_data()
{
    Bullet bullet;

    
    std::cout<< "Ballistic Calculator "<< '\n'<<'\n' <<"please enter the values: " << std::endl;
    
    
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
   return bullet;
}

Environment Interface::input_env_data()
{
    Environment environment;
    int choice; 
    std::cout << "\nChoose one environment:\n"
            << "1: Environment 1:\n PEEEEVO\n"<<"wind speed= 12 m/s,"<<'\n'<<"wind direction= 67"<<'\n'<<"g = 9.81"<<'\n';
    bool isRunning = true;  
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
                environment.name = "PEEEEVO";
                environment.g = 9.81;
                environment.wind_speed = 12;
                environment.wind_direction = 67;
                isRunning = false;
                break;
            default:
                std::cout << "Invalid environment! Please choose 1.\n";

                break;
        }
    }
    return Environment();
}

Task_param Interface::input_task_param_data()
{
    Task_param task_param;
 
    std::cout<< "Task parameters "<< '\n'<<'\n' <<"please enter the values: " << std::endl;
    
    
    while (true)
    {
        std::cout<< "Start speed = ";
        if ((std::cin >> task_param.start_speed)&& task_param.start_speed > 0) {
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
        std::cout<< "Angle = ";
        if ((std::cin >> task_param.angle)&& (task_param.angle > 0)&& (task_param.angle < 180)) {
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
        std::cout<< "Target distance = ";
        if ((std::cin >> task_param.target_distance)&& task_param.target_distance > 0) {
            break; 
        } 
        else{
            std::cout << "Error: Please enter a valid number!" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
    }

    return task_param;
}

void Interface::SelectCalculate()
{
    Task_param task_param ;
    Environment env;
    Bullet bull;
    int choice; 
    std::cout << "\nSelect a calculation method:\n"
            << "1: Method1:\n calculate the final coordinates of the bullet\n"<<'\n';
    bool isRunning = true;  
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
                std::cout << "You chose Method1\n";
                bull = input_bullet_data();
                env = input_env_data();
                task_param = input_task_param_data();
                isRunning = false;
                break;
            default:
                std::cout << "Invalid environment! Please choose 1.\n";

                break;
        }
    }

}
