#include "Button.h"

CButton::CButton(const std::string& fielName, int positionX, int positionY, int colorR, int colorG, int colorB)
{
  if (!mTexture.loadFromFile(fielName))
  {
    // TODO: trigger excecption
  }

  mSprite.setTexture(mTexture);
  mSprite.setColor(sf::Color(colorR, colorG, colorB));
  mSprite.setPosition(sf::Vector2f(positionX, positionY));
}

CButton::~CButton()
{
}

void CButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &mTexture;
  target.draw(mSprite, states);
}