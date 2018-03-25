#include "Stepper.h"

CStepper::CStepper(SPosition position, std::shared_ptr<CMazeMap> mazeMap)
  : mActualPosition(position)
  , mActualMazeMap(mazeMap)
{
}

CStepper::~CStepper()
{
}

void CStepper::goNorth()
{
  mActualPosition.row -= 1;
  mLastStep.value = 0;
  mLastStep.fields.N = 1;
  UDirections direction{};
  direction.fields.S = 1;
  setFirstEntranceDirection(mActualPosition.row, mActualPosition.col, direction);
}

void CStepper::goSouth()
{
  mActualPosition.row += 1;
  mLastStep.value = 0;
  mLastStep.fields.S = 1;
  UDirections direction{};
  direction.fields.N = 1;
  setFirstEntranceDirection(mActualPosition.row, mActualPosition.col, direction);
}

void CStepper::goEast()
{
  mActualPosition.col += 1;
  mLastStep.value = 0;
  mLastStep.fields.E = 1;
  UDirections direction{};
  direction.fields.W = 1;
  setFirstEntranceDirection(mActualPosition.row, mActualPosition.col, direction);
}

void CStepper::goWest()
{
  mActualPosition.col -= 1;
  mLastStep.value = 0;
  mLastStep.fields.W = 1;
  UDirections direction{};
  direction.fields.E = 1;
  setFirstEntranceDirection(mActualPosition.row, mActualPosition.col, direction);
}

void CStepper::checkWalls()
{
  mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition
    = mActualMazeMap->getWallPosition(mActualPosition.row, mActualPosition.col);
}

void CStepper::setVisited()
{
  mDetectedMazeMap[mActualPosition.row][mActualPosition.col].visited = true;
}

void CStepper::setFirstEntranceDirection(int row, int col, UDirections direction)
{
  if (!mDetectedMazeMap[row][col].visited)
  {
    mDetectedMazeMap[row][col].firstEntranceDirection = direction;
  }
}

bool CStepper::atGoal()
{
  for (const auto& position : mActualMazeMap->goalPosition)
  {
    if ((mActualPosition.col == position.col) && (mActualPosition.row == position.row))
    {
      return true;
    }
  }
  return false;
}