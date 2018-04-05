///
/// klasa reprezentuje algorytm brute force
///

#pragma once

#include "Stepper.h"

class CBruteForce : public CStepper
{
public:
  CBruteForce(SPosition position, std::shared_ptr<CMazeMap> mazeMap); ///< konstruktor
  virtual ~CBruteForce();                                             ///< destruktor
  SPosition go() override;                                            ///< wykonuj krok wg algorytmu brute force

private:
  UDirections getPossibleDirections();                                ///< sprawdzaj mozliwe kierunki
  UDirections generateDirection(UDirections possibleDirections);      ///< generuj losowo jeden wy mozliwych kierunkow
  void goInDirection(UDirections direction);                          ///< wykonuj krok w wybranym kierunku
};

