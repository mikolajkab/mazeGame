#include "Maze.h"

CMaze::CMaze(const std::string& tileset)
{
  for (unsigned int col = 0; col < sMazeWidth; ++col)
    for (unsigned int row = 0; row < sMazeHeight; ++row)
    {
      mMazeMap[col][row].setWall(mazeMap2[col][row]);
    }
  sMazeMap = mazeMap1;

  // load the tileset texture
  if (!mTexture.loadFromFile(tileset))
  {
    //return false;
  }

  // resize the vertex array to fit the level size
  mVertexArray.setPrimitiveType(sf::Quads);
  mVertexArray.resize(sMazeWidth * sMazeHeight * 4);

  // populate the vertex array, with one quad per tile
  for (unsigned int col = 0; col < sMazeWidth; ++col)
    for (unsigned int row = 0; row < sMazeHeight; ++row)
    {
      // get a pointer to the current tile's quad
      sf::Vertex* quad = &mVertexArray[(col + row * sMazeWidth) * 4];

      setQuadPositions(quad, col, row);
      setQuadCoords(quad, col, row);
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

void CMaze::setQuadPositions(sf::Vertex* quad, int col, int row)
{
  // define its 4 corners
  quad[0].position = sf::Vector2f((col * sTileWidth), (row * sTileHeight));
  quad[1].position = sf::Vector2f((col + 1) * sTileWidth, row * sTileHeight);
  quad[2].position = sf::Vector2f((col + 1) * sTileWidth, (row + 1) * sTileHeight);
  quad[3].position = sf::Vector2f(col * sTileWidth, (row + 1) * sTileHeight);
}

void CMaze::setQuadCoords(sf::Vertex* quad, int col, int row)
{
  // get the current tile number
  int tileNumber = sMazeMap[col + row * sMazeWidth];

  // find its position in the tileset texture
  int tu = tileNumber % (mTexture.getSize().x / sTileWidth);
  int tv = tileNumber / (mTexture.getSize().x / sTileWidth);

  // define its 4 texture coordinates
  quad[0].texCoords = sf::Vector2f(tu * sTileWidth, tv * sTileHeight);
  quad[1].texCoords = sf::Vector2f((tu + 1) * sTileWidth, tv * sTileHeight);
  quad[2].texCoords = sf::Vector2f((tu + 1) * sTileWidth, (tv + 1) * sTileHeight);
  quad[3].texCoords = sf::Vector2f(tu * sTileWidth, (tv + 1) * sTileHeight);
}
