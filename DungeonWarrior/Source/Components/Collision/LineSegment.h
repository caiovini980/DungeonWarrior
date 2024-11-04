#pragma once

#include "../../Utils/Vector2.h"

class LineSegment
{
public:
    LineSegment(Vector2 start, Vector2 end);

    Vector2 PointOnSegment(float value) const;
    
private:
    Vector2 m_Start;
    Vector2 m_End;
};
