#include "Window.h"

CWindow::CWindow(int width, int height, std::string name)
  : mWindow(sf::VideoMode(width, height), name, sf::Style::Close)
  , map("tileset.png")
{
}

CWindow::~CWindow()
{
}

bool CWindow::isOpen() const
{
  return mWindow.isOpen();
}

void CWindow::pollEvents()
{
  sf::Event event;
  while (mWindow.pollEvent(event))
  {
    switch (event.type)
    {
    // window closed
    case sf::Event::Closed:
      mWindow.close();
      break;

    default:
      break;
    }
  }
  //sf::Time elapsed = mClock.restart();
}

void CWindow::clear()
{
  mWindow.clear(sf::Color::Black);
}
void CWindow::display()
{
  mWindow.draw(map);
  mWindow.display();
}