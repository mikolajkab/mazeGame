#include "Window.h"
#include "MazeMap.h"

CWindow::CWindow(int width, int height, std::string name)
  : mRenderWindow(sf::VideoMode(width, height), name, sf::Style::Close)
  , mMazeMap(make_shared<CMazeMap>())
  , mMaze(nullptr)
  , mMouse(nullptr)
{
  mMaze = make_unique<CMaze>("tileset2.png", mMazeMap);

  SPosition initialPosition;
  initialPosition.col = 0;
  initialPosition.row = 0;
  mMouse = make_unique<CMouse>("mouse.png", mMazeMap, initialPosition);
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
  if (mMaze != nullptr)
  {
    mRenderWindow.draw(*mMaze);
  }
  if (mMouse != nullptr)
  {
    mMouse->go();
    mRenderWindow.draw(*mMouse);
  }
  mRenderWindow.display();
}