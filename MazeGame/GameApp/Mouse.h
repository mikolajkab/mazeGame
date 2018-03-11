#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "MazeMap.h"

class CMouse : public sf::Drawable, public sf::Transformable
{
public:
  CMouse(const std::string& fielName, CMazeMap& mazeMap);
  virtual ~CMouse();

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void goNorth();
  void goSouth();
  void goEast();
  void goWest();
  void checkWall();
  sf::Texture mTexture;
  sf::Sprite mSprite;

  struct SPosition
  {
    int row;
    int col;
  } mPosition;

  UWallPosition mDetectedMazeMap[][4];
};

