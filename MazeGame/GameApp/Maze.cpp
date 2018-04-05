#include "Maze.h"

CMaze::CMaze(const std::string& fielName, std::shared_ptr<CMazeMap> mazeMap)
{
  mTexture.loadFromFile(fielName);

  /// ustaw typ elementow w vertex array
  mVertexArray.setPrimitiveType(sf::Quads);
  mVertexArray.resize(mazeMap->getWidth() * mazeMap->getHeight() * sNumVerticesInQuad);

  /// wypelnik vertex array kafelkami
  for (unsigned int row = 0; row < mazeMap->getHeight(); ++row)
    for (unsigned int col = 0; col < mazeMap->getWidth(); ++col)
    {
      /// ustaw wskaznik do aktualnej kafelki
      sf::Vertex* quad = &mVertexArray[(row + col * mazeMap->getWidth()) * sNumVerticesInQuad];

      setQuadPositions(quad, row, col);

      int tileType = mazeMap->map[row][col].value;
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
  /// sdefiniuj pozycje wierzcholkow kafelki
  quad[0].position = sf::Vector2f((col * CTile::sWidth), (row * CTile::sHeight));
  quad[1].position = sf::Vector2f((col + 1) * CTile::sWidth, row * CTile::sHeight);
  quad[2].position = sf::Vector2f((col + 1) * CTile::sWidth, (row + 1) * CTile::sHeight);
  quad[3].position = sf::Vector2f(col * CTile::sWidth, (row + 1) * CTile::sHeight);
}

void CMaze::setQuadCoords(sf::Vertex* quad, int row, int col, int tileType)
{
  /// znajdz numer plytki
  int tu = tileType % (mTexture.getSize().x / CTile::sWidth);

  /// zdefinuj pozycje plytki w teksturze
  quad[0].texCoords = sf::Vector2f(tu * CTile::sWidth, 0);
  quad[1].texCoords = sf::Vector2f((tu + 1) * CTile::sWidth, 0);
  quad[2].texCoords = sf::Vector2f((tu + 1) * CTile::sWidth, CTile::sHeight);
  quad[3].texCoords = sf::Vector2f(tu * CTile::sWidth, CTile::sHeight);
}