#include "Core.hpp"

namespace Factory::Core
{
    Core::Core() : _server(std::make_unique<Factory::Server::ServerManager>()),
                   _preloader(std::make_unique<Factory::Preloader::PreloaderManager>()),
                   _sfmlManager(std::make_unique<Factory::SFML::SFMLManager>()) {}

    int Core::init(std::string host, int port)
    {
        try {
            _logManager = std::make_unique<Log::LogManager>();
        } catch (const std::exception &e) {
            ERR(NAME << " Log manager init failed: " << e.what());
            return OUTPUT::ERROR;
        }
        try {
            _server = std::make_unique<Factory::Server::ServerManager>();
            _server->init(host, port);
            _logManager->log("SYSTEM", "Server initialized successfully");
        } catch (const std::exception &e) {
            _logManager->log("SYSTEM", "Server init failed", e);
            ERR(NAME << " Server init failed: " << e.what());
            return OUTPUT::ERROR;
        }
        try {
            _preloader = std::make_unique<Factory::Preloader::PreloaderManager>();
            _preloader->init();
            _logManager->log("SYSTEM", "Preloader initialized successfully");
        } catch (const std::exception &e) {
            _logManager->log("SYSTEM", "Preloader init failed", e);
            ERR(NAME << " Preloader init failed: " << e.what());
            return OUTPUT::ERROR;
        }
        try {
            _sfmlManager = std::make_unique<Factory::SFML::SFMLManager>();
            _sfmlManager->init();
            _logManager->log("SYSTEM", "SFML manager initialized successfully");
        } catch (const std::exception &e) {
            _logManager->log("SYSTEM", "SFML manager init failed", e);
            ERR(NAME << " SFML manager init failed: " << e.what());
            return OUTPUT::ERROR;
        }
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
        MSG(NAME << " Stopping...");
        return OUTPUT::NOERROR;
    }
}
