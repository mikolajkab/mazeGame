#pragma once

#include <cstdint>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>

using std::string;

static GLuint texName;

class CWindow
{
public:
  CWindow(const string& name, int argc = 0, char* argv[] = {});
  ~CWindow();

  void Init();
  void Display(const int width, const int height, const void* pixels);
  void Reshape(void);
  void Loop(void);

private:
  const string mName;
  int mWindowHandle;

  static constexpr int sCurrentWidth = 800;
  static constexpr int sCurrentHeight = 800;

  static void DisplayGlut(void);
  static void ReshapeGlut(int w, int h);

  void SpecifyImage(const int width, const int height, const void* pixels);
};





//#pragma once
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdint>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string>
//#include <GL/glew.h>
//#include <GL/freeglut.h>
//
//#define WINDOW_TITLE_PREFIX "Maze Game"
//
//using std::string;
//
//class CWindow
//{
//public:
//  CWindow(const string& name, int argc, char* argv[]);
//  ~CWindow();
//
//private:
//  const string mName;
//  int mWindowHandle;
//  GLenum mGlewInitResult;
//
//  static unsigned FrameCount;
//  static int sCurrentWidth;
//  static int sCurrentHeight;
//
//  static GLuint VertexShaderId;
//  static GLuint FragmentShaderId;
//  static GLuint ProgramId;
//  static GLuint VaoId;
//  static GLuint VboId;
//  static GLuint ColorBufferId;
//
//  const GLchar* VertexShader =
//  {
//    "#version 400\n"\
//
//    "layout(location=0) in vec4 in_Position;\n"\
//    "layout(location=1) in vec4 in_Color;\n"\
//    "out vec4 ex_Color;\n"\
//
//    "void main(void)\n"\
//    "{\n"\
//    "  gl_Position = in_Position;\n"\
//    "  ex_Color = in_Color;\n"\
//    "}\n"
//  };
//
//  const GLchar* FragmentShader =
//  {
//    "#version 400\n"\
//
//    "in vec4 ex_Color;\n"\
//    "out vec4 out_Color;\n"\
//
//    "void main(void)\n"\
//    "{\n"\
//    "  out_Color = ex_Color;\n"\
//    "}\n"
//  };
//
//
//  void Init(int argc, char* argv[]);
//
//  static void sResize(int Width, int Height);
//  static void sRender(void);
//  static void TimerFunction(int);
//  static void IdleFunction(void);
//
//
//  static void Cleanup(void);
//  void CreateVBO(void);
//  static void DestroyVBO(void);
//  void CreateShaders(void);
//  static void DestroyShaders(void);
//
//  static constexpr float sRead = 0.0;
//  static constexpr float sGreen = 0.0;
//  static constexpr float sBlue = 0.0;
//  static constexpr float sAlpha = 0.0;
//  static constexpr int sGLintX = 0;
//  static constexpr int sGLintY = 0;
//  static constexpr int sMajorVersion = 4;
//  static constexpr int sMinorVersion = 0;
//
//  static constexpr int sMaxWIndowHandles = 1;
//
//};
//
