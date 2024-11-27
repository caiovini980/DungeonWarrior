#include "Obstacle.h"
#include <thread>

#include "Engine/Components/Transform/Transform.h"
#include "Engine/Components/Sprite/Sprite.h"
#include "Engine/Components/Collision/BoxCollider.h"

Obstacle::Obstacle()
{
    GetTransform()->SetPosition(300, 300);
    m_Sprite = AddComponent<Sprite>();
    m_Collider = AddComponent<BoxCollider>();
}

void Obstacle::SetupObstacle(const ObstacleConfig& config)
{
    m_Config = config;
    if (auto sprite = m_Sprite.lock())
    {
        sprite->SetTexture(m_TexturesPaths[m_Config.textureIndex].c_str());
    }

    if (auto collider = m_Collider.lock())
    {
        collider->SetupCollider(CollisionTags::OBSTACLE);
        collider->SetCollisionMapValue(CollisionTags::PLAYER, true);
    }

    // set possible positions for the obstacle to move towards
    m_MovePositions[0] = Vector2(500, 500);
    m_MovePositions[1] = Vector2(300, 300);
    m_MovePositions[2] = Vector2(120, 300);
    m_MovePositions[3] = Vector2(120, 200);
    m_MovePositions[4] = Vector2(120, 500);
    
    m_NextDestinationIndex = 0;
}

void Obstacle::Update()
{
    GetTransform()->SetScale(m_Config.sizeX, m_Config.sizeY);
    MoveTo(m_MovePositions[m_NextDestinationIndex]);
}

void Obstacle::LateUpdate()
{
    
}

void Obstacle::MoveTo(Vector2 newPosition)
{
    m_HaveReachedDestination = false;
    Vector2 nextPosition = m_MovePositions[m_NextDestinationIndex];
    Vector2 currentPosition = GetTransform()->GetPosition();
    GetTransform()->SetPosition(Lerp(currentPosition, nextPosition, m_Speed));
    
    if (
        (toupper(currentPosition.m_X) == toupper(nextPosition.m_X - 1) &&
        toupper(currentPosition.m_Y) == toupper(nextPosition.m_Y - 1)) ||
        (toupper(currentPosition.m_X) == toupper(nextPosition.m_X) &&
        toupper(currentPosition.m_Y) == toupper(nextPosition.m_Y)))
    {
        m_HaveReachedDestination = true;
        std::cout << "Obstacle reached it's destination\n";
        // get the next available destination to go, if it's the last one,
        // return to the first and restart the routine
        
        if (m_NextDestinationIndex + 1 >= m_MovePositions.size())
        {
            m_NextDestinationIndex = 0;
        }
        else
        {
            m_NextDestinationIndex += 1;
        }
    }

    // std::cout << "Current position: " << toupper(GetTransform()->GetPosition().m_X) << ", "
    // << toupper(GetTransform()->GetPosition().m_Y) << "\n" << "Destination: " << toupper(nextPosition.m_X) << ", " << toupper(nextPosition.m_Y) << "\n\n";
}

Vector2 Obstacle::Lerp(const Vector2 origin, const Vector2 destination, const float speed)
{
    return origin + (destination - origin) * speed;
}

BoxCollider& Obstacle::GetCollider() const
{
    return *m_Collider.lock();
}

