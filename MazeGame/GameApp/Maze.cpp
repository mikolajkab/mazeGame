#include "Maze.h"
#include "MazeMap.h"

CMaze::CMaze(const std::string& fielName)
{
  mMazeMap = mazeMap3;

  // load the tileset texture
  if (!mTexture.loadFromFile(fielName))
  {
    // TODO: trigger exception
  }

  // resize the vertex array to fit the level size
  mVertexArray.setPrimitiveType(sf::Quads);
  mVertexArray.resize(sWidth * sHeight * sNumVerticesInQuad);

  // populate the vertex array, with one quad per tile
  for (unsigned int row = 0; row < sWidth; ++row)
    for (unsigned int col = 0; col < sHeight; ++col)
    {
      // get a pointer to the current tile's quad
      sf::Vertex* quad = &mVertexArray[(row + col * sWidth) * sNumVerticesInQuad];

      setQuadPositions(quad, row, col);
      setQuadCoords(quad, row, col);
    }
}

CMaze::~CMaze()
{
}

void CMaze::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // apply the transform
  states.transform *= getTransform();

  // apply the tileset texture
  states.texture = &mTexture;

  // draw the vertex array
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

void CMaze::setQuadCoords(sf::Vertex* quad, int row, int col)
{
  // get the current tile number
  int tileType = mMazeMap[row][col].value;

  // find its position in the tileset texture
  int tu = tileType % (mTexture.getSize().x / CTile::sWidth);

  // define its 4 texture coordinates
  quad[0].texCoords = sf::Vector2f(tu * CTile::sWidth, 0);
  quad[1].texCoords = sf::Vector2f((tu + 1) * CTile::sWidth, 0);
  quad[2].texCoords = sf::Vector2f((tu + 1) * CTile::sWidth, CTile::sHeight);
  quad[3].texCoords = sf::Vector2f(tu * CTile::sWidth, CTile::sHeight);
}