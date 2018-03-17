#include "Mouse.h"

const CMouse::SPosition CMouse::stopPosition = { 2,2 };

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
  setSpritePosition(0);
}

void CMouse::goSouth()
{
  mPosition.row += 1;
  mLastStep.value = 0;
  mLastStep.fields.S = 1;
  setSpritePosition(0);
}

void CMouse::goEast()
{
  mPosition.col += 1;
  mLastStep.value = 0;
  mLastStep.fields.E = 1;
  setSpritePosition(0);
}

void CMouse::goWest()
{
  mPosition.col -= 1;
  mLastStep.value = 0;
  mLastStep.fields.W = 1;
  setSpritePosition(0);
}

void CMouse::checkWalls()
{
  mDetectedMazeMap[mPosition.row][mPosition.col].wallPosition = mActualMazeMap->getWallPosition(mPosition.row,mPosition.col);
}

void CMouse::setSpritePosition(float angle)
{
  mSprite.setPosition(sf::Vector2f(mPosition.col*CTile::sWidth, mPosition.row*CTile::sHeight));
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

void CMouse::goBruteForce()
{




}