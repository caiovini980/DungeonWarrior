#include "Collider.h"

#include "Engine/EngineManager.h"
#include "Engine/GameObject.h"
#include "../Transform/Transform.h"

Collider::Collider(E_ColliderShape newShape)
    : m_Transform(std::make_shared<Transform>())
    , m_Shape(newShape)
    , m_CollisionMap{
        {CollisionTypes::WALL, false},
        {CollisionTypes::PLAYER, false},
        {CollisionTypes::FLOOR, false}
    }
{
    
}

void Collider::SetCollisionMapValue(const CollisionTypes type, const bool canCollide)
{
    m_CollisionMap[type] = canCollide;
}

bool Collider::GetCollisionMapValue(CollisionTypes type)
{
    return m_CollisionMap[type];
}

void Collider::Update()
{
    // update position and scale
    m_Transform->SetPosition(GetOwner()->GetTransform()->GetPosition());
    m_Transform->SetScale(GetOwner()->GetTransform()->GetSize());
}
