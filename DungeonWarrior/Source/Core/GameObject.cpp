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
    for (auto& component : m_Components)
    {
        component->Render();
    }
}

void GameObject::UpdateComponents() const
{
    for (auto& element : m_Components)
    {
        element->Update();
    }
}
