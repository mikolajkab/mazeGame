#include "Mouse.h"

const SPosition CMouse::goalPosition = { 3,3 };

CMouse::CMouse(const std::string& fielName, std::shared_ptr<CMazeMap> mazeMap, SPosition position)
  : mActualPosition(position)
  , mStep(std::make_unique<CWallFollower>(mActualPosition, mazeMap))
{
  if (!mTexture.loadFromFile(fielName))
  {
    // TODO: trigger excecption
  }

  mSprite.setTexture(mTexture);
  mSprite.setColor(sf::Color(155, 0, 128));
  mSprite.setOrigin(sf::Vector2f(-7, -7));
  setSpritePosition(0);
}

CMouse::~CMouse()
{
}

void CMouse::go()
{
  if(!atGoal())
  {
    mActualPosition = mStep->go();
    setSpritePosition(0);
  }
}

void CMouse::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &mTexture;
  target.draw(mSprite, states);
}

void CMouse::setSpritePosition(float angle)
{
  mSprite.setPosition(sf::Vector2f(mActualPosition.col*CTile::sWidth,
                                   mActualPosition.row*CTile::sHeight));
  mSprite.setRotation(angle);
}

bool CMouse::atGoal()
{
  if ((mActualPosition.col == goalPosition.col) && (mActualPosition.row == goalPosition.row))
  {
    //return true;
  }
  return false;
}