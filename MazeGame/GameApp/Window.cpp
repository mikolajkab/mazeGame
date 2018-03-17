#include "Window.h"
#include "MazeMap.h"

CWindow::CWindow(int width, int height, std::string name)
  : mRenderWindow(sf::VideoMode(width, height), name, sf::Style::Close)
  , mMazeMap()
  , mMaze("tileset2.png", mMazeMap)
  , mMouse("mouse.png", mMazeMap)
{
}

CWindow::~CWindow()
{
}

bool CWindow::isOpen() const
{
  return mRenderWindow.isOpen();
}

void CWindow::pollEvents()
{
  sf::Event event;
  while (mRenderWindow.pollEvent(event))
  {
    switch (event.type)
    {
    // window closed
    case sf::Event::Closed:
      mRenderWindow.close();
      break;

    default:
      break;
    }
  }
}

void CWindow::clear()
{
  mRenderWindow.clear(sf::Color::Black);
}

void CWindow::display()
{
  mRenderWindow.draw(mMaze);
  mMouse.goWallFollower();
  mRenderWindow.draw(mMouse);
  mRenderWindow.display();
}