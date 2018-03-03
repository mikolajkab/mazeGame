#pragma once

#include <SFML/Graphics.hpp>

class CTileMap : public sf::Drawable, public sf::Transformable
{
public:
  CTileMap();
  ~CTileMap();

  bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  sf::VertexArray mVertexArray;
  sf::Texture mTexture;
};

