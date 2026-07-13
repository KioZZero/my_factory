#ifndef ACOMPONENT_HPP
    #define ACOMPONENT_HPP

#include "IComponent.hpp"

#include <SFML/Graphics.hpp>

namespace Factory::SFML
{
    class AComponent : public IComponent
    {
        protected:
            bool _active;
            sf::Vector2f _position;
            sf::Clock _delta_time;
            
        public:
            explicit AComponent(sf::Vector2f position = {0.f, 0.f}, bool active = true);
            ~AComponent() override = default;

            bool isActive() const override;
            void setActive(bool active) override;

            sf::Vector2f getPosition() const;
            void setPosition(sf::Vector2f position);

            float getDeltaTime();
    };
}

#endif // ACOMPONENT_HPP
