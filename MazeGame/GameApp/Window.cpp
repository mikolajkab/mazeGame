#include "Window.h"
#include "MazeMap.h"

CWindow::CWindow(int width, int height, std::string name)
  : mRenderWindow(sf::VideoMode(width, height), name, sf::Style::Close)
  , mMazeMap(make_shared<CMazeMap>(1))
  , mMaze(make_unique<CMaze>("tileset2.png", mMazeMap))
  , mRun(false)
{
  mButtons.push_back(make_unique<CButton>("start.png", sButPosX, sButStartPosY));
  mButtons.push_back(make_unique<CButton>("stop.png", sButPosX, sButStopPosY));
  mButtons.push_back(make_unique<CButton>("reset.png", sButPosX, sButResetPosY));
  mButtons.push_back(make_unique<CButton>("wallFollower.png", sButPosX, sButWFPosY));
  mButtons.push_back(make_unique<CButton>("bruteForce.png", sButPosX, sButBFPosY));
  mButtons.push_back(make_unique<CButton>("zmianaMapy.png", sButPosX, sButSwitchMapY));
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
  mRenderWindow.clear(sf::Color(0, 0, sColorBlue, 0));
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
  switchMap();
}

void CWindow::addMouse()
{
  if (isCompMouseInPosition(sButPosX, sButWFPosY, sButSideLen, sButSideLen))
  {
    SPosition initialPosition;
    initialPosition.col = 0;
    initialPosition.row = 0;
    mMice.push_back(make_unique<CMouse>("mouseWallFollower.png", mMazeMap, initialPosition, CMouse::sAlgNumWallFollower));
  }
  else if (isCompMouseInPosition(sButPosX, sButBFPosY, sButSideLen, sButSideLen))
  {
    SPosition initialPosition;
    initialPosition.col = 0;
    initialPosition.row = 0;
    mMice.push_back(make_unique<CMouse>("mouseBruteForce.png", mMazeMap, initialPosition, CMouse::sAlgNumBruteForce));
  }
}

void CWindow::switchMap()
{
  if (isCompMouseInPosition(sButPosX, sButSwitchMapY, sButSideLen, sButSideLen))
  {
    mMice.clear();
    mRun = false;
    mMazeMap->switchMap();
    mMaze.reset();
    mMaze = make_unique<CMaze>("tileset2.png", mMazeMap);
  }
}

void CWindow::startStopReset()
{
  if (isCompMouseInPosition(sButPosX, sButStartPosY, sButSideLen, sButSideLen))
  {
    mRun = true;
  }
  else if (isCompMouseInPosition(sButPosX, sButStopPosY, sButSideLen, sButSideLen))
  {
    mRun = false;
  }
  else if (isCompMouseInPosition(sButPosX, sButResetPosY, sButSideLen, sButSideLen))
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

