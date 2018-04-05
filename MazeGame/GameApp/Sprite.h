///
/// funkcja reprezentuje przycisk
/// dziedziczy Drawable i Transformable z biblioteki SFML
///

#pragma once

#include <SFML/Graphics.hpp>

class CSprite : public sf::Drawable, public sf::Transformable
{
public:
  CSprite(const std::string& fielName); ///< konstruktor
  ~CSprite();                                                                                                               ///< destruktor

protected:
  sf::Texture mTexture;     ///< obraz (tekstura) przycisku
  sf::Sprite mSprite;       ///< obiekt graficzny przycisku

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // rysuj przycisk
};

