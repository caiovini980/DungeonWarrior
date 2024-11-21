#include "Tile.h"
#include <iostream>

#include "Engine/Components/Collision/BoxCollider.h"
#include "Engine/Components/Transform/Transform.h"
#include "Engine/Components/Sprite/Sprite.h"

void Tile::SetupTile(const char* texturePath, CollisionTypes collisionType)
{
    m_Sprite = AddComponent<Sprite>();
    if (auto sprite = m_Sprite.lock())
    {
        sprite->SetTexture(texturePath);
    }
    
    m_Collider = AddComponent<BoxCollider>();
    if (auto collider = m_Collider.lock())
    {
        collider->SetupCollider(collisionType);
        collider->SetCollisionMapValue(CollisionTypes::PLAYER, true);
    }
}

void Tile::SetTilePosition(const Vector2& newPosition)
{
    GetTransform()->SetPosition(
        newPosition.m_X * GetTransform()->GetSize().m_X,
        newPosition.m_Y * GetTransform()->GetSize().m_Y
        );
}

void Tile::SetTileSize(const Vector2& newSize) 
{
    GetTransform()->SetScale(newSize.m_X, newSize.m_Y);
}

BoxCollider& Tile::GetCollider() const
{
    return *m_Collider.lock();
}

void Tile::Update()
{
}

