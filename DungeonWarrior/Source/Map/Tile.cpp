﻿#include "Tile.h"
#include <iostream>

#include "../Components/Collision/BoxCollider.h"
#include "../Components/Transform/Transform.h"
#include "../Components/Sprite/Sprite.h"

void Tile::SetupTile(const char* texturePath, CollisionTypes collisionType)
{
    m_Sprite = &AddComponent<Sprite>();
    m_Sprite->SetTexture(texturePath);

    m_Collider = &AddComponent<BoxCollider>();
    m_Collider->SetupCollider(collisionType);
    m_Collider->SetCollisionMapValue(CollisionTypes::PLAYER, true);
}

void Tile::SetTilePosition(const Vector2& newPosition) const
{
    GetTransform()->SetPosition(
        newPosition.m_X * GetTransform()->GetSize().m_X,
        newPosition.m_Y * GetTransform()->GetSize().m_Y
        );
}

void Tile::SetTileSize(const Vector2& newSize) const
{
    GetTransform()->SetScale(newSize.m_X, newSize.m_Y);
}

BoxCollider& Tile::GetCollider() const
{
    return *m_Collider;
}

void Tile::Update()
{
}

