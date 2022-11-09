
#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Entity.h"
class Player : public Entity
{
public:
	Player() : Entity() {}
	Player(sf::RenderWindow* window) : Entity(window) {}
	~Player() {};

};

