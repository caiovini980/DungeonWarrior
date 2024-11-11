#include "Sprite.h"

#include <SDL_image.h>

#include <iostream>

#include "../../Core/GameManager.h"
#include "../Transform/Transform.h"
#include "../../Core/GameObject.h"

Sprite::Sprite()
{
    
}

void Sprite::SetTexture(const char* imagePath)
{
    SDL_Renderer* renderer = GameManager::GetInstance().GetRenderer();
    SDL_Surface* tempSurface = IMG_Load(imagePath);
    
    m_Texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

void Sprite::Update()
{
    
}

void Sprite::Render()
{
    SDL_RenderCopy(GameManager::GetInstance().GetRenderer(), GetTexture(), nullptr, GetOwner()->GetTransform()->GetResultTransform());
}

SDL_Texture* Sprite::GetTexture() const
{
    return m_Texture;
}
