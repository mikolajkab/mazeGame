///
/// funkcja reprezentuje przycisk
/// dziedziczy Drawable i Transformable z biblioteki SFML
///

#pragma once

#include <SFML/Graphics.hpp>

#include "Utilities.h"
#include "Image.h"

class CButton : public CImage
{
public:
  CButton(const std::string& fielName, int positionX, int positionY, int colorR = 255, int colorG = 255, int colorB = 255); ///< konstruktor
  ~CButton();                                                                                                               ///< destruktor
};

