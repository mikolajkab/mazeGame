#include "Window.h"
#include "MazeMap.h"

CWindow::CWindow(int width, int height, std::string name)
  : mRenderWindow(sf::VideoMode(width, height), name, sf::Style::Close)
  , mMazeMap(make_shared<CMazeMap>())
  , mMaze(nullptr)
  , mMouse(nullptr)
  , mStartButton("start.png", 1150, 50)
  , mStopButton("stop.png", 1150, 200)
  , mResetButton("reset.png", 1150, 350)
  , mWallFollowerButton("wallFollower.png", 1150, 500)
  , mBruteForceButton("bruteForce.png", 1150, 650)
  , mRun(false)
{
  mMaze = make_unique<CMaze>("tileset2.png", mMazeMap);
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

    case sf::Event::MouseButtonPressed:
    {
      handleButtons();
    }

    default:
      break;
    }
  }
}

void CWindow::clear()
{
  mRenderWindow.clear(sf::Color(0, 0, 150, 0));
}

void CWindow::display()
{

  if (mMaze != nullptr)
  {
    mRenderWindow.draw(*mMaze);
  }
  if (mMouse != nullptr)
  {
    if (mRun)
    {
      mMouse->go();
    }
    mRenderWindow.draw(*mMouse);
  }
  mRenderWindow.draw(mStartButton);
  mRenderWindow.draw(mStopButton);
  mRenderWindow.draw(mResetButton);
  mRenderWindow.draw(mWallFollowerButton);
  mRenderWindow.draw(mBruteForceButton);
  mRenderWindow.display();
}

void CWindow::handleButtons()
{
  startStopReset();
  addMouse();
}

void CWindow::addMouse()
{
  if ((mMouse == nullptr) && (isMouseInPosition(1150, 500, 150, 150)))
  {
    SPosition initialPosition;
    initialPosition.col = 0;
    initialPosition.row = 0;
    mMouse = make_unique<CMouse>("mouse.png", mMazeMap, initialPosition);
  }
}

void CWindow::startStopReset()
{
  if (isMouseInPosition(1150, 50, 150, 150))
  {
    mRun = true;
  }
  else if (isMouseInPosition(1150, 200, 150, 150))
  {
    mRun = false;
  }
  else if (isMouseInPosition(1150, 350, 150, 150))
  {
    mMouse = nullptr;
    mRun = false;
  }
}

bool CWindow::isMouseInPosition(int positionX, int positionY, int width, int height)
{
  sf::Vector2i localPosition = sf::Mouse::getPosition(mRenderWindow);
  if((localPosition.x>positionX) && (localPosition.x<positionX+width)
      && (localPosition.y>positionY) && (localPosition.y<positionY + height))
  {
    return true;
  }
  return false;
}
