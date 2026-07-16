#ifndef PLAYERCOMPONENT_HPP
    #define PLAYERCOMPONENT_HPP

#include "AComponent.hpp"

#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace Factory::SFML
{
    class PlayerComponent : public AComponent
    {
        private:
            sf::ConvexShape _shape;
            float _speed = 1.f;

        public:
            PlayerComponent(sf::Vector2f position, sf::Vector2f size = {32.f, 32.f}, float speed = 200.f, sf::Color color = sf::Color(100, 200, 255), bool active = true);
            ~PlayerComponent() override = default;

            void update(float dt) override;
            void render(sf::RenderWindow& window) override;
            void move(sf::Vector2f offset) override;
            float getSpeed() const;
            void setSpeed(float speed);
            void setColor(sf::Color color);
            sf::FloatRect getBounds() const;
    };
}

#endif // PLAYERCOMPONENT_HPP
