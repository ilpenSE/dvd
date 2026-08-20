#pragma once
#include <format>
#include <raylib.h>

// Extra minor features for raylib in C++
// like operator overload for vectors and stuff

// Vector2 <-> scalar
Vector2 operator *(const Vector2& v, float scalar) {
  return Vector2{v.x * scalar, v.y * scalar};
}

void operator *=(Vector2& v, float scalar) {
  v.x *= scalar; v.y *= scalar;
}

Vector2 operator /(const Vector2& v, float scalar) {
  return Vector2{v.x / scalar, v.y / scalar};
}

void operator /=(Vector2& v, float scalar) {
  v.x /= scalar; v.y /= scalar;
}

// Vector2 <-> Vector2
void operator +=(Vector2& vec, const Vector2& other) {
  vec.x += other.x;
  vec.y += other.y;
}

Vector2 operator +(const Vector2& vec, const Vector2& other) {
  return Vector2{vec.x + other.x, vec.y + other.y};
}

void operator -=(Vector2& vec, const Vector2& other) {
  vec.x -= other.x;
  vec.y -= other.y;
}

Vector2 operator -(const Vector2& vec, const Vector2& other) {
  return Vector2{vec.x - other.x, vec.y - other.y};
}

void operator *=(Vector2& vec, const Vector2& other) {
  vec.x *= other.x;
  vec.y *= other.y;
}

Vector2 operator *(const Vector2& vec, const Vector2& other) {
  return Vector2{vec.x * other.x, vec.y * other.y};
}

void operator /=(Vector2& vec, const Vector2& other) {
  vec.x /= other.x;
  vec.y /= other.y;
}

Vector2 operator /(const Vector2& vec, const Vector2& other) {
  return Vector2{vec.x / other.x, vec.y / other.y};
}

// Rectangle <-> Vector2
void operator +=(Rectangle& rect, const Vector2& vec) {
  rect.x += vec.x;
  rect.y += vec.y;
}

Rectangle operator +(const Rectangle& rect, const Vector2& vec) {
  return Rectangle{
    .x = rect.x + vec.x,
    .y = rect.y + vec.y,
    .width = rect.width,
    .height = rect.height,
  };
}

void operator -=(Rectangle& rect, const Vector2& vec) {
  rect.x -= vec.x;
  rect.y -= vec.y;
}

Rectangle operator -(const Rectangle& rect, const Vector2& vec) {
  return Rectangle{
    .x = rect.x - vec.x,
    .y = rect.y - vec.y,
    .width = rect.width,
    .height = rect.height,
  };
}

void operator *=(Rectangle& rect, const Vector2& vec) {
  rect.x *= vec.x;
  rect.y *= vec.y;
}

Rectangle operator *(const Rectangle& rect, const Vector2& vec) {
  return Rectangle{
    .x = rect.x * vec.x,
    .y = rect.y * vec.y,
    .width = rect.width,
    .height = rect.height,
  };
}

void operator /=(Rectangle& rect, const Vector2& vec) {
  rect.x /= vec.x;
  rect.y /= vec.y;
}

Rectangle operator /(const Rectangle& rect, const Vector2& vec) {
  return Rectangle{
    .x = rect.x / vec.x,
    .y = rect.y / vec.y,
    .width = rect.width,
    .height = rect.height,
  };
}

// Formatter for Vector2
template <>
struct std::formatter<Vector2> : std::formatter<std::string> {
  auto format(const Vector2& vec, std::format_context& ctx) const {
    std::string result = "{";
    result += std::to_string(vec.x);
    result += ", ";
    result += std::to_string(vec.y);
    result += "}";
    return std::formatter<std::string>::format(result, ctx);
  }
};

// Formatter for Rectangle
template <>
struct std::formatter<Rectangle> : std::formatter<std::string> {
  auto format(const Rectangle& vec, std::format_context& ctx) const {
    std::string result = "{";
    result += std::to_string(vec.x);
    result += ", ";
    result += std::to_string(vec.y);
    result += ", ";
    result += std::to_string(vec.width);
    result += ", ";
    result += std::to_string(vec.height);
    result += "}";
    return std::formatter<std::string>::format(result, ctx);
  }
};
