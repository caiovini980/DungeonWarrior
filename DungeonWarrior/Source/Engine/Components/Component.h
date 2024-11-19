#pragma once

class Component
{
friend class GameObject;
    
public:
    Component() = default;
    virtual ~Component() = default;

    virtual void Render(){}

    virtual void Update(){}
    
    GameObject* GetOwner() const { return m_Owner; }

protected:
    virtual void LateUpdate(){}
    
private:
    void Setup(GameObject* owner) { m_Owner = owner; }
    GameObject* m_Owner;
};
