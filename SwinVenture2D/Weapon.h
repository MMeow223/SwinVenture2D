#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Object.h"
using namespace std;
class Weapon : public Object
{
private:
	float max_distance;
	float damage;
	float count = 0;

	bool isFinish = false;

public:
	Weapon();
	Weapon(sf::RenderWindow* window,sf::Vector2f position, float max_distance = 3);
	~Weapon();
	
	//getter
	float getMaxDistance() { return max_distance; }
	float getDamage() { return damage; }
	bool getIsFinish() { return isFinish; }	
	//setter
	void setMaxDistance(float max_distance) { this->max_distance = max_distance; }
	void setDamage(float damage) { this->damage = damage; }
	void setIsFinish(bool isFinish) { this->isFinish = isFinish; }
	
	void update();
};

