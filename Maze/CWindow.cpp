#include "CWindow.h"

CWindow::CWindow(const string& name, int argc, char* argv[])
  : mName(name)
{
  glutInit(&argc, argv); // Initialize GLUT
  glutInitWindowSize(sCurrentWidth, sCurrentHeight);
  glutInitWindowPosition(800, 200);
  glutCreateWindow("Maze Game");
  glClearColor(0.0, 0.0, 0.0, 0.0); //  set the "clearing" or background color
}

CWindow::~CWindow()
{
}

void CWindow::Init()
{
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  glGenTextures(1, &texName);
  glBindTexture(GL_TEXTURE_2D, texName);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void CWindow::DrawImage(void)
{
  glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color


  glFlush();  // Render now
}

void CWindow::Display(void)
{
  // Define shapes enclosed within a pair of glBegin and glEnd
  glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
  glColor3f(1.0f, 0.0f, 0.0f); // Red
  glVertex2f(-0.8f, 0.1f);     // Define vertices in counter-clockwise (CCW) order
  glVertex2f(-0.2f, 0.1f);     //  so that the normal (front-face) is facing you
  glVertex2f(-0.2f, 0.7f);
  glVertex2f(-0.8f, 0.7f);

  glEnd();
  glutDisplayFunc(DrawImage);
}

void CWindow::Reshape(void)
{
}

void CWindow::Loop(void)
{
  glutMainLoop();
}