#include "Maze.h"
#include "MazeMap.h"

CMaze::CMaze(const std::string& tileset)
{
  //for (unsigned int col = 0; col < sWidth; ++col)
  //  for (unsigned int row = 0; row < sHeight; ++row)
  //  {
  //    mMazeMap[col][row].setWall(mazeMap2[col][row]);
  //  }

  mMazeMap = mazeMap2;

  // load the tileset texture
  if (!mTexture.loadFromFile(tileset))
  {
    //return false;
  }

  // resize the vertex array to fit the level size
  mVertexArray.setPrimitiveType(sf::Quads);
  mVertexArray.resize(sWidth * sHeight * 4);

  // populate the vertex array, with one quad per tile
  for (unsigned int col = 0; col < sWidth; ++col)
    for (unsigned int row = 0; row < sHeight; ++row)
    {
      // get a pointer to the current tile's quad
      sf::Vertex* quad = &mVertexArray[(col + row * sWidth) * 4];

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
  quad[0].position = sf::Vector2f((col * CTile::sWidth), (row * CTile::sHeight));
  quad[1].position = sf::Vector2f((col + 1) * CTile::sWidth, row * CTile::sHeight);
  quad[2].position = sf::Vector2f((col + 1) * CTile::sWidth, (row + 1) * CTile::sHeight);
  quad[3].position = sf::Vector2f(col * CTile::sWidth, (row + 1) * CTile::sHeight);
}

void CMaze::setQuadCoords(sf::Vertex* quad, int col, int row)
{
  //// get the current tile number
  //int tileNumber = mMazeMap[col + row * sWidth];

  //// find its position in the tileset texture
  //int tu = tileNumber % (mTexture.getSize().x / CTile::sWidth);
  //int tv = tileNumber / (mTexture.getSize().x / CTile::sWidth);

  int tu = 1;
  int tv = 2;
  // define its 4 texture coordinates
  quad[0].texCoords = sf::Vector2f(tu * CTile::sWidth, tv * CTile::sHeight);
  quad[1].texCoords = sf::Vector2f((tu + 1) * CTile::sWidth, tv * CTile::sHeight);
  quad[2].texCoords = sf::Vector2f((tu + 1) * CTile::sWidth, (tv + 1) * CTile::sHeight);
  quad[3].texCoords = sf::Vector2f(tu * CTile::sWidth, (tv + 1) * CTile::sHeight);
}
