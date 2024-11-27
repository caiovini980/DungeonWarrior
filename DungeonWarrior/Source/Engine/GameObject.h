#pragma once
#include <memory>
#include <vector>

#include "Engine/Components/Component.h"

class Transform;
class Component;

class GameObject
{
    friend class EngineManager;

public:
    GameObject();
    virtual ~GameObject() = default;
    
    std::shared_ptr<Transform> GetTransform()
    {
        return m_Transform.lock();
    }

protected:
    virtual void Update() = 0;
    virtual void LateUpdate();
    
    template<typename T>
    std::shared_ptr<T>& AddComponent()
    {
        static_assert(std::is_base_of_v<Component, T>, "The class must be a Component to be added to a GameObject");

        std::shared_ptr<T> newComponent {std::make_shared<T>()};
        m_Components.push_back(std::static_pointer_cast<Component>(newComponent));
        m_Components.back()->Setup(this);

        return newComponent;
    }

private:
    void Render() const;
    void UpdateComponents() const;
    void LateUpdateComponents();

    std::vector<std::shared_ptr<Component>> m_Components;
    std::weak_ptr<Transform> m_Transform;
};