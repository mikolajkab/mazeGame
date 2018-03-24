#include "Step.h"

CStep::CStep(SPosition position, std::shared_ptr<CMazeMap> mazeMap)
  : mActualPosition(position)
  , mActualMazeMap(mazeMap)
{
}

CStep::~CStep()
{
}

void CStep::goNorth()
{
  mActualPosition.row -= 1;
  mLastStep.value = 0;
  mLastStep.fields.N = 1;
  UDirections direction{};
  direction.fields.S = 1;
  setFirstEntranceDirection(mActualPosition.row, mActualPosition.col, direction);
}

void CStep::goSouth()
{
  mActualPosition.row += 1;
  mLastStep.value = 0;
  mLastStep.fields.S = 1;
  UDirections direction{};
  direction.fields.N = 1;
  setFirstEntranceDirection(mActualPosition.row, mActualPosition.col, direction);
}

void CStep::goEast()
{
  mActualPosition.col += 1;
  mLastStep.value = 0;
  mLastStep.fields.E = 1;
  UDirections direction{};
  direction.fields.W = 1;
  setFirstEntranceDirection(mActualPosition.row, mActualPosition.col, direction);
}

void CStep::goWest()
{
  mActualPosition.col -= 1;
  mLastStep.value = 0;
  mLastStep.fields.W = 1;
  UDirections direction{};
  direction.fields.E = 1;
  setFirstEntranceDirection(mActualPosition.row, mActualPosition.col, direction);
}

void CStep::checkWalls()
{
  mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition
    = mActualMazeMap->getWallPosition(mActualPosition.row, mActualPosition.col);
}

void CStep::setVisited()
{
  mDetectedMazeMap[mActualPosition.row][mActualPosition.col].visited = true;
}

void CStep::setFirstEntranceDirection(int row, int col, UDirections direction)
{
  if (!mDetectedMazeMap[row][col].visited)
  {
    mDetectedMazeMap[row][col].firstEntranceDirection = direction;
  }
}

bool CStep::atGoal()
{
  if ((mActualPosition.col == mActualMazeMap->goalPosition.col) && (mActualPosition.row == mActualMazeMap->goalPosition.row))
  {
    return true;
  }
  return false;
}