#pragma once
#include <memory>
#include <SDL_render.h>
#include <vector>
#include "../Components/Collision/BoxCollider.h"

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

    void RegisterCollider(Collider* collider);
    
    // Templates
    template<typename T>
    T& SpawnGameObject()
    {
        static_assert(std::is_base_of_v<GameObject, T>, "The class must be derived from GameObject");

        std::shared_ptr<T> newObject = std::make_shared<T>();
        m_GameObjects.push_back(std::static_pointer_cast<GameObject>(newObject));
        return *newObject.get();
    }

    // TODO create methods that handle each collision (box-box, box-sphere, etc.)

    bool CheckCollision(Collider* colliderA, Collider* colliderB);
    bool CheckCollision(BoxCollider* colliderA, BoxCollider* colliderB);
    
    
private:
    static EngineManager* m_Instance;
    
    std::vector<std::shared_ptr<GameObject>> m_GameObjects;

    // TODO Remove null colliders
    std::vector<Collider*> m_Colliders;

    SDL_Renderer* m_Renderer{};
};

