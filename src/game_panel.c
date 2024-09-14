#include "game_panel.h"

const GamePanel gamePanel = {.width = 800,
                             .height = 800,
                             .fps = 60,
                             .title = "Snake Game",
                             .scale = 40,
                             .cols = 800 / 40,
                             .rows = 800 / 40};

void DrawBoard(int *score) {
  for (int i = 0; i < gamePanel.rows; i++) {
    for (int j = 0; j < gamePanel.cols; j++) {
      int x = i * gamePanel.scale;
      int y = j * gamePanel.scale;
      DrawRectangle(x, y, gamePanel.scale - 1, gamePanel.scale - 1, WHITE);
      DrawText(TextFormat("SCORE %d", *score), 5, 5, 30, BLACK);
    }
  }
}
