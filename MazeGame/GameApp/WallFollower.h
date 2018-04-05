///
/// klasa reprezentuje algorytm wall follower
///

#pragma once

#include "Stepper.h"

class CWallFollower : public CStepper
{
public:
  CWallFollower(SPosition position, std::shared_ptr<CMazeMap> mazeMap); ///< konstruktor
  virtual ~CWallFollower();                                             ///< destruktor
  SPosition go() override;                                              ///< wykonaj krok we algorytmu wall follower
};

