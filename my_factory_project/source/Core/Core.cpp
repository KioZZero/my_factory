#include "Core.hpp"

namespace Factory::Core
{
    Core::Core() : _server(std::make_unique<Factory::Server::ServerManager>()), _preloader(std::make_unique<Factory::Preloader::PreloaderManager>()) {}

    int Core::init(std::string host, int port)
    {
        try {
            _server = std::make_unique<Factory::Server::ServerManager>();
            _server->init(host, port);
            MSG(NAME << " Server endpoint: " << host << ":" << port);
        } catch (const std::exception &e) {
            ERR(NAME << " Server init failed: " << e.what());
            return OUTPUT::ERROR;
        }
        try {
            _preloader = std::make_unique<Factory::Preloader::PreloaderManager>();
            _preloader->init();
            MSG(NAME << " Preloader initialized successfully");
        } catch (const std::exception &e) {
            ERR(NAME << " Preloader init failed: " << e.what());
            return OUTPUT::ERROR;
        }
        // init serveur 
        // init preloader
        return OUTPUT::NOERROR;
    }

    int Core::run(std::string host, int port)
    {
        init(host, port);

        MSG(NAME << " Running...");

        return loop();
    }

    int Core::loop(void)
    {
        return OUTPUT::NOERROR;
    }
}
