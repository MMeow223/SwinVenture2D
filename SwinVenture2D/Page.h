#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Object.h"
class Page : public Object
{

public:
	Page();
	Page(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, string filepath);
	~Page();
	void render();

};

