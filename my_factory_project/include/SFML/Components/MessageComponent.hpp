#ifndef MESSAGECOMPONENT_HPP
    #define MESSAGECOMPONENT_HPP

#include "AComponent.hpp"

#include <SFML/Graphics.hpp>

namespace Factory::SFML
{
    class MessageComponent : public AComponent
    {
        private:
            sf::Text _text;
            sf::Color _color;

        public:
            MessageComponent(const std::string& message, const sf::Font& font, sf::Vector2f position, unsigned int charSize = 16, sf::Color color = sf::Color::White, bool active = true);
            ~MessageComponent() override = default;

            void update(float dt) override;
            void render(sf::RenderWindow& window) override;
            void setMessage(const std::string& message);
            std::string getMessage() const;
            void setCharSize(unsigned int size);
            void setColor(sf::Color color);
    };
}

#endif // MESSAGECOMPONENT_HPP
