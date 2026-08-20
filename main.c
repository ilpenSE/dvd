#include <stdio.h>
#include <raylib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct Box {
  Rectangle rect;
  Vector2 speed;
  Color color;
} Box;

typedef struct Ball {
  Vector2 center;
  Vector2 speed;
  float radius;
  Color color;
} Ball;

void draw_x_axis(float thickness) {
  Vector2 start = {0.0, HEIGHT / 2};
  Vector2 end = {WIDTH, HEIGHT / 2};
  DrawLineEx(start, end, thickness, BLUE);
}

void draw_y_axis(float thickness) {
  Vector2 start = {WIDTH / 2, 0.0};
  Vector2 end = {WIDTH / 2, HEIGHT};
  DrawLineEx(start, end, thickness, BLUE);
}

void dvd_rect_example(Box *box, double dt) {
  const int swidth = GetScreenWidth();
  const int sheight = GetScreenHeight();

  // Update rectangle
  box->rect.x += box->speed.x * dt;
  box->rect.y += box->speed.y * dt;

  // Calculate if x element out-of-bounds
  // If that, inverse x speed then clamp the position
  if (box->rect.x <= 0) {
    box->rect.x = 0;
    box->speed.x *= -1;
  } else if (box->rect.x + box->rect.width >= swidth) {
    box->rect.x = swidth - box->rect.width;
    box->speed.x *= -1;
  }

  // Calculate if y element out-of-bounds
  // If that, inverse y speed then clamp the position
  if (box->rect.y <= 0) {
    box->rect.y = 0;
    box->speed.y *= -1;
  } else if (box->rect.y + box->rect.height >= sheight) {
    box->rect.y = sheight - box->rect.height;
    box->speed.y *= -1;
  }

  DrawRectangleRec(box->rect, box->color);
}

void dvd_circle_example(Ball *ball, double dt) {
  const int swidth = GetScreenWidth();
  const int sheight = GetScreenHeight();
  const float rad = ball->radius;

  // Update circle
  ball->center.x += ball->speed.x * dt;
  ball->center.y += ball->speed.y * dt;

  // Calculate if x element out-of-bounds
  // If that, inverse x speed then clamp the position
  if (ball->center.x - rad <= 0) {
    ball->center.x = rad;
    ball->speed.x *= -1;
  } else if (ball->center.x + rad >= swidth) {
    ball->center.x = swidth - rad;
    ball->speed.x *= -1;
  }

  // Calculate if y element out-of-bounds
  // If that, inverse y speed then clamp the position
  if (ball->center.y - rad <= 0) {
    ball->center.y = rad;
    ball->speed.y *= -1;
  } else if (ball->center.y + rad >= sheight) {
    ball->center.y = sheight - rad;
    ball->speed.y *= -1;
  }

  DrawCircleV(ball->center, ball->radius, ball->color);
}

int main(void) {
  InitWindow(WIDTH, HEIGHT, "DVDez nuttzz");
  SetTargetFPS(180);

  Box rectangle = {.rect={.x=100, .y=200, .width=200, .height=100}, .speed={300,300}, .color=RED};
  Box square = {.rect={.x=400, .y=400, .width=50, .height=50}, .speed={300, 300}, .color=BLUE};
  Ball circle = {.center={100, 100}, .radius=50.0f, .speed={300, 300}, .color=GREEN};

  while (!WindowShouldClose()) {
    double dt = GetFrameTime();

    BeginDrawing();
      ClearBackground(GetColor(0x181818FF));

      dvd_rect_example(&rectangle, dt);
      dvd_rect_example(&square, dt);
      dvd_circle_example(&circle, dt);

      #if 0
      draw_x_axis(5.0f); draw_y_axis(5.0f);
      #endif
    EndDrawing();
  }
  CloseWindow();
}
