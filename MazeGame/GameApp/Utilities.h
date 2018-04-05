///
/// plik definiujacy struktury pomocnicze
///
#pragma once

#include <cstdint>

/// unia przechowuje polozenie scian w kafelce
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

/// struktura przechowuje poolozenie kafelki
struct SPosition
{
  int row;
  int col;
};

/// enumeracja okresla rodzaj algorytmu oblicz
enum class EAlgorithm
{
  eWallFollower,
  eBruteForce,
};

/// szablon mnozenia
template<typename T> T multiply(T a, T b, T c = 1, T d = 1)
{
  return a*b*c*d;
}

/// szablon dodawania
template<typename T> T add(T a, T b = 0, T c = 0, T d = 0)
{
  return a + b + c;
}