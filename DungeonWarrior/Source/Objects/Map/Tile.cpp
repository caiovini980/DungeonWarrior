#include "Tile.h"

#include <iostream>

Tile::Tile(SDL_Renderer& renderer, const char* texturePath, std::string& tag)
{
    m_Transform = std::make_shared<Transform>();
    m_Sprite = std::make_shared<Sprite>(renderer);

    m_Sprite->SetTexture(texturePath);
    
    // TODO change the way we get this tag, maybe add it to some global file
    m_Collider = std::make_unique<BoxCollider>(*m_Transform, tag);
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

void Tile::Render() const
{
    if (m_Sprite->GetTexture() != nullptr && m_Sprite->GetRenderer() != nullptr)
    {
        SDL_RenderCopy(m_Sprite->GetRenderer(), m_Sprite->GetTexture(), nullptr, m_Transform->GetResultTransform());
    }
}

void Tile::Update()
{
}

void Tile::Destroy()
{
}

