#include "Star.h"

Star::Star() : Object()
{
	cout << "Init Star" << endl;

	rarity = 1;
}

Star::Star(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size,float velocity, float rarity, string filepath)
	: Object(window, position, size, velocity, filepath)
{
	this->rarity = rarity;
}


Star::~Star()
{
}
