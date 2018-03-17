#include "Game.h"

CGame::CGame()
  : mWindow(mWindowHeight, mWindowWidth, "MicroMouse")
  , time(sf::milliseconds(200))
{
}

CGame::~CGame()
{
}

void CGame::runMainLoop()
{
  while (mWindow.isOpen())
  {
    if (mClock.getElapsedTime() > time)
    {
      mWindow.pollEvents();
      mWindow.clear();
      mWindow.display();
      sf::Time elapsed = mClock.restart();
    }
  }
}
