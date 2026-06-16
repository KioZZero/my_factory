/*
** 2026
** my_factory
** File description:
** Utils.hpp
*/

#ifndef UTILS_HPP
    #define UTILS_HPP

    #include <string>
    #include <iostream>
    #include <ostream>
    #include <vector>
    #include <memory>
    
    struct Axis_t
    {
        Axis_t() : x(0.0f), y(0.0f), z(0.0f) {}
        Axis_t(float x, float y, float z) : x(x), y(y), z(z) {}

        float x;
        float y;
        float z;
    };

    #define ERROR 84
    #define NOERROR 0

    #define DEFAULT 0

    #define LOOP 1

    #define UNKNOWN -1

    #define MSG(msg) std::cout << msg << std::endl

int conditions(int argc, char *argv[]);


#endif // UTILS_HPP