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
  SPosition go() override;                                            ///< funkcja wykonuje krok wg algorytmu brute force

private:
  UDirections getPossibleDirections();                                ///< funkcja sprawdza mozliwe kierunki
  UDirections generateDirection(UDirections possibleDirections);      ///< funkcja generuje losowo jeden wy mozliwych kierunkow
  void goInDirection(UDirections direction);                          ///< funkcja wykonuje krokw wybranym kierunku
};

