#pragma once

#include <SFML/Graphics.hpp>

#include "MazeMap.h"

class CTileMap : public sf::Drawable, public sf::Transformable
{
public:
  CTileMap(const std::string& tileset);
  ~CTileMap();

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void setQuadPositions(sf::Vertex* quad, int col, int row);
  void setQuadCoords(sf::Vertex* quad, int col, int row);

  const int* sTiles;

  sf::VertexArray mVertexArray;
  sf::Texture mTexture;
  sf::Vector2u tileSize;

  static constexpr int sTileWidth = 64;
  static constexpr int sTileHeight = 64;

  static constexpr int sMazeWidth = 16;
  static constexpr int sMazeHeight = 16;
};

