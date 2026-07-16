#include "MessageComponent.hpp"

namespace Factory::SFML
{
    MessageComponent::MessageComponent(const std::string& message, const sf::Font& font, sf::Vector2f position, unsigned int charSize, sf::Color color, bool active) : AComponent(position, active), _color(color)
    {
        _text.setFont(font);
        _text.setString(message);
        _text.setCharacterSize(charSize);
        _text.setFillColor(color);
        _text.setPosition(position);
    }

    void MessageComponent::update(float dt)
    {
        (void)dt;
    }

    void MessageComponent::render(sf::RenderWindow& window)
    {
        if (!_active) {
            return;
        }
        window.draw(_text);
    }

    void MessageComponent::setMessage(const std::string& message)
    {
        _text.setString(message);
    }

    std::string MessageComponent::getMessage() const
    {
        return _text.getString().toAnsiString();
    }

    void MessageComponent::setCharSize(unsigned int size)
    {
        _text.setCharacterSize(size);
    }

    void MessageComponent::setColor(sf::Color color)
    {
        _color = color;
        _text.setFillColor(color);
    }
}
