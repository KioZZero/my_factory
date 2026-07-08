#include "Utils.hpp"
#include "Core.hpp"

#define DEFAULT_HOST "127.0.0.1"
#define DEFAULT_PORT 8080
#define HELP_FLAG "--help"
#define SIMPLIFIED_HELP_FLAG "-h"
#define PORT_FLAG "--port"
#define SIMPLIFIED_PORT_FLAG "-p"
#define HOST_FLAG "--hostname"
#define SIMPLIFIED_HOST_FLAG "-H"

static int display_help(void)
{
    MSG("USAGE\n"
     << "\t./my_factory [OPTIONS]\n"
     << "OPTIONS\n"
     << "\t-h, --help     Display this help message\n"
     << "\t-p, --port     Specify the port number\n"
     << "\t-H, --hostname Specify the hostname");
    return OUTPUT::NOERROR;
}

int conditions(int argc, char *argv[])
{
    std::string host = DEFAULT_HOST;
    int port = DEFAULT_PORT;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == SIMPLIFIED_HELP_FLAG || arg == HELP_FLAG) {
            return display_help();
        } else if ((arg == SIMPLIFIED_PORT_FLAG || arg == PORT_FLAG) && i + 1 < argc) {
            try {
                port = std::stoi(argv[++i]);
            } catch (const std::exception &e) {
                MSG("Error: Invalid port number");
                return OUTPUT::ERROR;
            }
        } else if ((arg == SIMPLIFIED_HOST_FLAG || arg == HOST_FLAG) && i + 1 < argc) {
            host = argv[++i];
        } else {
            MSG("Error: Unknown option '" << arg << "'");
            return OUTPUT::ERROR;
        }
    }

    Factory::Core::Core Core;
    Core.run(host, port);

    return OUTPUT::NOERROR;
}
