#pragma once
#include <memory>
#include <SDL_render.h>
#include <vector>
#include "Engine/Components/Collision/BoxCollider.h"

class BoxCollider;
class GameObject;
class Collider;

class EngineManager
{
public:
    EngineManager() = default;
    ~EngineManager() = default;

    EngineManager& operator=(const EngineManager&) = delete;
    
    static EngineManager& GetInstance();
    
    SDL_Renderer* GetRenderer() const { return m_Renderer; }
    void SetRenderer(SDL_Renderer* renderer) { m_Renderer = renderer; }
    
    void Update();
    void Render() const;
    void Destroy(GameObject* gameObject);

    void RegisterCollider(const std::weak_ptr<Collider>& collider);
    
    // Templates
    template<typename T>
    T& SpawnGameObject()
    {
        static_assert(std::is_base_of_v<GameObject, T>, "The class must be derived from GameObject");

        std::shared_ptr<T> newObject = std::make_shared<T>();
        m_GameObjects.push_back(std::static_pointer_cast<GameObject>(newObject));
        return *newObject.get();
    }

    SDL_bool CheckCollision(Collider* colliderA, Collider* colliderB, SDL_Rect* result);
    SDL_bool CheckCollision(BoxCollider* colliderA, BoxCollider* colliderB, SDL_Rect* result);
    
    
private:
    static std::shared_ptr<EngineManager> m_Instance;
    
    std::vector<std::shared_ptr<GameObject>> m_GameObjects;
    std::vector<std::weak_ptr<Collider>> m_Colliders;

    SDL_Renderer* m_Renderer{};
};

