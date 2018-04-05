///
/// funkcja reprezentuje przycisk
/// dziedziczy CImage
///

#pragma once

#include "Image.h"

class CButton : public CImage
{
public:
  CButton(const std::string& fielName, int positionX, int positionY, int colorR = 255, int colorG = 255, int colorB = 255); ///< konstruktor
  ~CButton();                                                                                                               ///< destruktor
};

