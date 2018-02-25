#pragma once
#include <SFML/Graphics.hpp>

class CWindow 
{
public:
	CWindow();
	virtual ~CWindow();
	void mainLoop();

private:
	sf::RenderWindow mWindow;
	sf::Clock mClock;
	sf::CircleShape mShape;

};

