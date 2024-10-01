#include "Tile.h"

#include <iostream>

Tile::Tile(SDL_Renderer& renderer, const char* texturePath)
{
    transform = std::make_shared<Transform>();
    sprite = std::make_shared<Sprite>(renderer);

    sprite->SetTexture(texturePath);
    std::cout << "Creating tile!\n";
}

Tile::~Tile()
{
}

void Tile::SetTilePosition(const Vector2& newPosition) const
{
    transform->SetPosition(
        newPosition.x * transform->GetScale().x,
        newPosition.y * transform->GetScale().y
        );
}

void Tile::SetTileSize(const Vector2& newSize) const
{
    transform->SetScale(newSize.x, newSize.y);
}

void Tile::Render()
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

