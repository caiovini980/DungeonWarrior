#include "LineSegment.h"

LineSegment::LineSegment(Vector2 start, Vector2 end)
    : m_Start(start), m_End(end)
{}

Vector2 LineSegment::PointOnSegment(float value) const
{
    return m_Start + (m_End - m_Start) * value;
}
