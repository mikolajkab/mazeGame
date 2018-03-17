#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "MazeMap.h"

class CMouse : public sf::Drawable, public sf::Transformable
{
public:
  CMouse(const std::string& fielName, CMazeMap& mazeMap);
  virtual ~CMouse();
  void goWallFollower();
  void goBruteForce();

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

  struct STile
  {
    UDirections wallPosition;
    bool visited;
  };

  static const SPosition stopPosition;

  CMazeMap* mActualMazeMap;
  STile mDetectedMazeMap[4][4];


  bool visited[3][3];

  void setSpritePosition(float angle);

  UDirections mLastStep;

};

