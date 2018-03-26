///
/// Klasa reprezentujaca glowne okno gry
///

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Maze.h"
#include "Mouse.h"
#include "MazeMap.h"
#include "Button.h"
#include "WallPosition.h"

class CWindow
{
public:
  CWindow(int length, int width, std::string name); ///< konstruktor
  ~CWindow();                                       ///< destruktor

  void pollEvents();    ///< monitoruje wystapienie wydarzen takich jak klikniecie myszka, zamkniete okna itp
  bool isOpen() const;  ///< zwraca true jezeli okno gry jest otwarte
  void display();       ///< wyswietla szystkie elementy gry
  void clear();         ///< usuwa wszystkie elementy gry

private:
  sf::RenderWindow mRenderWindow;     ///< okno na ktorym wyswietlane sa obrazy
  std::shared_ptr<CMazeMap> mMazeMap; ///< wskaznik do klasy reprezentujacej mape labiryntu
  std::unique_ptr<CMaze> mMaze;       ///< wskaznik do klasy reprezentujacej  labirynt

  std::vector<std::unique_ptr<CMouse>>  mMice;    ///< wskaznik do klasy reprezentujacej mysz
  std::vector<std::unique_ptr<CButton>> mButtons; ///< wskaznik do klasy reprezentujacej przycisk

  bool mRun;  ///< reprezentuje stan run lub stop

  void handleButtons();   ///< wywoluje odpowiednie funkcje w reakcji na klikniecie przyciskow
  void startStopReset();  ///< rozpoczyna, zatrzymuje lub restartuje program
  void addMouse();        ///< dodaje mysz na planszy
  void switchMap();       ///< zmiania plansze z labiryntem

  bool isCompMouseInPosition(int positionX, int positionY, int width, int height);  ///< zwrata true jesli mysz komputerowa jest podanym obszarze

  static constexpr int sButPosX       = 1150;   ///< szerokosc przycisku
  static constexpr int sButStartPosY  = 50;     ///< polozenie Y przycisku Start
  static constexpr int sButStopPosY   = 200;    ///< polozenie Y przycisku Stop
  static constexpr int sButResetPosY  = 350;    ///< polozenie Y przycisku Reset
  static constexpr int sButWFPosY     = 500;    ///< polozenie Y przycisku Wall Follower
  static constexpr int sButBFPosY     = 650;    ///< polozenie Y przycisku Brute Force
  static constexpr int sButSwitchMapY = 800;    ///< polozenie Y przycisku Zmiana Mapy
  static constexpr int sButSideLen    = 150;    ///< dlugosc boku przycisku
  static constexpr int sColorBlue     = 150;    ///< wartoc B w formacie RGB dla koluru niebieskiego
};

