#ifndef CORE_HPP
    #define CORE_HPP

#include "Utils.hpp"
#include "Server.hpp"
#include "Preloader.hpp"

#define NAME "[CORE]"

namespace Factory::Core
{
    #include "CCharacter.hpp"

    class Core
    {
        private:
            std::unique_ptr<Factory::Server::ServerManager> _server;
            std::unique_ptr<Factory::Preloader::PreloaderManager> _preloader;
        public:
            Core();
            ~Core() = default;
            
            int init(std::string host, int port);
            int run(std::string host, int port);
            int loop(void);
    };
}

#endif // CORE_HPP