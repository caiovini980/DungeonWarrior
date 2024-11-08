#include "GameObject.h"

#include <iostream>

#include "../Components/Component.h"
#include "../Components/Transform/Transform.h"

GameObject::GameObject()
    : m_Transform(std::make_unique<Transform>())
{
    std::cout << "Constructing game object\n";
}

void GameObject::Render()
{
}

void GameObject::UpdateComponents() const
{
    for (auto& element : m_Components)
    {
        element->Update();
    }
}

template <typename T>
T* GameObject::AddComponent()
{
    static_assert(std::is_base_of_v<Component, T>, "The class must be a Component to be added to a GameObject");

    std::shared_ptr<T> newComponent = std::make_shared<T>();
    static_cast<Component*>(newComponent.get())->Setup(this);
    m_Components.emplace_back(newComponent);
    
    return newComponent;
}
