#include "Mouse.h"

const CMouse::SPosition CMouse::goalPosition = { 2,2 };


CMouse::CMouse(const std::string& fielName, CMazeMap& mazeMap)
  : mActualMazeMap(&mazeMap)
{
  if (!mTexture.loadFromFile(fielName))
  {
    // TODO: trigger excecption
  }

  mSprite.setTexture(mTexture);
  mSprite.setColor(sf::Color(155, 0, 128));
  mSprite.setOrigin(sf::Vector2f(-7, -7));
  mPosition.row = 0;
  mPosition.col = 0;
  setSpritePosition(0);
}

CMouse::~CMouse()
{
}

void CMouse::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &mTexture;
  target.draw(mSprite, states);
}

void CMouse::goNorth()
{
  mPosition.row -= 1;
  mLastStep.value = 0;
  mLastStep.fields.N = 1;
  UDirections direction{};
  direction.fields.S = 1;
  setFirstEntranceDirection(mPosition.row, mPosition.row, direction);
  setSpritePosition(0);
}

void CMouse::goSouth()
{
  mPosition.row += 1;
  mLastStep.value = 0;
  mLastStep.fields.S = 1;
  UDirections direction{};
  direction.fields.N = 1;
  setFirstEntranceDirection(mPosition.row, mPosition.row, direction);
  setSpritePosition(0);
}

void CMouse::goEast()
{
  mPosition.col += 1;
  mLastStep.value = 0;
  mLastStep.fields.E = 1;
  UDirections direction{};
  direction.fields.W = 1;
  setFirstEntranceDirection(mPosition.row, mPosition.row, direction);
  setSpritePosition(0);
}

void CMouse::goWest()
{
  mPosition.col -= 1;
  mLastStep.value = 0;
  mLastStep.fields.W = 1;
  UDirections direction{};
  direction.fields.E = 1;
  setFirstEntranceDirection(mPosition.row, mPosition.row, direction);
  setSpritePosition(0);
}

void CMouse::setFirstEntranceDirection(int row, int col, UDirections direction)
{
  if (!mDetectedMazeMap[row][col].visited)
  {
    mDetectedMazeMap[row][col].firstEntranceDirection = direction;
  }
}

void CMouse::checkWalls()
{
  mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition
    =
      mActualMazeMap->getWallPosition(mPosition.row, mPosition.col);
}

void CMouse::setSpritePosition(float angle)
{
  mSprite.setPosition(sf::Vector2f(mPosition.col*CTile::sWidth,
                                   mPosition.row*CTile::sHeight));
  mSprite.setRotation(angle);
}

void CMouse::goWallFollower(void)
{
  checkWalls();
  switch (mLastStep.value)
  {
  case 1:
    if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.E == 0)
    {
      goEast();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.N == 0)
    {
      goNorth();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.W == 0)
    {
      goWest();
    }
    else
    {
      goSouth();
    }
    break;
  case 2:
    if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.W == 0)
    {
      goWest();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.S == 0)
    {
      goSouth();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.E == 0)
    {
      goEast();
    }
    else
    {
      goNorth();
    }
    break;
  case 4:
    if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.S == 0)
    {
      goSouth();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.E == 0)
    {
      goEast();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.N == 0)
    {
      goNorth();
    }
    else
    {
      goWest();
    }
    break;
  case 8:
    if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.N == 0)
    {
      goNorth();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.W == 0)
    {
      goWest();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.S == 0)
    {
      goSouth();
    }
    else
    {
      goEast();
    }
    break;
  default:
    mLastStep.value = 1;
    break;
  }
}

void CMouse::setVisited()
{
  mDetectedMazeMap[mPosition.row][mPosition.col].visited = true;
}

void CMouse::goBruteForce()
{
  setVisited();
  if (checkGoal())
  {
    return;
  }
  checkWalls();
  UDirections possibleDirections = getPossibleDirections();
  UDirections direction = generateDirection(possibleDirections);

  goInDirection(direction);
}

bool CMouse::checkGoal()
{
  return false;
}

UDirections CMouse::getPossibleDirections()
{
  UDirections possibleDirections{};
  if ((mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.N == 0)
      && (!mDetectedMazeMap[mPosition.row - 1][mPosition.col].visited)
      && ((mPosition.row - 1) >= 0))
  {
    possibleDirections.fields.N = 1;
  }
  if ((mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.S == 0)
      && (!mDetectedMazeMap[mPosition.row + 1][mPosition.col].visited)
      && ((mPosition.row + 1) < mActualMazeMap->getWidth()))
  {
    possibleDirections.fields.S = 1;
  }
  if ((mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.E == 0)
      && (!mDetectedMazeMap[mPosition.row][mPosition.col + 1].visited)
      && ((mPosition.col + 1) < mActualMazeMap->getHeight()))
  {
    possibleDirections.fields.E = 1;
  }
  if ((mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition.fields.W == 0)
      && (!mDetectedMazeMap[mPosition.row][mPosition.col - 1].visited)
      && ((mPosition.col - 1) >= 0))
  {
    possibleDirections.fields.W = 1;
  }
  return possibleDirections;
}

UDirections CMouse::generateDirection(UDirections possibleDirections)
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
    return mDetectedMazeMap[mPosition.row][mPosition.col].firstEntranceDirection;
  }
  int randIndex = rand() % directions.size();
  return directions[randIndex];
}

void CMouse::goInDirection(UDirections direction)
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