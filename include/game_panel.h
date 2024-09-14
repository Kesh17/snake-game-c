#ifndef GAME_PANEL
#define GAME_PANEL

#include "raylib.h"

typedef struct GamePanel {
  int width;
  int height;
  int fps;
  const char *title;
  int scale;
  int cols;
  int rows;
} GamePanel;

typedef enum GameState{GAME_OVER,GAME_PLAY}GameState;

extern const GamePanel gamePanel;
void DrawBoard(int *score);
void initializer() ;

#endif
