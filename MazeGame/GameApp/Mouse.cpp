#include "Mouse.h"


CMouse::CMouse(const std::string& fielName, CMazeMap& mazeMap)
{

  //mActualMazeMap = mazeMap.map;

  if (!mTexture.loadFromFile(fielName))
  {
    // TODO: trigger excecption
  }

  mSprite.setTexture(mTexture);
  mSprite.setPosition(sf::Vector2f(7, 7 + 192));
  mSprite.setColor(sf::Color(155, 0, 128));

  mPosition.row = 0;
  mPosition.col = 0;

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
  mSprite.move(0, CTile::sHeight);
}

void CMouse::goSouth()
{
  mSprite.move(0, -CTile::sHeight);
}

void CMouse::goEast()
{
  mSprite.move(-CTile::sHeight, 0);
}

void CMouse::goWest()
{
  mSprite.move(CTile::sHeight, 0);
}

void CMouse::checkWall()
{

}