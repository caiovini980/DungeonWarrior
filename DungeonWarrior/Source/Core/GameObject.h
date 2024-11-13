#pragma once
#include <memory>
#include <vector>

#include "../Components/Component.h"

class Transform;
class Component;

class GameObject
{
    friend class EngineManager;

public:
    GameObject();
    virtual ~GameObject() = default;
    
    Transform* GetTransform() const { return m_Transform.get(); }

protected:
    virtual void Update() = 0;
    
    template<typename T>
    T& AddComponent()
    {
        static_assert(std::is_base_of_v<Component, T>, "The class must be a Component to be added to a GameObject");

        std::shared_ptr<T> newComponent {std::make_shared<T>()};
        m_Components.push_back(std::static_pointer_cast<Component>(newComponent));
        m_Components.back().get()->Setup(this);

        return *newComponent.get();
    }

private:
    void Render() const;
    void UpdateComponents() const;

    std::vector<std::shared_ptr<Component>> m_Components;
    std::shared_ptr<Transform> m_Transform;
};