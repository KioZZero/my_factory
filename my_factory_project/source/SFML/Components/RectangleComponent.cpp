#include "RectangleComponent.hpp"

namespace Factory::SFML
{
    RectangleComponent::RectangleComponent( sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, float outlineThickness, bool active) : AComponent(position, active)
    {
        _shape.setPosition(position);
        _shape.setSize(size);
        _shape.setFillColor(fillColor);
        _shape.setOutlineColor(outlineColor);
        _shape.setOutlineThickness(outlineThickness);
    }

    void RectangleComponent::update(float dt)
    {
        (void)dt;
    }

    void RectangleComponent::render(sf::RenderWindow& window)
    {
        if (!_active) {
            return;
        }
        window.draw(_shape);
    }

    void RectangleComponent::move(sf::Vector2f offset)
    {
        AComponent::move(offset);
        _shape.setPosition(_position);
    }

    sf::Vector2f RectangleComponent::getSize() const
    {
        return _shape.getSize();
    }

    void RectangleComponent::setSize(sf::Vector2f size)
    {
        _shape.setSize(size);
    }

    void RectangleComponent::setFillColor(sf::Color color)
    {
        _shape.setFillColor(color);
    }

    void RectangleComponent::setOutlineColor(sf::Color color)
    {
        _shape.setOutlineColor(color);
    }

    void RectangleComponent::setOutlineThickness(float thickness)
    {
        _shape.setOutlineThickness(thickness);
    }

    sf::FloatRect RectangleComponent::getBounds() const
    {
        return _shape.getGlobalBounds();
    }
}
