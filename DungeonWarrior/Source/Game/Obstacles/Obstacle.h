#pragma once
#include <array>
#include <string>
#include <future>

#include "Engine/GameObject.h"
#include "Utils/ConfigHandler.h"
#include "Utils/Vector2.h"


class BoxCollider;
class Sprite;

class Obstacle : public GameObject
{
public:
    Obstacle();
    ~Obstacle() override = default;
    
    virtual void SetupObstacle(const ObstacleConfig& config);
    
    void Update() override;
    void LateUpdate() override;

    void MoveTo(Vector2 newPosition);
    
    BoxCollider& GetCollider() const;
    
private:
    bool ComputeMovement();
    int m_NextDestinationIndex;

    
    Vector2 Lerp(Vector2 origin, Vector2 destination, float speed);
    
    ObstacleConfig m_Config;
    
    std::weak_ptr<Sprite> m_Sprite;
    std::weak_ptr<BoxCollider> m_Collider;

    std::array<std::string, 1> m_TexturesPaths {
        "Assets/Sprites/obstacle_default.png"
    };
    
    std::array<Vector2, 5> m_MovePositions;
    
    float m_Speed{0.03f};
    bool m_HaveReachedDestination{false};
    bool m_CanCreateAnotherThread{true};
};
