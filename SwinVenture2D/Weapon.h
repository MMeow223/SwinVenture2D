#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
class Weapon
{
private:
	sf::RenderWindow* window;
	sf::Texture texture;
	sf::Sprite sprite;
	float max_distance;
	float damage;
	sf::Vector2f init_position;
	sf::Vector2f position;
	sf::Vector2f size;
	float count = 0;
	sf::Text text;
	sf::Font font;

	bool isFinish = false;

public:
	Weapon();
	Weapon(sf::RenderWindow* window,sf::Vector2f position, float max_distance = 3);
	~Weapon();
	
	//getter
	sf::Texture getTexture() { return texture; }
	sf::Vector2f getPosition() { return position; }
	sf::Vector2f getSize() { return size; }
	float getMaxDistance() { return max_distance; }
	float getDamage() { return damage; }
	bool getIsFinish() { return isFinish; }	
	//setter
	void setTexture(sf::Texture texture) { this->texture = texture; }
	void setPosition(sf::Vector2f position) { this->position = position; }
	void setSize(sf::Vector2f size) { this->size = size; }
	void setMaxDistance(float max_distance) { this->max_distance = max_distance; }
	void setDamage(float damage) { this->damage = damage; }
	void setIsFinish(bool isFinish) { this->isFinish = isFinish; }
	
	
	void update();
	void render();
};

