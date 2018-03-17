#include "Mouse.h"


CMouse::CMouse(const std::string& fielName, CMazeMap& mazeMap)
  : mActualMazeMap(mazeMap)
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
  setSpritePosition();
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
  setSpritePosition();
}

void CMouse::goSouth()
{
  mPosition.row += 1;
  mLastStep.value = 0;
  mLastStep.fields.S = 1;
  setSpritePosition();
}

void CMouse::goEast()
{
  mPosition.col += 1;
  mLastStep.value = 0;
  mLastStep.fields.E = 1;
  setSpritePosition();
}

void CMouse::goWest()
{
  mPosition.col -= 1;
  mLastStep.value = 0;
  mLastStep.fields.W = 1;
  setSpritePosition();
}

void CMouse::checkWalls()
{
  mDetectedMazeMap[mPosition.row][mPosition.col] = mActualMazeMap.getWallPosition(mPosition.row,mPosition.col);
}

void CMouse::setSpritePosition(void)
{
  mSprite.setPosition(sf::Vector2f(mPosition.col*CTile::sWidth, mPosition.row*CTile::sHeight));
}

void CMouse::move(void)
{
  checkWalls();
  switch (mLastStep.value)
  {
  case 1:
    if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.E == 0)
    {
      goEast();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.N == 0)
    {
      goNorth();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.W == 0)
    {
      goWest();
    }
    else
    {
      goSouth();
    }
    break;
  case 2:
    if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.W == 0)
    {
      goWest();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.S == 0)
    {
      goSouth();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.E == 0)
    {
      goEast();
    }
    else
    {
      goNorth();
    }
    break;
  case 4:
    if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.S == 0)
    {
      goSouth();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.E == 0)
    {
      goEast();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.N == 0)
    {
      goNorth();
    }
    else
    {
      goWest();
    }
    break;
  case 8:
    if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.N == 0)
    {
      goNorth();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.W == 0)
    {
      goWest();
    }
    else if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.S == 0)
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