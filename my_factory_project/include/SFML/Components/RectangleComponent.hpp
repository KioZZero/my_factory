#ifndef RECTANGLECOMPONENT_HPP
    #define RECTANGLECOMPONENT_HPP

#include "AComponent.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

namespace Factory::SFML
{
    class RectangleComponent : public AComponent
    {
        protected:
            sf::RectangleShape _shape;

        public:
            explicit RectangleComponent(sf::Vector2f position = {0.f, 0.f}, sf::Vector2f size = {32.f, 32.f}, sf::Color fillColor = sf::Color::White, sf::Color outlineColor = sf::Color::Transparent, float outlineThickness = 0.f, bool active = true);
            ~RectangleComponent() override = default;

            void update(float dt) override;
            void render(sf::RenderWindow& window) override;

            sf::Vector2f getSize() const;
            void setSize(sf::Vector2f size);
            void setFillColor(sf::Color color);
            void setOutlineColor(sf::Color color);
            void setOutlineThickness(float thickness);
            sf::FloatRect getBounds() const;
    };
}

#endif // RECTANGLECOMPONENT_HPP
