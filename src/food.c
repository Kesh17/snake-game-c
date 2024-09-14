#include "food.h"

int_vector positionGenerator() {
  int x = GetRandomValue(0, gamePanel.rows - 1);
  int y = GetRandomValue(0, gamePanel.cols - 1);

  return (int_vector){x, y};
}

void DrawFood(Food * food,Texture2D texture) {
  for (int i = 0; i < gamePanel.rows; i++) {
    for (int j = 0; j < gamePanel.cols; j++) {
      int x = food->pos.x * gamePanel.scale;
      int y = food->pos.y * gamePanel.scale;
      DrawTextureRec(
          texture,
          (Rectangle){
              .width = 40, .height = 40, .x = gamePanel.scale * 4, .y = 0},
          (Vector2){x, y}, WHITE);
    }
  }
}
