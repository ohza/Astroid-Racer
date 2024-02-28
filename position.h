#pragma once

struct Position
{
  Position() = default;
  Position(int y, int x) : y(y), x(x) {}
  int y;
  int x;
};