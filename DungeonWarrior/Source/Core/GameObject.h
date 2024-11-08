#pragma once
#include <memory>
#include <vector>

class Transform;
class Component;

class GameObject
{
    friend class GameManager;

public:
    GameObject();
    virtual ~GameObject() = default;
    
    Transform* GetTransform() const { return m_Transform.get(); }

protected:
    virtual void Update() = 0;
    
    template<typename T>
    T* AddComponent();
    
private:
    
    void Render();
    void UpdateComponents() const;

    std::vector<std::shared_ptr<Component>> m_Components;
    std::unique_ptr<Transform> m_Transform;
};
