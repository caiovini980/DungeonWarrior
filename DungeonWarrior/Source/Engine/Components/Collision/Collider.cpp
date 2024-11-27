#include "Collider.h"

#include "Engine/EngineManager.h"
#include "Engine/GameObject.h"
#include "../Transform/Transform.h"

Collider::Collider(E_ColliderShape newShape)
    : m_Transform(std::make_shared<Transform>())
    , m_Shape(newShape)
    , m_CollisionMap{
        {CollisionTags::WALL, false},
        {CollisionTags::PLAYER, false},
        {CollisionTags::FLOOR, false}
    }
{
    
}

void Collider::SetCollisionMapValue(const CollisionTags tag, const bool canCollide)
{
    m_CollisionMap[tag] = canCollide;
}

bool Collider::GetCollisionMapValue(CollisionTags tag)
{
    return m_CollisionMap[tag];
}

void Collider::Update()
{
    // update position and scale
    m_Transform->SetPosition(GetOwner()->GetTransform()->GetPosition());
    m_Transform->SetScale(GetOwner()->GetTransform()->GetSize());
}
