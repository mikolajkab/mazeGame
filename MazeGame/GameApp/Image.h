#pragma once

#include <SFML/Graphics.hpp>


class CImage : public sf::Drawable, public sf::Transformable
{
public:
  CImage(const std::string& fielName);
  ~CImage();

protected:
  sf::Texture mTexture;     ///< obraz (tekstura) przycisku
  sf::Sprite mSprite;       ///< obiekt graficzny przycisku

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; // rysuj przycisk
};

