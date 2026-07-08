#ifndef SERVER_HPP
    #define SERVER_HPP

#include "Utils.hpp"

namespace Factory::Server
{
    class ServerManager
    {
        private:
            std::string _host;
            int _port;
        public:
            ServerManager();
            ~ServerManager() = default;
            
            int init(std::string host, int port);
            int run();
            void getEvents();
    };
}

#endif // SERVER_HPP