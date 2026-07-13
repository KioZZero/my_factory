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
            logger.log("CORE", "Server initialized successfully");
        } catch (const std::exception& e) {
            logger.log("CORE", "Server init failed", e);
            return OUTPUT::ERROR;
        }
        try {
            _preloader = std::make_unique<Factory::Preloader::PreloaderManager>();
            _preloader->init();
            logger.log("CORE", "Preloader initialized successfully");
        } catch (const std::exception& e) {
            logger.log("CORE", "Preloader init failed", e);
            return OUTPUT::ERROR;
        }
        try {
            _sfmlManager = std::make_unique<Factory::SFML::SFMLManager>();
            _sfmlManager->init();
            logger.log("CORE", "SFML manager initialized successfully");
        } catch (const std::exception& e) {
            logger.log("CORE", "SFML manager init failed", e);
            return OUTPUT::ERROR;
        }
        return OUTPUT::NOERROR;
    }

    int Core::run(std::string host, int port)
    {
        if (init(host, port) != OUTPUT::NOERROR) {
            ERR("CORE Failed to initialize core");
            return OUTPUT::ERROR;
        }
        return loop();
    }

    void Core::manageInput(void)
    {
        _sfmlManager->getInput();
    }

    int Core::loop(void)
    {
        MSG("CORE Running...");
        while (_sfmlManager->getWindow().isOpen())
        {
            manageInput();
            _sfmlManager->render();
        }
        MSG("CORE Stopping...");
        return OUTPUT::NOERROR;
    }
}