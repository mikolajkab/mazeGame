#include "BruteForce.h"
#include <vector>

CBruteForce::CBruteForce(SPosition position, std::shared_ptr<CMazeMap> mazeMap)
  :CStepper(position, mazeMap)
{
}

CBruteForce::~CBruteForce()
{
}

SPosition CBruteForce::go()
{
  setVisited();
  checkWalls();
  UDirections possibleDirections = getPossibleDirections();
  UDirections direction = generateDirection(possibleDirections);

  goInDirection(direction);
  return mActualPosition;
}

UDirections CBruteForce::getPossibleDirections()
{
  UDirections possibleDirections{};
  if ((mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.N == 0)
      && (!mDetectedMazeMap[mActualPosition.row - 1][mActualPosition.col].visited)
      && ((mActualPosition.row - 1) >= 0))
  {
    possibleDirections.fields.N = 1;
  }
  if ((mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.S == 0)
      && (!mDetectedMazeMap[mActualPosition.row + 1][mActualPosition.col].visited)
      && ((mActualPosition.row + 1) < mActualMazeMap->getWidth()))
  {
    possibleDirections.fields.S = 1;
  }
  if ((mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.E == 0)
      && (!mDetectedMazeMap[mActualPosition.row][mActualPosition.col + 1].visited)
      && ((mActualPosition.col + 1) < mActualMazeMap->getHeight()))
  {
    possibleDirections.fields.E = 1;
  }
  if ((mDetectedMazeMap[mActualPosition.row][mActualPosition.col].wallPosition.fields.W == 0)
      && (!mDetectedMazeMap[mActualPosition.row][mActualPosition.col - 1].visited)
      && ((mActualPosition.col - 1) >= 0))
  {
    possibleDirections.fields.W = 1;
  }
  return possibleDirections;
}

UDirections CBruteForce::generateDirection(UDirections possibleDirections)
{
  std::vector<UDirections> directions;
  if (possibleDirections.fields.N == 1)
  {
    UDirections north{};
    north.fields.N = 1;
    directions.push_back(north);
  }
  if (possibleDirections.fields.S == 1)
  {
    UDirections south{};
    south.fields.S = 1;
    directions.push_back(south);
  }
  if (possibleDirections.fields.E == 1)
  {
    UDirections east{};
    east.fields.E = 1;
    directions.push_back(east);
  }
  if (possibleDirections.fields.W == 1)
  {
    UDirections west{};
    west.fields.W = 1;
    directions.push_back(west);
  }
  if (directions.size() == 0)
  {
    return mDetectedMazeMap[mActualPosition.row][mActualPosition.col].firstEntranceDirection;
  }
  int randIndex = rand() % directions.size();
  return directions[randIndex];
}

void CBruteForce::goInDirection(UDirections direction)
{
  if (direction.fields.N)
  {
    goNorth();
  }
  else if (direction.fields.S)
  {
    goSouth();
  }
  else if (direction.fields.E)
  {
    goEast();
  }
  else if (direction.fields.W)
  {
    goWest();
  }
}