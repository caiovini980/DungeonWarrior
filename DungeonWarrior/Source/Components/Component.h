#pragma once

class Component
{
friend class GameObject;
    
public:
    Component() = default;
    virtual void Update() = 0;
    virtual ~Component() = default;

    virtual void Render(){}
    
protected:
    GameObject* GetOwner() const { return m_Owner; }

private:
    void Setup(GameObject* owner) { m_Owner = owner; }
    GameObject* m_Owner;
};
