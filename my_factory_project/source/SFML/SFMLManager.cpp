#include "SFMLManager.hpp"

namespace Factory::SFML
{
    namespace
    {
        Log::LogManager& logger = Log::LogManager::instance();
    }

    SFMLManager::SFMLManager() : _window(nullptr), _fontLoaded(false) {}

    SFMLManager::~SFMLManager()
    {
        if (_window) {
            _window->close();
        }
    }

    int SFMLManager::init()
    {
        try {
            sf::ContextSettings settings;
            settings.antialiasingLevel = 4;

            _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1280, 720), PROJECT_TITLE, sf::Style::Default, settings);
            _window->setPosition(sf::Vector2i(50, 50));
            _window->setSize(sf::Vector2u(1280, 720));
            _window->setFramerateLimit(120);
        } catch (const std::exception& e) {
            logger.log("SFML", "Error: could not create window.", e);
            ERR("[SFML] Error: could not create window.");
            return OUTPUT::ERROR;
        }
        if (_base_text_font.loadFromFile("resources/fonts/Ubuntu.ttf")) {
            _fontLoaded = true;
        } else {
            logger.log("SFML", "Warning: could not load a system font. Text will be disabled.");
            ERR("[SFML] Warning: could not load a system font. Text will be disabled.");
            return OUTPUT::ERROR;
        }
        return OUTPUT::NOERROR;
    }

    void SFMLManager::getInput()
    {

    }
    
    void SFMLManager::render()
    {

    }

}