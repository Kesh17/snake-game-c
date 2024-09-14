#ifndef COLLISION_H
#define COLLISION_H

#include "food.h"
#include "snake.h"
typedef struct Snake Snake;

bool checkWallCollison(Snake *snake);
bool CheckHeadCollision(Snake *snake);
bool collision(Snake *snake);
void foodCollsion(Snake *snake, Food *food, int *score);

#endif
