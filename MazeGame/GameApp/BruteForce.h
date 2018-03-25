#pragma once

#include "Stepper.h"

class CBruteForce : public CStepper
{
public:
  CBruteForce(SPosition position, std::shared_ptr<CMazeMap> mazeMap);
  virtual ~CBruteForce();
  SPosition go() override;

private:
  UDirections getPossibleDirections();
  UDirections generateDirection(UDirections possibleDirections);
  void goInDirection(UDirections direction);
};

