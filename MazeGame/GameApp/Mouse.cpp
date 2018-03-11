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
  // apply the transform
  states.transform *= getTransform();

  // apply the tileset texture
  states.texture = &mTexture;

  // draw the vertex array
  target.draw(mSprite, states);
}

void CMouse::goNorth()
{
  mPosition.row -= 1;
  setSpritePosition();
}

void CMouse::goSouth()
{
  mPosition.row += 1;
  setSpritePosition();
}

void CMouse::goEast()
{
  mPosition.col -= 1;
  setSpritePosition();
}

void CMouse::goWest()
{
  mPosition.col += 1;
  setSpritePosition();
}

void CMouse::checkWalls()
{
  mDetectedMazeMap[mPosition.row][mPosition.col] = mActualMazeMap.getWallPosition(mPosition.row,mPosition.col);
}

void CMouse::setSpritePosition(void)
{
  mSprite.setPosition(sf::Vector2f(mPosition.row*CTile::sHeight, mPosition.col*CTile::sWidth));
}

void CMouse::move(void)
{
  checkWalls();
  if (mDetectedMazeMap[mPosition.row][mPosition.col].fields.N == 0)
  {
    goNorth();
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
    goWest();
  }
}