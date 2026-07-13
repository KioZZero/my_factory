#include "AComponent.hpp"

namespace Factory::SFML
{
    AComponent::AComponent(sf::Vector2f position, bool active) : _active(active), _position(position) {}

    bool AComponent::isActive() const
    {
        return _active;
    }

    void AComponent::setActive(bool active)
    {
        _active = active;
    }

    sf::Vector2f AComponent::getPosition() const
    {
        return _position;
    }

    void AComponent::setPosition(sf::Vector2f position)
    {
        _position = position;
    }

    float AComponent::getDeltaTime()
    {
        return _delta_time.restart().asSeconds();
    }
}
