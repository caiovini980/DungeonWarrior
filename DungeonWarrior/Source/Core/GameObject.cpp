#include "GameObject.h"

#include <iostream>

#include "../Components/Component.h"
#include "../Components/Transform/Transform.h"

GameObject::GameObject()
    : m_Transform(std::make_unique<Transform>())
{
    // std::cout << "Constructing game object\n";
}

void GameObject::Render() const
{
    if (m_Components.empty()) return;
    
    for (auto& component : m_Components)
    {
        component->Render();
    }
}

void GameObject::UpdateComponents() const
{
    if (m_Components.empty()) return;
    
    for (auto& element : m_Components)
    {
        element->Update();
    }
}
