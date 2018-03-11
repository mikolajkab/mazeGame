#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "MazeMap.h"

class CMouse : public sf::Drawable, public sf::Transformable
{
public:
  CMouse(const std::string& fielName, CMazeMap& mazeMap);
  virtual ~CMouse();
  void move();

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void goNorth();
  void goSouth();
  void goEast();
  void goWest();
  void checkWalls();
  sf::Texture mTexture;
  sf::Sprite mSprite;

  struct SPosition
  {
    int row;
    int col;
  } mPosition;

  CMazeMap& mActualMazeMap;
  UWallPosition mDetectedMazeMap[4][4];

  void setSpritePosition(void);

  UWallPosition mLastStep;
};

