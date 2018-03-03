#pragma once

#include <SFML/Graphics.hpp>

#include "TileMap.h"


class CWindow
{
public:
  CWindow(int length, int width, std::string name);
  ~CWindow();

  void pollEvents();
  bool isOpen() const;
  void display();
  void clear();

private:
  sf::RenderWindow mWindow;
  sf::Clock mClock;
  CTileMap map;
};

