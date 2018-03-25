#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "MazeMap.h"
#include "WallFollower.h"
#include "BruteForce.h"

class CMouse : public sf::Drawable, public sf::Transformable
{
public:
  CMouse(const std::string& fielName, std::shared_ptr<CMazeMap> mazeMap, SPosition position, int algNum);
  virtual ~CMouse();
  void go();

  static constexpr int sAlgNumWallFollower  = 1;
  static constexpr int sAlgNumBruteForce    = 2;

private:
  std::unique_ptr<CStepper> mStepper;
  sf::Texture mTexture;
  sf::Sprite mSprite;
  SPosition mActualPosition;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void setSpritePosition(float angle);
};

