#ifndef UTILS_HPP
    #define UTILS_HPP

    #include <string>
    #include <iostream>
    #include <ostream>
    #include <vector>
    #include <memory>
    
    struct Axis_t
    {
        Axis_t() : x(0.f), y(0.f), z(0.f) {}
        Axis_t(float x, float y, float z) : x(x), y(y), z(z) {}

        float x;
        float y;
        float z;
    };

    enum OUTPUT {
        ERROR = 84,
        NOERROR = 0,
    };

    #define PROJECT_NAME "Factory"
    #define PROJECT_MAJOR "0"
    #define PROJECT_MINOR "0"
    #define PROJECT_PATCH "0"
    #define PROJECT_BUILD "0"
    #define PROJECT_VERSION PROJECT_MAJOR "." PROJECT_MINOR "." PROJECT_PATCH "." PROJECT_BUILD
    #define PROJECT_TITLE PROJECT_NAME " " PROJECT_VERSION

    #define DEFAULT 0

    #define LOOP 1

    #define UNKNOWN -1

    #define MSG(msg) std::cout << msg << std::endl
    #define ERR(msg) std::cerr << msg << std::endl

int conditions(int argc, char *argv[]);


#endif // UTILS_HPP