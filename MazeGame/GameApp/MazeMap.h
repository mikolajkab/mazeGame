///
/// Klasa reprezentujaca mape labiryntu
///

#pragma once

#include <array>

#include "Utilities.h"

class CMazeMap
{
public:
  CMazeMap(int mapNum);                           ///< konstruktor
  virtual ~CMazeMap();                            ///< destruktor

  size_t getWidth();                              ///< zwraca szerokosc labiryntu (w ilosci pol)
  size_t getHeight();                             ///< zwraca wysokosc labiryntu (w ilosci pol)
  UDirections getWallPosition(int row, int col);  ///< zwraca pozycje scian w kafelce
  void switchMap();                               ///< zmienia mape labiryntu

  static constexpr int sWidth = 16;               ///< szerokosc labiryntu (w ilosci pol)
  static constexpr int sHeight = 16;              ///< wysokoksc labiryntu (w ilosci pol)
  static constexpr SPosition goalPosition[]= { { 7,7 },{ 7,8 },{ 8,7 },{ 8,8 } }; ///< pozycjca celu w labiryncie

  std::array<std::array<UDirections, sHeight>, sWidth> map; ///< macierz opisujaca pozycje scian w labiryncie

private:
  int mMapNum;                                    ///< numer mapy
};

