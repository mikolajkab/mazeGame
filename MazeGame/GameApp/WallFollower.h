#pragma once

#include "Stepper.h"

class CWallFollower : public CStepper
{
public:
  CWallFollower(SPosition position, std::shared_ptr<CMazeMap> mazeMap);
  virtual ~CWallFollower();
  SPosition go() override;

private:
  bool wasVisited();
};

