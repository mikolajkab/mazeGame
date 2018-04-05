///
/// funkcja reprezentuje przycisk
/// dziedziczy Drawable i Transformable z biblioteki SFML
///

#pragma once

#include <SFML/Graphics.hpp>

#include "Utilities.h"

class CButton : public sf::Drawable, public sf::Transformable
{
public:
  CButton(const std::string& fielName, int positionX, int positionY, int colorR = 255, int colorG = 255, int colorB = 255); ///< konstruktor
  ~CButton();                                                                                                               ///< destruktor

private:
  sf::Texture mTexture;     ///< obraz (tekstura) przycisku
  sf::Sprite mSprite;       ///< obiekt graficzny przycisku

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // funkcja rysuje przycisk
};

