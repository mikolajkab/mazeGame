///
/// klasa reprezentuje obraz, jest klasa bazowa dla CButton i CMouse
/// dziedziczy Drawable i Transformable z biblioteki SFML
///
#pragma once

#include <SFML/Graphics.hpp>


class CImage : public sf::Drawable, public sf::Transformable
{
public:
  CImage(const std::string& fielName); ///< konstruktor
  ~CImage();                           ///< destruktor

protected:
  sf::Texture mTexture;     ///< obraz (tekstura) przycisku
  sf::Sprite mSprite;       ///< obiekt graficzny przycisku

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // rysuj przycisk
};

