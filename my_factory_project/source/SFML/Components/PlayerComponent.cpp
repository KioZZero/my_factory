#include "PlayerComponent.hpp"

namespace Factory::SFML
{
    PlayerComponent::PlayerComponent(sf::Vector2f position, sf::Vector2f size, float speed, sf::Color color, bool active) : AComponent(position, active), _speed(speed)
    {
        const float size_x = size.x / 1.f;
        const float size_y = size.y / 1.f;

        _shape.setPointCount(6);
        _shape.setPoint(0, sf::Vector2f(-2.f * size_x, 0.f));
        _shape.setPoint(1, sf::Vector2f(-1.f * size_x, 1.f * size_y));
        _shape.setPoint(2, sf::Vector2f(0.f, 5.f * size_y));
        _shape.setPoint(3, sf::Vector2f(1.f * size_x, 1.f * size_y));
        _shape.setPoint(4, sf::Vector2f(2.f * size_x, 0.f));
        _shape.setPoint(5, sf::Vector2f(0.f, -2.f * size_y));
        _shape.setFillColor(color);
        _shape.setPosition(position);
    }

    void PlayerComponent::update(float dt)
    {
        if (!_active) {
            return;
        }

        sf::Vector2f velocity(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocity.y -= _speed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            velocity.y += _speed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity.x -= _speed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity.x += _speed * dt;
        }
        _position += velocity;
        _shape.setPosition(_position);
    }

    void PlayerComponent::render(sf::RenderWindow& window)
    {
        if (!_active) {
            return;
        }
        window.draw(_shape);
    }

    void PlayerComponent::move(sf::Vector2f offset)
    {
        AComponent::move(offset);
        _shape.setPosition(_position);
    }

    float PlayerComponent::getSpeed() const
    {
        return _speed;
    }

    void PlayerComponent::setSpeed(float speed)
    {
        _speed = speed;
    }

    void PlayerComponent::setColor(sf::Color color)
    {
        _shape.setFillColor(color);
    }

    sf::FloatRect PlayerComponent::getBounds() const
    {
        return _shape.getGlobalBounds();
    }
}
