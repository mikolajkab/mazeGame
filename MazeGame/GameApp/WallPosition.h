#pragma once
#include <cstdint>

using std::uint8_t;

union UDirections
{
  uint8_t value;
  struct SFields
  {
    uint8_t N	: 1;
    uint8_t S	: 1;
    uint8_t E	: 1;
    uint8_t W	: 1;
    uint8_t res : 4;
  } fields;
};

struct SPosition
{
  int row;
  int col;
};