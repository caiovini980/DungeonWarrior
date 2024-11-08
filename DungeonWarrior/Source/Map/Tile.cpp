#include "Tile.h"
#include <iostream>

#include "../Components/Transform/Transform.h"
#include "../Components/Sprite/Sprite.h"
#include "../Core/GameManager.h"

Tile::Tile(SDL_Renderer& renderer, const char* texturePath, CollisionManager& collisionManager, CollisionTypes collisionType)
{
    m_Transform = std::make_shared<Transform>();
    m_Sprite = std::make_shared<Sprite>();

    m_Sprite->SetTexture(texturePath);
    
    // m_Collider = collisionManager.CreateCollider<BoxCollider>(*m_Transform, collisionType);
}

void Tile::SetTilePosition(const Vector2& newPosition) const
{
    m_Transform->SetPosition(
        newPosition.m_X * m_Transform->GetSize().m_X,
        newPosition.m_Y * m_Transform->GetSize().m_Y
        );
}

void Tile::SetTileSize(const Vector2& newSize) const
{
    m_Transform->SetScale(newSize.m_X, newSize.m_Y);
}

BoxCollider& Tile::GetCollider() const
{
    return *m_Collider;
}

void Tile::Render()
{
    if (m_Sprite->GetTexture() != nullptr && GameManager::GetInstance().GetRenderer() != nullptr)
    {
        SDL_RenderCopy(GameManager::GetInstance().GetRenderer(), m_Sprite->GetTexture(), nullptr, m_Transform->GetResultTransform());
    }
}

