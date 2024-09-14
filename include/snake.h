#ifndef SNAKE_H
#define SNAKE_H

#include "food.h"
#include "game_panel.h"
#include "collision.h"
#include "linked_list.h"
#include "raylib.h"

typedef struct Snake Snake;
struct Snake {
  Node *head;
  Vector2 velocity;
};

typedef enum { BODY_LEFT, BODY_UP, BODY_RIGHT, BODY_DOWN } BODY_POSITION;

int ChangeDirection(Snake *snake, BODY_POSITION *body_position, int *frames);
void drawSnake(Snake *snake, Texture2D texture, BODY_POSITION body_position);

#endif
