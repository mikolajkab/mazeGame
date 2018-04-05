#include "Mouse.h"

CMouse::CMouse(const std::string& fielName, std::shared_ptr<CMazeMap> mazeMap, SPosition position, EAlgorithm algNum)
  : CImage(fielName)
  , mActualPosition(position)
  , mStepper(nullptr)
{

  if (algNum == EAlgorithm::eWallFollower)
  {
    mStepper = std::make_unique<CWallFollower>(mActualPosition, mazeMap);
  }
  else if (algNum == EAlgorithm::eBruteForce)
  {
    mStepper = std::make_unique<CBruteForce>(mActualPosition, mazeMap);
  }

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

void CMouse::setSpritePosition(float angle)
{
  mSprite.setPosition(sf::Vector2f(mActualPosition.col*CTile::sWidth,
                                   mActualPosition.row*CTile::sHeight));
  mSprite.setRotation(angle);
}