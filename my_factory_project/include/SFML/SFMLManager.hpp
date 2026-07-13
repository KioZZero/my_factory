#ifndef SFMLMANAGER_HPP
    #define SFMLMANAGER_HPP

#include "Utils.hpp"

#include "SimplifiedSFML.hpp"
#include "LogManager.hpp"

#include "Components/PlayerComponent.hpp"
#include "Components/CircleComponent.hpp"
#include "Components/LineComponent.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <memory>

namespace Factory::SFML
{
    class SFMLManager
    {
        private:
            sf::Clock _delta;
            std::unique_ptr<sf::RenderWindow> _window;
            std::unique_ptr<Factory::SFML::SimplifiedSFML> _simplifiedSFML;
            sf::Font _base_text_font;
            bool _fontLoaded;

            std::unique_ptr<PlayerComponent> _player;
            std::unique_ptr<CircleComponent> _circle;
            std::unique_ptr<LineComponent> _line;
        public:
            SFMLManager();
            ~SFMLManager();

            int init();
            void getInput();
            void render();
            const sf::RenderWindow& getWindow(void);
    };
}

#endif // SFMLMANAGER_HPP