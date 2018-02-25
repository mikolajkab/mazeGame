#include "Window.h"

CWindow::CWindow()
: mWindow(sf::VideoMode(200, 200), "SFML works!", sf::Style::Close)
, mShape(100.f)
{
	mShape.setFillColor(sf::Color::Green);
}

CWindow::~CWindow()
{
}

void CWindow::mainLoop()
{
	while (mWindow.isOpen())
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mWindow.close();
		}

		sf::Time elapsed = mClock.restart();

		mWindow.clear();
		mWindow.draw(mShape);
		mWindow.display();
	}
}