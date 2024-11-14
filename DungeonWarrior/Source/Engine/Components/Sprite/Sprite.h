#pragma once
#include <SDL_render.h>

#include "../Component.h"

class Sprite : public Component
{
public:
    Sprite();
    ~Sprite() override = default;

    void SetTexture(const char* imagePath);

    void Update() override;
    
    SDL_Texture* GetTexture() const;

private:
    SDL_Texture* m_Texture;

    void Render() override;
};
