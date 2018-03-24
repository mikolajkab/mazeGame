#pragma once

#include <array>
#include <memory>

#include "WallPosition.h"
#include "MazeMap.h"

class CStep
{
public:
  CStep(SPosition position, std::shared_ptr<CMazeMap> mazeMap);
  ~CStep();
  virtual SPosition go() = 0;
  bool atGoal();

protected:
  SPosition mActualPosition;
  UDirections mLastStep;
  std::shared_ptr<CMazeMap> mActualMazeMap;

  struct STile
  {
    UDirections wallPosition;
    UDirections firstEntranceDirection;
    bool visited;
  };

  std::array<std::array<STile, CMazeMap::sWidth>, CMazeMap::sHeight> mDetectedMazeMap;

  void goNorth();
  void goSouth();
  void goEast();
  void goWest();
  void checkWalls();
  void setVisited();
  void setFirstEntranceDirection(int row, int col, UDirections direction);
};

