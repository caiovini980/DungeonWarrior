#include "Collider.h"

#include "../../Core/GameObject.h"
#include "../Transform/Transform.h"

Collider::Collider()
    : m_Transform(std::make_shared<Transform>())
{
    
}

void Collider::Update()
{
    m_Transform->SetPosition(GetOwner()->GetTransform()->GetPosition());
}
