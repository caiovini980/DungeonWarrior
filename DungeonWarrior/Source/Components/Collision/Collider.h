#pragma once
#include <memory>
#include <string>

#include "../Transform/Transform.h"

class Collider
{
    virtual const std::string& GetTag() const = 0;
    
public:
    Collider(const std::shared_ptr<Transform>& transform, const std::shared_ptr<std::string>& tag) : m_Transform(transform), m_Tag(tag){}
    
    std::shared_ptr<Transform> m_Transform;
    std::shared_ptr<std::string> m_Tag;
};
