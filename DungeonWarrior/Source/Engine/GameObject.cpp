#include "GameObject.h"

#include <iostream>

#include "Engine/Components/Component.h"
#include "Engine/Components/Transform/Transform.h"

GameObject::GameObject()
    : m_Transform(AddComponent<Transform>())
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

void GameObject::LateUpdateComponents()
{
    if (m_Components.empty()) return;

    for (auto& element : m_Components)
    {
        element->LateUpdate();
    }
}
