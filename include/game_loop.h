#ifndef GAME_LOOP
#define GAME_LOOP

#include "food.h"
#include "game_panel.h"
#include "raylib.h"
#include "snake.h"
#include "collision.h"

void game_loop() ;
void dintialize(Image *img, Snake *snake, Texture2D *texture);
void intialize(Snake *snake, Food *food, int *score, int *frames, Image *img,
               Texture2D *texture, GameState *gameState,
               BODY_POSITION *body_position);

#endif
