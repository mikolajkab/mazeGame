///
/// Klasa reprezentujaca kafelke w labiryncie
///

#pragma once

#include "Utilities.h"

class CTile
{
public:
  CTile();                            ///< konstruktor
  ~CTile();                           ///< destruktor
  UDirections getWall(void);          ///< zrwaca polezenie scian w kafelce
  void setWall(UDirections);          ///< ustawia polozenie scian w kafelce

  static constexpr int sWidth = 64;   ///< szerokosc kafelki w pixelach
  static constexpr int sHeight = 64;  ///< wysokosc kafelki w pixelach

private:
  UDirections mWall;                  ///< okresla polozenie scian w kafelce
};

