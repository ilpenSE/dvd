#include <stdio.h>
#include <raylib.h>

struct Box {
  Rectangle rect;
  Vector2 speed;
  Color color;
};

struct Ball {
  Vector2 center;
  Vector2 speed;
  float radius;
  Color color;
};

void DrawCoordinateSystem(float thickness, Color color, float swidth = GetScreenWidth(), float sheight = GetScreenHeight()) {
  Vector2 x_start = {0.0, sheight / 2};
  Vector2 x_end = {swidth, sheight / 2};
  Vector2 y_start = {swidth / 2, 0.0};
  Vector2 y_end = {swidth / 2, sheight};

  DrawLineEx(x_start, x_end, thickness, color);
  DrawLineEx(y_start, y_end, thickness, color);
}

void DvdExample(Box& box, double dt, int swidth = GetScreenWidth(), int sheight = GetScreenHeight()) {
  // Update rectangle
  box.rect.x += box.speed.x * dt;
  box.rect.y += box.speed.y * dt;

  // Calculate if x element out-of-bounds
  // If that, inverse x speed then clamp the position
  if (box.rect.x <= 0) {
    box.rect.x = 0;
    box.speed.x *= -1;
  } else if (box.rect.x + box.rect.width >= swidth) {
    box.rect.x = swidth - box.rect.width;
    box.speed.x *= -1;
  }

  // Calculate if y element out-of-bounds
  // If that, inverse y speed then clamp the position
  if (box.rect.y <= 0) {
    box.rect.y = 0;
    box.speed.y *= -1;
  } else if (box.rect.y + box.rect.height >= sheight) {
    box.rect.y = sheight - box.rect.height;
    box.speed.y *= -1;
  }

  DrawRectangleRec(box.rect, box.color);
}

void DvdExample(Ball& ball, double dt, int swidth = GetScreenWidth(), int sheight = GetScreenHeight()) {
  const float rad = ball.radius;

  // Update circle
  ball.center.x += ball.speed.x * dt;
  ball.center.y += ball.speed.y * dt;

  // Calculate if x element out-of-bounds
  // If that, inverse x speed then clamp the position
  if (ball.center.x - rad <= 0) {
    ball.center.x = rad;
    ball.speed.x *= -1;
  } else if (ball.center.x + rad >= swidth) {
    ball.center.x = swidth - rad;
    ball.speed.x *= -1;
  }

  // Calculate if y element out-of-bounds
  // If that, inverse y speed then clamp the position
  if (ball.center.y - rad <= 0) {
    ball.center.y = rad;
    ball.speed.y *= -1;
  } else if (ball.center.y + rad >= sheight) {
    ball.center.y = sheight - rad;
    ball.speed.y *= -1;
  }

  DrawCircleV(ball.center, ball.radius, ball.color);
}

int main(void) {
  InitWindow(800, 600, "DVDez nuttzz");
  SetTargetFPS(180);

  Box rectangle = {.rect={.x=100, .y=200, .width=200, .height=100}, .speed={300,300}, .color=RED};
  Box square = {.rect={.x=400, .y=400, .width=50, .height=50}, .speed={300, 300}, .color=BLUE};
  Ball circle = {.center={100, 100}, .speed={300, 300}, .radius=50.0f, .color=GREEN};

  while (!WindowShouldClose()) {
    double dt = GetFrameTime();

    BeginDrawing();
      ClearBackground(GetColor(0x181818FF));

      DvdExample(rectangle, dt);
      DvdExample(square, dt);
      DvdExample(circle, dt);

      #if 0
      DrawCoordinateSystem(5.0f, WHITE);
      #endif
    EndDrawing();
  }
  CloseWindow();
}
