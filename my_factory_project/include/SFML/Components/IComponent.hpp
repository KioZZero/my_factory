#ifndef ICOMPONENT_HPP
    #define ICOMPONENT_HPP

#include "Utils.hpp"

#include <SFML/Graphics.hpp>

namespace Factory::SFML
{
    class IComponent
    {
        public:
            virtual ~IComponent() = default;
            
            virtual void update(float dt) = 0;
            virtual void render(sf::RenderWindow& window) = 0;
            virtual bool isActive() const = 0;
            virtual void setActive(bool active) = 0;
    };
}

#endif // ICOMPONENT_HPP
