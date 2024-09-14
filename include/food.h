#ifndef FOOD_H
#define FOOD_H

#include "game_panel.h"
#include "linked_list.h"
#include "raylib.h"

typedef struct Food {
  int_vector pos;
} Food;

void DrawFood(Food * food,Texture2D texture) ;
int_vector positionGenerator();

#endif
