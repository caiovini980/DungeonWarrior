#pragma once

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void Render() = 0;
    virtual void Update() = 0;
    virtual void Destroy() = 0;
};
