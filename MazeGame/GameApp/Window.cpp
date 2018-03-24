#include "Window.h"
#include "MazeMap.h"

CWindow::CWindow(int width, int height, std::string name)
  : mRenderWindow(sf::VideoMode(width, height), name, sf::Style::Close)
  , mMazeMap(make_shared<CMazeMap>())
  , mMaze(make_unique<CMaze>("tileset2.png", mMazeMap))
  , mRun(false)
{
  mButtons.push_back(make_unique<CButton>("start.png", 1150, 50));
  mButtons.push_back(make_unique<CButton>("stop.png", 1150, 200));
  mButtons.push_back(make_unique<CButton>("reset.png", 1150, 350));
  mButtons.push_back(make_unique<CButton>("wallFollower.png", 1150, 500));
  mButtons.push_back(make_unique<CButton>("bruteForce.png", 1150, 650));
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

  for (const auto& mouse : mMice)
  {
    if (mRun)
    {
      mouse->go();
    }
    mRenderWindow.draw(*mouse);
  }

  for (const auto& button : mButtons)
  {
    mRenderWindow.draw(*button);
  }

  mRenderWindow.display();
}

void CWindow::handleButtons()
{
  startStopReset();
  addMouse();
}

void CWindow::addMouse()
{
  if (isCompMouseInPosition(1150, 500, 150, 150))
  {
    SPosition initialPosition;
    initialPosition.col = 0;
    initialPosition.row = 0;
    mMice.push_back(make_unique<CMouse>("mouseWallFollower.png", mMazeMap, initialPosition, CMouse::sAlgNumWallFollower));
  }
  else if (isCompMouseInPosition(1150, 650, 150, 150))
  {
    SPosition initialPosition;
    initialPosition.col = 0;
    initialPosition.row = 0;
    mMice.push_back(make_unique<CMouse>("mouseBruteForce.png", mMazeMap, initialPosition, CMouse::sAlgNumBruteForce));
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
    mMice.clear();
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
