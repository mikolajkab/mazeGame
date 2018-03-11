#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"

class CMouse : public sf::Drawable, public sf::Transformable
{
public:
  CMouse(const std::string& fielName);
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

  const UWallPosition(*mActualMazeMap)[4];
  UWallPosition mDetectedMazeMap[][4];
};

