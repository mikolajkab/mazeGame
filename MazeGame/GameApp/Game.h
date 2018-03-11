#pragma once
#include <SFML/Graphics.hpp>

#include "Window.h"

class CGame
{
public:
  CGame();
  virtual ~CGame();
  void runMainLoop();


private:
  CWindow mWindow;
  sf::Clock mClock;
  sf::Time time;
};

