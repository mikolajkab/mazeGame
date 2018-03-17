#include "Maze.h"

CMaze::CMaze(const std::string& fielName, CMazeMap& mazeMap)
{
  if (!mTexture.loadFromFile(fielName))
  {
    // TODO: trigger exception
  }

  // resize the vertex array to fit the level size
  mVertexArray.setPrimitiveType(sf::Quads);
  mVertexArray.resize(mazeMap.getWidth() * mazeMap.getHeight() * sNumVerticesInQuad);

  // populate the vertex array, with one quad per tile
  for (unsigned int row = 0; row < mazeMap.getHeight(); ++row)
    for (unsigned int col = 0; col < mazeMap.getWidth(); ++col)
    {
      // get a pointer to the current tile's quad
      sf::Vertex* quad = &mVertexArray[(row + col * mazeMap.getWidth()) * sNumVerticesInQuad];

      setQuadPositions(quad, row, col);

      int tileType = mazeMap.map[row][col].value;
      setQuadCoords(quad, row, col, tileType);
    }
}

CMaze::~CMaze()
{
}

void CMaze::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &mTexture;
  target.draw(mVertexArray, states);
}

void CMaze::setQuadPositions(sf::Vertex* quad, int row, int col)
{
  // define its 4 corners
  quad[0].position = sf::Vector2f((col * CTile::sWidth), (row * CTile::sHeight));
  quad[1].position = sf::Vector2f((col + 1) * CTile::sWidth, row * CTile::sHeight);
  quad[2].position = sf::Vector2f((col + 1) * CTile::sWidth, (row + 1) * CTile::sHeight);
  quad[3].position = sf::Vector2f(col * CTile::sWidth, (row + 1) * CTile::sHeight);
}

void CMaze::setQuadCoords(sf::Vertex* quad, int row, int col, int tileType)
{
  // find its position in the tileset texture
  int tu = tileType % (mTexture.getSize().x / CTile::sWidth);

  // define its 4 texture coordinates
  quad[0].texCoords = sf::Vector2f(tu * CTile::sWidth, 0);
  quad[1].texCoords = sf::Vector2f((tu + 1) * CTile::sWidth, 0);
  quad[2].texCoords = sf::Vector2f((tu + 1) * CTile::sWidth, CTile::sHeight);
  quad[3].texCoords = sf::Vector2f(tu * CTile::sWidth, CTile::sHeight);
}