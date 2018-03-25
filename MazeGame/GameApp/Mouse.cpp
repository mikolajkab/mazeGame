#include "Mouse.h"

CMouse::CMouse(const std::string& fielName, std::shared_ptr<CMazeMap> mazeMap, SPosition position, int algNum)
  : mActualPosition(position)
  , mStepper(nullptr)
{
  if (!mTexture.loadFromFile(fielName))
  {
    // TODO: trigger excecption
  }

  if (algNum == sAlgNumWallFollower)
  {
    mStepper = std::make_unique<CWallFollower>(mActualPosition, mazeMap);
  }
  else if (algNum == sAlgNumBruteForce)
  {
    mStepper = std::make_unique<CBruteForce>(mActualPosition, mazeMap);
  }

  mSprite.setTexture(mTexture);
  mSprite.setOrigin(sf::Vector2f(-7, -7));
  setSpritePosition(0);
}

CMouse::~CMouse()
{
}

void CMouse::go()
{
  if(!mStepper->atGoal())
  {
    mActualPosition = mStepper->go();
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