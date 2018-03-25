#pragma once

#include <cstdint>

union UDirections
{
  std::uint8_t value;
  struct SFields
  {
    std::uint8_t N	: 1;
    std::uint8_t S	: 1;
    std::uint8_t E	: 1;
    std::uint8_t W	: 1;
    std::uint8_t res : 4;
  } fields;
};

struct SPosition
{
  int row;
  int col;
};