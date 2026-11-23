#include "Environment.h"

Environment::Environment()    : name("env"), wind_speed(0), wind_direction(0), g(9.81) {}

Environment::Environment(std::string name_, double wind_speed_, double wind_direction_, double g_)
    : name(name_), wind_speed(wind_speed_), wind_direction(wind_direction_), g(g_) {}

std::ostream &operator<<(std::ostream &stream, const Environment &rhs)
{
    stream << "Environment: " << rhs.name << " | ";
    stream << "Wind speed: " << rhs.wind_speed << "m/s" << " | ";
    stream << "Wind direction: " << rhs.wind_direction << "*";
    return stream;
}