#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"

using std::array;

class CMaze : public sf::Drawable, public sf::Transformable
{
public:
  CMaze(const std::string& fielName, const UWallPosition (*mazeMap)[4]);
  ~CMaze();

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void setQuadPositions(sf::Vertex* quad, int col, int row);
  void setQuadCoords(sf::Vertex* quad, int col, int row);

  const UWallPosition (*mMazeMap)[4] ;

  sf::VertexArray mVertexArray;
  sf::Texture mTexture;

  static constexpr int sWidth = 4;
  static constexpr int sHeight = 4;
  static constexpr int sNumVerticesInQuad = 4;
};

