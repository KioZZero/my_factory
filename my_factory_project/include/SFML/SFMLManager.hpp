#ifndef SFMLMANAGER_HPP
    #define SFMLMANAGER_HPP

#include "Utils.hpp"

#include "SimplifiedSFML.hpp"
#include "LogManager.hpp"

#include "IComponent.hpp"
#include "PlayerComponent.hpp"
#include "CircleComponent.hpp"
#include "LineComponent.hpp"
#include "RectangleComponent.hpp"
#include "MessageComponent.hpp"

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

            std::vector<std::unique_ptr<IComponent>> _components;
            std::vector<PlayerComponent*> _player;
            int _focused_player = 0;
        public:
            SFMLManager();
            ~SFMLManager();

            int init();
            void getInput();
            void render();
            bool isOpen() const;
            const sf::RenderWindow& getWindow(void);
            sf::Font& getFont();
            void addComponent(std::unique_ptr<IComponent> component);
            void addPlayer(std::unique_ptr<PlayerComponent> player);
    };
}

#endif // SFMLMANAGER_HPP