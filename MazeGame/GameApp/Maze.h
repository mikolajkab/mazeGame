#pragma once

#include <SFML/Graphics.hpp>

#include "MazeMap.h"
#include "Tile.h"

using std::array;

class CMaze : public sf::Drawable, public sf::Transformable
{
public:
  CMaze(const std::string& tileset);
  ~CMaze();

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void setQuadPositions(sf::Vertex* quad, int col, int row);
  void setQuadCoords(sf::Vertex* quad, int col, int row);

  const int* sMazeMap;

  sf::VertexArray mVertexArray;
  sf::Texture mTexture;

  static constexpr int sMazeWidth = 4;
  static constexpr int sMazeHeight = 4;

  CTile mMazeMap[sMazeWidth][sMazeHeight];

};

