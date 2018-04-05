#include "Image.h"

CImage::CImage(const std::string& fielName)
{
  mTexture.loadFromFile(fielName);
  mSprite.setTexture(mTexture);
}


CImage::~CImage()
{
}

void CImage::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &mTexture;
  target.draw(mSprite, states);
}