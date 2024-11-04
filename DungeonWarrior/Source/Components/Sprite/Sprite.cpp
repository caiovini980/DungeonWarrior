#include "Sprite.h"

#include <SDL_image.h>

#include <iostream>

Sprite::Sprite(SDL_Renderer& renderer)
    : renderer(&renderer)
{
    
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
    free(renderer);
}

void Sprite::SetTexture(const char* imagePath)
{
    SDL_Surface* tempSurface = IMG_Load(imagePath);
    texture = SDL_CreateTextureFromSurface(this->renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

SDL_Texture* Sprite::GetTexture() const
{
    return texture;
}

SDL_Renderer* Sprite::GetRenderer() const
{
    return renderer;
}
