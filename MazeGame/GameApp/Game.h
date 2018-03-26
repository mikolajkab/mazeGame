///
/// Klasa reprezentujaca gre
///
#pragma once

#include <SFML/Graphics.hpp>

#include "Window.h"

class CGame
{
public:
  CGame();            ///< konstruktor
  virtual ~CGame();   ///< destruktor
  void runMainLoop(); ///< funkcja sterujaca gra

private:
  CWindow mWindow;    ///< okno dialogowe w ktorym wyswietla sie gra
  sf::Clock mClock;   ///< zegar odmierza czas,z biblioteki SFML
  sf::Time time;      ///< reprezentuje czas, biblioteki SFML

  static const int mWindowHeight = 1024;  ///< wysokosc okna dialogowego
  static const int mWindowWidth = 1424;   ///< szerokosc okna dialogowego
};

