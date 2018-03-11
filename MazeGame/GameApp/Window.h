#pragma once

#include <SFML/Graphics.hpp>

#include "Maze.h"
#include "Mouse.h"

class CWindow
{
public:
  CWindow(int length, int width, std::string name);
  ~CWindow();

  void pollEvents();
  bool isOpen() const;
  void display();
  void clear();
  void calculatePosition();

private:
  sf::RenderWindow mWindow;
  sf::Clock mClock;
  CMaze mMaze;
  CMouse mMouse;
};

