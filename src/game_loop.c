#include "game_loop.h"

void intialize(Snake *snake,Food *food,int *score,int* frames,Image *img,Texture2D *texture,GameState *gameState,BODY_POSITION *body_position) {
  InitWindow(gamePanel.width, gamePanel.height, gamePanel.title);
  SetTargetFPS(gamePanel.fps);

  *gameState = GAME_PLAY;
  *body_position = BODY_UP;
  snake->head = NULL;
  snake->velocity = (Vector2){0,0};
  snake->head = create_node(
      (int_vector){.x = gamePanel.rows / 2, .y = gamePanel.cols / 2});
  food->pos = (int_vector){2,8};
  *score = 0;
  *frames = 0;

  *img = LoadImage("./resource/pic3.png");
  *texture = LoadTextureFromImage(*img);
}

void dintialize(Image *img,Snake *snake,Texture2D *texture) {
  UnloadImage(*img);
  removeAllNode(snake->head);
  UnloadTexture(*texture);
  CloseWindow();
}

void game_loop() {
    Snake snake;
    Food food;
    int score,frames;
    Image img;
    Texture2D texture;
    GameState gameState;
    BODY_POSITION body_position;

  intialize(&snake,&food,&score,&frames,&img,&texture,&gameState,&body_position);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    switch (gameState) {
    case GAME_PLAY: {
      frames++;
      DrawBoard(&score);
      DrawFood(&food, texture);
      drawSnake(&snake, texture, body_position);
      if (ChangeDirection(&snake, &body_position, &frames) == -1)
        gameState = GAME_OVER;
      foodCollsion(&snake, &food, &score);
    } break;

    case GAME_OVER: {
      DrawRectangle(0, 0, gamePanel.width, gamePanel.height, GREEN);
      DrawText("GAME OVER", 150, 290, 80, DARKGREEN);
      DrawText(TextFormat("SCORE: %d", score), 250, 400, 20, DARKGREEN);
      DrawText("PRESS ENTER TO RETRY", 250, 425, 20, DARKGREEN);
      if (IsKeyPressed(KEY_ENTER)) {
        snake.head = removeAllNode(snake.head);
        snake.head = create_node(
            (int_vector){.x = gamePanel.rows / 2, .y = gamePanel.cols / 2});
        snake.velocity = (Vector2){0, 0};
        score = 0;
        frames = 0;
        food.pos = (int_vector){2,8};
        body_position = BODY_UP;
        gameState = GAME_PLAY;
      }
    } break;
    }
    EndDrawing();
  }
  dintialize(&img,&snake,&texture);
}
