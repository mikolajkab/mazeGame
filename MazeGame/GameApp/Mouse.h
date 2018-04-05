///
/// klasa reprezentujaca mysz
/// dziedziczy CImage
///

#pragma once

#include "Tile.h"
#include "MazeMap.h"
#include "WallFollower.h"
#include "BruteForce.h"
#include "Image.h"

class CMouse : public CImage
{
public:
  CMouse(const std::string& fielName, std::shared_ptr<CMazeMap> mazeMap, SPosition position, EAlgorithm algNum);  ///< konstruktor
  virtual ~CMouse();                                                                                              ///< destruktor
  void go();                                                                                                      ///< wykonuje jeden krok

private:
  std::unique_ptr<CStepper> mStepper;   ///< wskaznik do klasy reprzentujacej krok
  SPosition mActualPosition;            ///< pozycja myszy

  void setSpritePosition(float angle);  ///< ustawiaj kat polozenia myszy
};

