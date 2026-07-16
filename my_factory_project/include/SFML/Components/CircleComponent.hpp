#ifndef CIRCLECOMPONENT_HPP
    #define CIRCLECOMPONENT_HPP

#include "AComponent.hpp"

#include <SFML/Graphics/CircleShape.hpp>

namespace Factory::SFML
{
    class CircleComponent : public AComponent
    {
        protected:
            sf::CircleShape _shape;

        public:
            explicit CircleComponent(sf::Vector2f position = {0.f, 0.f}, float radius = 16.f, unsigned int pointCount = 30, sf::Color fillColor = sf::Color::White, sf::Color outlineColor = sf::Color::Transparent, float outlineThickness = 0.f, bool active = true);
            ~CircleComponent() override = default;

            void update(float dt) override;
            void render(sf::RenderWindow& window) override;
            void move(sf::Vector2f offset) override;

            float getRadius() const;
            void setRadius(float radius);
            void setFillColor(sf::Color color);
            void setOutlineColor(sf::Color color);
            void setOutlineThickness(float thickness);
            sf::FloatRect getBounds() const;
    };
}

#endif // CIRCLECOMPONENT_HPP
