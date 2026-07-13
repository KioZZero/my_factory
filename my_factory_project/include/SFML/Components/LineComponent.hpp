#ifndef LINECOMPONENT_HPP
    #define LINECOMPONENT_HPP

#include "AComponent.hpp"

#include <SFML/Graphics/VertexArray.hpp>

namespace Factory::SFML
{
    class LineComponent : public AComponent
    {
        private:
            sf::VertexArray _vertices;
            sf::Vector2f _end;
            float _thickness;
            sf::Color _color;

            void _rebuild();

        public:
            explicit LineComponent(sf::Vector2f start = {0.f, 0.f}, sf::Vector2f end = {100.f, 0.f}, float thickness = 2.f, sf::Color color = sf::Color::White, bool active = true);
            ~LineComponent() override = default;

            void update(float dt) override;
            void render(sf::RenderWindow& window) override;

            sf::Vector2f getEnd() const;
            float getThickness() const;
            sf::Color getColor() const;

            void setEnd(sf::Vector2f end);
            void setThickness(float thickness);
            void setColor(sf::Color color);
    };
}

#endif // LINECOMPONENT_HPP
