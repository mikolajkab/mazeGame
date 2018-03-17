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
  void goInDirection(UDirections direction);
  void checkWalls();
  bool checkGoal();
  void setFirstEntranceDirection(int row, int col, UDirections direction);
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
    UDirections firstEntranceDirection;
    bool visited;
  };
  STile mDetectedMazeMap[4][4];
  CMazeMap* mActualMazeMap;
  static const SPosition goalPosition;

  UDirections mLastStep;

  void setVisited();
  UDirections generateDirection(UDirections possibleDirections);
  UDirections getPossibleDirections();


  void setSpritePosition(float angle);

};

