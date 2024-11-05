#include "Sprite.h"

#include <SDL_image.h>

#include <iostream>

Sprite::Sprite(SDL_Renderer& renderer)
    : m_Renderer(&renderer)
{
    
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(m_Texture);
    free(m_Renderer);
}

void Sprite::SetTexture(const char* imagePath)
{
    SDL_Surface* tempSurface = IMG_Load(imagePath);
    m_Texture = SDL_CreateTextureFromSurface(this->m_Renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

SDL_Texture* Sprite::GetTexture() const
{
    return m_Texture;
}

SDL_Renderer* Sprite::GetRenderer() const
{
    return m_Renderer;
}
