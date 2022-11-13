#include "Page.h"

Page::Page() : Object()
{
}

Page::Page(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, string filepath)
	: Object(window, position, size, velocity, filepath)
{
	// set size
	this->size = sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);
}

Page::~Page()
{
}

void Page::render()
{
	sprite.setPosition(position);
	window->draw(sprite);
}
