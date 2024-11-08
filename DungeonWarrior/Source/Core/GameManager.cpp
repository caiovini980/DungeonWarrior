#include "GameManager.h"
#include <iostream>

#include "../Core/GameObject.h"

GameManager& GameManager::GetInstance()
{
    static GameManager instance;
        
    return instance;
}

void GameManager::Update() const
{
    for (auto& element : m_GameObjects)
    {
        element->UpdateComponents();
        element->Update();
    }
}

void GameManager::Render() const
{
    for (auto& element : m_GameObjects)
    {
        element->Render();
    }
}

void GameManager::Destroy(GameObject* gameObject)
{
    auto it = std::find_if(
        m_GameObjects.begin(), m_GameObjects.end(),
            [gameObject](const std::shared_ptr<GameObject>& item)
            {
                return item.get() == gameObject;
            });

    if (it != m_GameObjects.end())
    {
        m_GameObjects.erase(it);
    }
}