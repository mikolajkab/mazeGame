#pragma once

#include "Step.h"

class CWallFollower : public CStep
{
public:
  CWallFollower(SPosition position, std::shared_ptr<CMazeMap> mazeMap);
  virtual ~CWallFollower();
  SPosition go() override;

private:
  bool wasVisited();
};

