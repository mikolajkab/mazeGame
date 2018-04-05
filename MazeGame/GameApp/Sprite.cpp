#include "Sprite.h"

CSprite::CSprite(const std::string& fielName)
{
  mTexture.loadFromFile(fielName);
  mSprite.setTexture(mTexture);
}

CSprite::~CSprite()
{
}

void CSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &mTexture;
  target.draw(mSprite, states);
}