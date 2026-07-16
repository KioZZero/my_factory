#include "LineComponent.hpp"

#include <cmath>

namespace Factory::SFML
{
    LineComponent::LineComponent(sf::Vector2f start, sf::Vector2f end, float thickness, sf::Color color, bool active) : AComponent(start, active), _vertices(sf::TriangleStrip, 4), _end(end), _thickness(thickness), _color(color)
    {
        _rebuild();
    }

    void LineComponent::_rebuild()
    {
        sf::Vector2f dir = _end - _position;
        float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);

        if (length < 0.001f) {
            for (unsigned int i = 0; i < 4; ++i) {
                _vertices[i].position = _position;
                _vertices[i].color    = _color;
            }
            return;
        }

        sf::Vector2f perp(-dir.y / length, dir.x / length);
        perp *= (_thickness * 0.5f);

        _vertices[0].position = _position + perp;
        _vertices[1].position = _position - perp;
        _vertices[2].position = _end + perp;
        _vertices[3].position = _end - perp;

        for (unsigned int i = 0; i < 4; ++i) {
            _vertices[i].color = _color;
        }
    }

    void LineComponent::update(float dt)
    {
        (void)dt;
    }

    void LineComponent::render(sf::RenderWindow& window)
    {
        if (!_active) {
            return;
        }
        window.draw(_vertices);
    }

    void LineComponent::move(sf::Vector2f offset)
    {
        AComponent::move(offset);
        _end += offset;
        _rebuild();
    }

    sf::Vector2f LineComponent::getEnd() const
    {
        return _end;
    }

    float LineComponent::getThickness() const
    {
        return _thickness;
    }

    sf::Color LineComponent::getColor() const
    {
        return _color;
    }

    void LineComponent::setEnd(sf::Vector2f end)
    {
        _end = end;
        _rebuild();
    }

    void LineComponent::setThickness(float thickness)
    {
        _thickness = thickness;
        _rebuild();
    }

    void LineComponent::setColor(sf::Color color)
    {
        _color = color;
        _rebuild();
    }
}
