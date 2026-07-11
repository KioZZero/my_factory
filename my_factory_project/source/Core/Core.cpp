#include "Core.hpp"

namespace Factory::Core
{
    namespace
    {
        Log::LogManager& logger = Log::LogManager::instance();
    }

    Core::Core() : _server(std::make_unique<Factory::Server::ServerManager>()),
                   _preloader(std::make_unique<Factory::Preloader::PreloaderManager>()),
                   _sfmlManager(std::make_unique<Factory::SFML::SFMLManager>()) {}

    int Core::init(std::string host, int port)
    {
        try {
            _server = std::make_unique<Factory::Server::ServerManager>();
            _server->init(host, port);
            logger.log("SYSTEM", "Server initialized successfully");
        } catch (const std::exception& e) {
            logger.log("SYSTEM", "Server init failed", e);
            ERR(NAME << " Server init failed: " << e.what());
            return OUTPUT::ERROR;
        }
        try {
            _preloader = std::make_unique<Factory::Preloader::PreloaderManager>();
            _preloader->init();
            logger.log("SYSTEM", "Preloader initialized successfully");
        } catch (const std::exception& e) {
            logger.log("SYSTEM", "Preloader init failed", e);
            ERR(NAME << " Preloader init failed: " << e.what());
            return OUTPUT::ERROR;
        }
        try {
            _sfmlManager = std::make_unique<Factory::SFML::SFMLManager>();
            _sfmlManager->init();
            logger.log("SYSTEM", "SFML manager initialized successfully");
        } catch (const std::exception& e) {
            logger.log("SYSTEM", "SFML manager init failed", e);
            ERR(NAME << " SFML manager init failed: " << e.what());
            return OUTPUT::ERROR;
        }
        return OUTPUT::NOERROR;
    }

    int Core::run(std::string host, int port)
    {
        if (init(host, port) != OUTPUT::NOERROR) {
            ERR(NAME << " Failed to initialize core");
            return OUTPUT::ERROR;
        }
        MSG(NAME << " Running...");
        return loop();
    }

    void Core::manageInput(void)
    {
        _sfmlManager->getInput();
    }

    int Core::loop(void)
    {
        // while (LOOP)
        // {
        //     manageInput();
        //     _sfmlManager->getInput();
        //     _sfmlManager->render();
        // }

        MSG(NAME << " Stopping...");
        return OUTPUT::NOERROR;
    }
}