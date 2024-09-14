#include "collision.h"

bool checkWallCollison(Snake *snake) {
  if (snake->head == NULL) {
    return false;
  }
  if (snake->head->pos.x < 0 || snake->head->pos.x >= gamePanel.rows || snake->head->pos.y >= gamePanel.cols || snake->head->pos.y < 0) {
    return true;
  }
  return false;
}

bool CheckHeadCollision(Snake *snake) {
  if (snake->head == NULL || snake->head->next == NULL) {
    return false;
  }

  Node *current = snake->head->next;
  while (current != NULL) {
    if (snake->head->pos.x == current->pos.x &&
        snake->head->pos.y == current->pos.y) {
      return true;
    }
    current = current->next;
  }
  return false;
}

bool collision(Snake *snake) {
  if (checkWallCollison(snake) || CheckHeadCollision(snake)) {
    return true;
  }
  return false;
}

void foodCollsion(Snake *snake, Food *food, int *score) {
  if (snake->head->pos.x == food->pos.x && snake->head->pos.y == food->pos.y) {
    *score += 1;
    snake->head = insert_at_first(snake->head,
                                  (int_vector){food->pos.x++, food->pos.y++});
    food->pos = positionGenerator();
    return;
  }
}
