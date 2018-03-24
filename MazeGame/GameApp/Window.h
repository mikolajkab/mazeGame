#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Maze.h"
#include "Mouse.h"
#include "MazeMap.h"
#include "Button.h"
#include "WallPosition.h"

using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::unique_ptr;

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
  shared_ptr<CMazeMap> mMazeMap;
  unique_ptr<CMaze> mMaze;

  std::vector<unique_ptr<CMouse>>  mMice;
  std::vector<unique_ptr<CButton>> mButtons;

  bool mRun;

  void handleButtons();
  void startStopReset();
  void addMouse();
  void switchMap();

  bool isCompMouseInPosition(int positionX, int positionY, int width, int height);

  static constexpr int sButPosX       = 1150;
  static constexpr int sButStartPosY  = 50;
  static constexpr int sButStopPosY   = 200;
  static constexpr int sButResetPosY  = 350;
  static constexpr int sButWFPosY     = 500;
  static constexpr int sButBFPosY     = 650;
  static constexpr int sButSwitchMapY = 800;
  static constexpr int sColorBlue     = 150;
  static constexpr int sButSideLen    = 150;
};

