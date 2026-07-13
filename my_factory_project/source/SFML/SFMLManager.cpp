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
            settings.antialiasingLevel = 8;
            _window = std::make_unique<sf::RenderWindow>(
                sf::VideoMode(1280, 720),
                PROJECT_TITLE,
                sf::Style::Default,
                settings
            );
            _window->setPosition(sf::Vector2i(50, 50));
            _window->setSize(sf::Vector2u(1280, 720));
            _window->setFramerateLimit(120);
        } catch (const std::exception& e) {
            logger.log("SFML", "Error: could not create window.", e);
            return OUTPUT::ERROR;
        }

        if (!_base_text_font.loadFromFile("resources/fonts/Ubuntu.ttf")) {
            logger.log("SFML", "Could not load font from resources/fonts/Ubuntu.ttf", "Font file not found");
            return OUTPUT::ERROR;
        }
        _fontLoaded = true;

        try {
            _simplifiedSFML = std::make_unique<SimplifiedSFML>();
        } catch (const std::exception& e) {
            logger.log("SFML", "Error: could not create SimplifiedSFML instance.", e);
            return OUTPUT::ERROR;
        }
        return OUTPUT::NOERROR;
    }

    void SFMLManager::getInput()
    {
        if (!_window) {
            return;
        }

        const float dt = _delta.restart().asSeconds();

        if (_player) {
            _player->update(dt);
        }

        sf::Event sfEvent;
        while (_window->pollEvent(sfEvent)) {
            if (sfEvent.type == sf::Event::Closed ||
                (sfEvent.type == sf::Event::KeyPressed &&
                 sfEvent.key.code == sf::Keyboard::Escape))
            {
                _window->close();
            }
        }
    }

    void SFMLManager::render()
    {
        if (!_window) {
            return;
        }

        _window->clear(sf::Color(15, 15, 25));
        if (_circle) {
            _circle->render(*_window);
        }
        if (_line) {
            _line->render(*_window);
        }
        if (_player) {
            _player->render(*_window);
        }

        _window->display();
    }
    const sf::RenderWindow& SFMLManager::getWindow(void)
    {
        if (_window) {
            return *_window;
        }
        logger.log("SFML", "tried to access window but it is not initialized");
        throw std::runtime_error("Window not initialized");
    }
}