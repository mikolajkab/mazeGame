///
/// Klasa reprezentujaca labirynt
/// dziedziczy Drawable i Transformable z biblioteki SFML
///

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Tile.h"
#include "MazeMap.h"

class CMaze : public sf::Drawable, public sf::Transformable
{
public:
  CMaze(const std::string& fielName, std::shared_ptr<CMazeMap> mazeMap);    ///< konstruktor
  ~CMaze();                                                                 ///< destruktor

private:
  sf::VertexArray mVertexArray;     ///< macierz reprezentujaca tlo (kafelki)
  sf::Texture mTexture;             ///< plik reprezentujacy tlo

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; ///< funkcja rysujaca tlo (z biblioteki SFML)
  void setQuadPositions(sf::Vertex* quad, int col, int row);                  ///< funkcja wyznaczca pozycje kafelki na mapie
  void setQuadCoords(sf::Vertex* quad, int col, int row, int tileType);       ///< funkcja wyznaczajaca pozycje kafelki w pliku graficznym

  static constexpr int sNumVerticesInQuad = 4;                                ///< ilosc punktow wyznaczajacych kafelke (4 bo kwadrat)
};

