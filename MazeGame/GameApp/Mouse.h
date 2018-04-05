///
/// klasa reprezentujaca mysz
/// dziedziczy Drawable i Transformable z biblioteki SFML
///

#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "MazeMap.h"
#include "WallFollower.h"
#include "BruteForce.h"

class CMouse : public sf::Drawable, public sf::Transformable
{
public:
  CMouse(const std::string& fielName, std::shared_ptr<CMazeMap> mazeMap, SPosition position, EAlgorithm algNum);  ///< konstruktor
  virtual ~CMouse();                                                                                              ///< destruktor
  void go();                                                                                                      ///< wykonuje jeden krok

private:
  std::unique_ptr<CStepper> mStepper; ///< wskaznik do klasy reprzentujacej krok
  sf::Texture mTexture;               ///< obraz (tekstura) myszy
  sf::Sprite mSprite;                 ///< obiekt grficzny myszy
  SPosition mActualPosition;          ///< pozycja myszy

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; ///< funkcja rysujaca mysz
  void setSpritePosition(float angle);                                        ///< funkcja ustawiajaca kat polozenia myszy
};

