#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "MazeMap.h"
#include "WallFollower.h"
#include "BruteForce.h"

class CMouse : public sf::Drawable, public sf::Transformable
{
public:
  CMouse(const std::string& fielName, std::shared_ptr<CMazeMap> mazeMap, SPosition position);
  virtual ~CMouse();
  void go();

private:
  std::unique_ptr<CStep> mStep;
  sf::Texture mTexture;
  sf::Sprite mSprite;
  SPosition mActualPosition;
  static const SPosition goalPosition;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void setSpritePosition(float angle);
  bool atGoal();
};

