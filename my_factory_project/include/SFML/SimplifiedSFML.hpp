#ifndef SIMPLIFIEDSFML_HPP
    #define SIMPLIFIEDSFML_HPP

#include "Utils.hpp"

#include <SFML/Graphics.hpp>

namespace Factory::SFML
{
    class SimplifiedSFML
    {
        public:
            SimplifiedSFML() = default;
            ~SimplifiedSFML() = default;

            static sf::RectangleShape makeRect(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor = sf::Color::White, sf::Color outlineColor = sf::Color::Transparent, float outlineThickness = 0.f);
            static sf::CircleShape makeCircle(sf::Vector2f position, float radius, unsigned int pointCount = 30, sf::Color fillColor = sf::Color::White, sf::Color outlineColor = sf::Color::Transparent, float outlineThickness = 0.f );
            static sf::VertexArray makeLine(sf::Vector2f start, sf::Vector2f end, float thickness = 2.f, sf::Color color = sf::Color::White);
    };
}

#endif // SIMPLIFIEDSFML_HPP