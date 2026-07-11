#ifndef SFMLMANAGER_HPP
    #define SFMLMANAGER_HPP

#include "Utils.hpp"

#include "SimplifiedSFML.hpp"
#include "LogManager.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

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
        public:
            SFMLManager();
            ~SFMLManager();

            int init();
            void getInput();
            void render();
    };
}

#endif // SFMLMANAGER_HPP