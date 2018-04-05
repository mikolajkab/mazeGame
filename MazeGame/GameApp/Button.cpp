#include "Button.h"

CButton::CButton(const std::string& fielName, int positionX, int positionY, int colorR, int colorG, int colorB)
  :CImage(fielName)
{
  mSprite.setColor(sf::Color(colorR, colorG, colorB));
  mSprite.setPosition(sf::Vector2f(positionX, positionY));
}

CButton::~CButton()
{
}