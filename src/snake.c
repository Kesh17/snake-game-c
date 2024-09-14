#include "snake.h"

const Color custom_green = {42, 194, 50, 255};

void drawSnake(Snake *snake, Texture2D texture,BODY_POSITION body_position) {
  if (snake->head == NULL)
    return;
  DrawTextureRec(
      texture,
      (Rectangle){.height = 40, .width = 40, .x = 40 * body_position, .y = 0},
      (Vector2){snake->head->pos.x * gamePanel.scale,
                snake->head->pos.y * gamePanel.scale},
      WHITE);
  Node *temp = snake->head->next;
  while (temp != NULL) {
    int x = temp->pos.x * gamePanel.scale;
    int y = temp->pos.y * gamePanel.scale;
    DrawRectangle(x, y, gamePanel.scale, gamePanel.scale, custom_green);

    temp = temp->next;
  }
}


int ChangeDirection(Snake *snake,BODY_POSITION *body_position,int *frames) {
  int keyPressed = GetKeyPressed();
  int speed = 60;
  float delta = GetFrameTime();
  switch (keyPressed) {
  case KEY_W:
    if (snake->velocity.y == 0) {
      snake->velocity = (Vector2){0, -speed * delta};
      *body_position = BODY_UP;
    }
    break;
  case KEY_S:
    if (snake->velocity.y == 0) {
      snake->velocity = (Vector2){0, speed * delta};
      *body_position = BODY_DOWN;
    }
    break;
  case KEY_A:
    if (snake->velocity.x == 0) {
      snake->velocity = (Vector2){-speed * delta, 0};
      *body_position = BODY_LEFT;
    }
    break;
  case KEY_D:
    if (snake->velocity.x == 0) {
      snake->velocity = (Vector2){speed * delta, 0};
      *body_position = BODY_RIGHT;
    }
    break;
  }
  if (*frames % 5 == 0) {

    if (snake->head == NULL)
      return 0;

    snake->head = insert_at_first(
        snake->head, (int_vector){snake->head->pos.x + (int)snake->velocity.x,
                                  snake->head->pos.y + (int)snake->velocity.y});

    snake->head = removeLastNode(snake->head);
    if (collision(snake)) {
      return -1;
    }
    return 0;
  }
  return 0;
}
