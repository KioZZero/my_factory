#ifndef CCOMPONENT_HPP
    #define CCOMPONENT_HPP

#include "AComponent.hpp"

#include <vector>
#include <memory>
#include <algorithm>

namespace Factory::SFML
{
    class CComponent : public AComponent
    {
        protected:
            std::vector<std::unique_ptr<IComponent>> _children;

        public:
            explicit CComponent(sf::Vector2f position = {0.f, 0.f}, bool active = true);
            ~CComponent() override = default;

            void update(float dt) override;
            void render(sf::RenderWindow& window) override;
            void addComponent(std::unique_ptr<IComponent> component);
            void removeComponent(IComponent* component);
            void clearComponents();
            bool hasChildren() const;
    };
}

#endif // CCOMPONENT_HPP
