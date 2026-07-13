#include "CircleComponent.hpp"

namespace Factory::SFML
{
    CircleComponent::CircleComponent(sf::Vector2f position, float radius, unsigned int pointCount, sf::Color fillColor, sf::Color outlineColor, float outlineThickness, bool active) : AComponent(position, active)
    {
        _shape.setRadius(radius);
        _shape.setPointCount(pointCount);
        _shape.setPosition(position - sf::Vector2f(radius, radius));
        _shape.setFillColor(fillColor);
        _shape.setOutlineColor(outlineColor);
        _shape.setOutlineThickness(outlineThickness);
    }

    void CircleComponent::update(float dt)
    {}

    void CircleComponent::render(sf::RenderWindow& window)
    {
        if (!_active) {
            return;
        }
        window.draw(_shape);
    }

    float CircleComponent::getRadius() const
    {
        return _shape.getRadius();
    }

    void CircleComponent::setRadius(float radius)
    {
        _shape.setRadius(radius);
        _shape.setPosition(_position - sf::Vector2f(radius, radius));
    }

    void CircleComponent::setFillColor(sf::Color color)
    {
        _shape.setFillColor(color);
    }

    void CircleComponent::setOutlineColor(sf::Color color)
    {
        _shape.setOutlineColor(color);
    }

    void CircleComponent::setOutlineThickness(float thickness)
    {
        _shape.setOutlineThickness(thickness);
    }

    sf::FloatRect CircleComponent::getBounds() const
    {
        return _shape.getGlobalBounds();
    }
}
