#pragma once

#include <cstdint>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>

using std::string;
using std::array;

static GLuint texName;

class CWindow
{
public:
  CWindow(const string& name, int argc = 0, char* argv[] = {});
  ~CWindow();

  void Init();
  void Display(void);
  void Reshape(void);
  void Loop(void);

private:
  const string mName;
  int mWindowHandle;

  static constexpr int sCurrentWidth = 80;
  static constexpr int sCurrentHeight = 80;

  static void DrawImage(void);
};