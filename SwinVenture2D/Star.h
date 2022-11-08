#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Object.h"
using namespace std;
class Star : public Object
{
private:
	float rarity;
public:
	Star();
	Star(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, float rarity, string filepath);
	~Star();
};

