﻿#pragma once
#include <SDL_render.h>

class Sprite
{
public:
    Sprite(SDL_Renderer& renderer);
    ~Sprite();

    void SetTexture(const char* imagePath);
    
    SDL_Texture* GetTexture() const;
    SDL_Renderer* GetRenderer() const;

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};
