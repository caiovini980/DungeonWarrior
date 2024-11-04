#include "Tile.h"

#include <iostream>

Tile::Tile(SDL_Renderer& renderer, const char* texturePath, std::string& tag)
{
    transform = std::make_shared<Transform>();
    sprite = std::make_shared<Sprite>(renderer);

    sprite->SetTexture(texturePath);
    
    // TODO change the way we get this tag, maybe add it to some global file
    collider = std::make_unique<BoxCollider>(*transform, tag);
}

void Tile::SetTilePosition(const Vector2& newPosition) const
{
    transform->SetPosition(
        newPosition.x * transform->GetSize().x,
        newPosition.y * transform->GetSize().y
        );
}

void Tile::SetTileSize(const Vector2& newSize) const
{
    transform->SetScale(newSize.x, newSize.y);
}

BoxCollider& Tile::GetCollider() const
{
    return *collider;
}

void Tile::Render() const
{
    if (sprite->GetTexture() != nullptr && sprite->GetRenderer() != nullptr)
    {
        SDL_RenderCopy(sprite->GetRenderer(), sprite->GetTexture(), nullptr, transform->GetResultTransform());
    }
}

void Tile::Update()
{
}

void Tile::Destroy()
{
}

