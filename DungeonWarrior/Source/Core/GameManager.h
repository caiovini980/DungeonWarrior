#pragma once
#include <memory>
#include <SDL_render.h>
#include <vector>

class GameObject;

class GameManager
{
public:
    GameManager() = default;
    ~GameManager() = default;

    GameManager& operator=(const GameManager&) = delete;
    
    static GameManager& GetInstance();
    
    SDL_Renderer* GetRenderer() const { return m_Renderer; }
    void SetRenderer(SDL_Renderer* renderer) { m_Renderer = renderer; }
    
    void Update() const;
    void Render() const;
    void Destroy(GameObject* gameObject);

    // Templates
    template<typename T>
    T& SpawnGameObject()
    {
        static_assert(std::is_base_of_v<GameObject, T>, "The class must be derived from GameObject");

        std::shared_ptr<T> newObject = std::make_shared<T>();
        m_GameObjects.push_back(std::static_pointer_cast<GameObject>(newObject));
        return *newObject.get();
    }
    
private:
    static GameManager* m_Instance;
    
    std::vector<std::shared_ptr<GameObject>> m_GameObjects;

    SDL_Renderer* m_Renderer{};
};

