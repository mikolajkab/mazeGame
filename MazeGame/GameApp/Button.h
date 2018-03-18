#pragma once
#include <SFML/Graphics.hpp>
#include "WallPosition.h"



class CButton : public sf::Drawable, public sf::Transformable
{
public:
  CButton(const std::string& fielName, int positionX, int positionY, int colorR = 255, int colorG = 255, int colorB = 255);
  ~CButton();

private:
  sf::Texture mTexture;
  sf::Sprite mSprite;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

