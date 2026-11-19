#include<iostream>
#include<string>
#include <limits>
// #include"Interface.h"


 int main() {
    double mass_bullet = 0.0 ;
    std::cout<< "Ballistic Calculator "<< '\n' <<"please enter the values: " << std::endl;
    
    
    while (true)
    {
        std::cout<< "Mass bullet = ";
        if (std::cin >> mass_bullet) {
            break; 
        } 
        else{
            std::cout << "Error: Please enter a valid number!" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
    }
    
    std::cout << "You entered: " << mass_bullet << std::endl;
    
    // std::cin>> mass_bullet;
    // std::cout<<mass_bullet<<std::endl;
    
    return 0 ;
}




