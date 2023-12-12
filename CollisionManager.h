//handles what happens when a snake encounters something
#pragma
#include "Snake.h"
#include "Food.h"

class CollisionManager{

public:
CollisionManager();
bool checkWallCollision(const Snake &snake) const;
bool checkSelfCollision(const Snake &snake ) const;
bool checkFoodCollision(const Snake &snake) const;

};