#include "Server.hpp"

namespace Factory::Server
{
    ServerManager::ServerManager() : _host("127.0.0.1"), _port(8080) {}

    int ServerManager::init(std::string host, int port)
    {
        _host = host;
        _port = port;
        return OUTPUT::NOERROR;
    }
}