#include "Window.h"
#include "MazeMap.h"

CWindow::CWindow(int width, int height, std::string name)
  : mRenderWindow(sf::VideoMode(width, height), name, sf::Style::Close)
  , mMazeMap(make_shared<CMazeMap>())
  , mMaze(make_unique<CMaze>("tileset2.png", mMazeMap))
  , mMouse(nullptr)
  , mStartButton(make_unique<CButton>("start.png", 1150, 50))
  , mStopButton(make_unique<CButton>("stop.png", 1150, 200))
  , mResetButton(make_unique<CButton>("reset.png", 1150, 350))
  , mWallFollowerButton(make_unique<CButton>("wallFollower.png", 1150, 500))
  , mBruteForceButton(make_unique<CButton>("bruteForce.png", 1150, 650))
  , mRun(false)
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
    case sf::Event::Closed:
      mRenderWindow.close();
      break;

    case sf::Event::MouseButtonPressed:
      handleButtons();
      break;

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
  mRenderWindow.draw(*mStartButton);
  mRenderWindow.draw(*mStopButton);
  mRenderWindow.draw(*mResetButton);
  mRenderWindow.draw(*mWallFollowerButton);
  mRenderWindow.draw(*mBruteForceButton);
  mRenderWindow.display();
}

void CWindow::handleButtons()
{
  startStopReset();
  addMouse();
}

void CWindow::addMouse()
{
  if ((mMouse == nullptr) && (isCompMouseInPosition(1150, 500, 150, 150)))
  {
    SPosition initialPosition;
    initialPosition.col = 0;
    initialPosition.row = 0;
    mMouse = make_unique<CMouse>("mouse.png", mMazeMap, initialPosition);
  }
}

void CWindow::startStopReset()
{
  if (isCompMouseInPosition(1150, 50, 150, 150))
  {
    mRun = true;
  }
  else if (isCompMouseInPosition(1150, 200, 150, 150))
  {
    mRun = false;
  }
  else if (isCompMouseInPosition(1150, 350, 150, 150))
  {
    mMouse = nullptr;
    mRun = false;
  }
}

bool CWindow::isCompMouseInPosition(int positionX, int positionY, int width, int height)
{
  sf::Vector2i localPosition = sf::Mouse::getPosition(mRenderWindow);
  if((localPosition.x>positionX) && (localPosition.x<positionX+width)
      && (localPosition.y>positionY) && (localPosition.y<positionY + height))
  {
    return true;
  }
  return false;
}
