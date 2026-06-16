/*
** 2026
** my_factory
** File description:
** conditions.cpp
*/

#include "Utils.hpp"
#include "Core.hpp"

static int display_help(void)
{
    MSG("USAGE");
    MSG("\t./my_factory [OPTIONS]");
    MSG("OPTIONS");
    MSG("\t-h, --help     Display this help message");
    return NOERROR;
}

int conditions(int argc, char *argv[])
{
    if (argc == 2) {
        std::string arg = argv[1];
        if (arg == "-h" || arg == "--help") { return display_help(); }
    }
    if (argc > 1) {
        MSG("Invalid arguments");
        for (int i = 1; i < argc; i++) {
            MSG(argv[i]);
        }
    }
    MSG("The program is now running...");
    
    Factory::Core::Core Core;
    Core.run();

    return ERROR;
}