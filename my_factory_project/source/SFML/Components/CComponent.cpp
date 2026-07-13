#include "CComponent.hpp"

namespace Factory::SFML
{
    CComponent::CComponent(sf::Vector2f position, bool active) : AComponent(position, active) {}

    void CComponent::update(float dt)
    {
        if (!_active) {
            return;
        }
        for (auto& child : _children)
        {
            if (child && child->isActive()) {
                child->update(dt);
            }
        }
    }

    void CComponent::render(sf::RenderWindow& window)
    {
        if (!_active) {
            return;
        }
        for (auto& child : _children)
        {
            if (child && child->isActive()) {
                child->render(window);
            }
        }
    }

    void CComponent::addComponent(std::unique_ptr<IComponent> component)
    {
        if (component) {
            _children.emplace_back(std::move(component));
        }
    }

    void CComponent::removeComponent(IComponent* component)
    {
        _children.erase(std::remove_if(_children.begin(), _children.end(), [component](const std::unique_ptr<IComponent>& child) { 
            return child.get() == component; 
        }), _children.end());
    }

    void CComponent::clearComponents()
    {
        _children.clear();
    }

    bool CComponent::hasChildren() const
    {
        return !_children.empty();
    }
}
