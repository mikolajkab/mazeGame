#pragma once
#include <memory>

#include "WallPosition.h"
#include "MazeMap.h"

class CStep
{
public:
  CStep(SPosition position, std::shared_ptr<CMazeMap> mazeMap);
  ~CStep();
  virtual SPosition go() = 0;

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

  STile mDetectedMazeMap[4][4];

  void goNorth();
  void goSouth();
  void goEast();
  void goWest();
  void checkWalls();
  void setVisited();
  void setFirstEntranceDirection(int row, int col, UDirections direction);
};

