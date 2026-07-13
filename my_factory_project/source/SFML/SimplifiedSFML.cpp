#include "SimplifiedSFML.hpp"

#include <cmath>

namespace Factory::SFML
{
    sf::RectangleShape SimplifiedSFML::makeRect( sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, float outlineThickness)
    {
        sf::RectangleShape rect;

        rect.setSize(size);
        rect.setPosition(position);
        rect.setFillColor(fillColor);
        rect.setOutlineColor(outlineColor);
        rect.setOutlineThickness(outlineThickness);

        return rect;
    }

    sf::CircleShape SimplifiedSFML::makeCircle(sf::Vector2f position, float radius, unsigned int pointCount, sf::Color fillColor, sf::Color outlineColor, float outlineThickness)
    {
        sf::CircleShape circle(radius, pointCount);

        circle.setPosition(position - sf::Vector2f(radius, radius));
        circle.setFillColor(fillColor);
        circle.setOutlineColor(outlineColor);
        circle.setOutlineThickness(outlineThickness);
        
        return circle;
    }

    sf::VertexArray SimplifiedSFML::makeLine(sf::Vector2f start, sf::Vector2f end, float thickness, sf::Color color)
    {
        sf::Vector2f dir = end - start;
        float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);

        sf::VertexArray va(sf::TriangleStrip, 4);

        if (length < 0.001f) {
            for (int i = 0; i < 4; ++i) {
                va[i].position = start;
                va[i].color = color;
            }
            return va;
        }

        sf::Vector2f perp(-dir.y / length, dir.x / length);
        perp *= (thickness * 0.5f);

        va[0].position = start + perp;
        va[1].position = start - perp;
        va[2].position = end + perp;
        va[3].position = end - perp;

        for (int i = 0; i < 4; ++i) {
            va[i].color = color;
        }

        return va;
    }
}