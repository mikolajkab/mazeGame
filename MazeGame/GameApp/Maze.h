#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Tile.h"
#include "MazeMap.h"

using std::array;

class CMaze : public sf::Drawable, public sf::Transformable
{
public:
  CMaze(const std::string& fielName, std::shared_ptr<CMazeMap> mazeMap);
  ~CMaze();

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void setQuadPositions(sf::Vertex* quad, int col, int row);
  void setQuadCoords(sf::Vertex* quad, int col, int row, int tileType);

  sf::VertexArray mVertexArray;
  sf::Texture mTexture;

  static constexpr int sNumVerticesInQuad = 4;
};

