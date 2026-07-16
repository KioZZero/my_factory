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
            
            int getPort();
            std::string getHost();
            int init(std::string host, int port);
            int run();
            void getEvents();
    };
} // Factory::Server

#endif // SERVER_HPP