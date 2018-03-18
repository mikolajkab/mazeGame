#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Maze.h"
#include "Mouse.h"
#include "MazeMap.h"
#include "WallPosition.h"

using std::make_shared;
using std::make_unique;

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
  sf::RenderWindow mRenderWindow;
  std::shared_ptr<CMazeMap> mMazeMap;

  std::unique_ptr<CMaze> mMaze;
  std::unique_ptr<CMouse> mMouse;
};

