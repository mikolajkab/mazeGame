#include "Game.h"

CGame::CGame()
  : mWindow(1024, 1024, "MicroMouse")
{
}

CGame::~CGame()
{
}

void CGame::runMainLoop()
{
  while (mWindow.isOpen())
  {
    mWindow.pollEvents();
    mWindow.clear();
    mWindow.display();
  }
}