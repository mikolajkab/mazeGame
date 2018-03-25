#include "WallFollower.h"

CWallFollower::CWallFollower(SPosition position, std::shared_ptr<CMazeMap> mazeMap)
  :CStepper(position, mazeMap)
{
  mLastStep.fields.S = 1;
}

CWallFollower::~CWallFollower()
{
}

SPosition CWallFollower::go()
{
  setVisited();
  checkWalls();
  switch (mLastStep.value)
  {
  case 1:
    if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.E == 0)
    {
      goEast();
    }
    else if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.N == 0)
    {
      goNorth();
    }
    else if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.W == 0)
    {
      goWest();
    }
    else
    {
      goSouth();
    }
    break;
  case 2:
    if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.W == 0)
    {
      goWest();
    }
    else if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.S == 0)
    {
      goSouth();
    }
    else if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.E == 0)
    {
      goEast();
    }
    else
    {
      goNorth();
    }
    break;
  case 4:
    if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.S == 0)
    {
      goSouth();
    }
    else if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.E == 0)
    {
      goEast();
    }
    else if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.N == 0)
    {
      goNorth();
    }
    else
    {
      goWest();
    }
    break;
  case 8:
    if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.N == 0)
    {
      goNorth();
    }
    else if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.W == 0)
    {
      goWest();
    }
    else if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.S == 0)
    {
      goSouth();
    }
    else
    {
      goEast();
    }
    break;
  default:
    mLastStep.value = 2;
    break;
  }
  return mActualPosition;
}

bool CWallFollower::wasVisited()
{
  if (mDetectedMazeMap[mActualPosition.row][mActualPosition.col].visited == true)
  {
    return true;
  }
  return false;
}