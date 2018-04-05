///
/// klasa reprezentujaca krok
///
#pragma once

#include <array>
#include <memory>

#include "Utilities.h"
#include "MazeMap.h"

class CStepper
{
public:
  CStepper(SPosition position, std::shared_ptr<CMazeMap> mazeMap);  ///< konstruktor
  ~CStepper();                                                      ///< destruktor
  virtual SPosition go() = 0;                                       ///< funkcja wirtualna wykonujaca krok
  bool atGoal();                                                    ///< sprawdz czy mysz dotarla do celu

protected:
  SPosition mActualPosition;                ///< aktualna pozycja myszy
  UDirections mLastStep;                    ///< kierunek ostatniego kroku
  std::shared_ptr<CMazeMap> mActualMazeMap; ///< wskaznik do mapy labiryntu

  /// struktura przechwuje informacjce o plytce:
  /// - pozyje scian,
  /// - kierunek pierwszego wejscia,
  /// - czy byla juz odwiedzana
  struct STileInfo
  {
    UDirections wallPosition;
    UDirections firstEntranceDirection;
    bool visited;
  };

  std::array<std::array<STileInfo, CMazeMap::sWidth>, CMazeMap::sHeight> mDetectedMazeMap; ///< mapa labiryntu rozpoznana przez mysz

  void goNorth();     ///< idz na polnoc
  void goSouth();     ///< idz na poludnie
  void goEast();      ///< idz na wschod
  void goWest();      ///< idz na zachod
  void checkWalls();  ///< sprawdz pozycje scian
  void setVisited();  ///< zapamietaj ze plytka byla odwiedzana
  void setFirstEntranceDirection(int row, int col, UDirections direction); ///< zapamietaj kierunek pierwszego wejscia
};

