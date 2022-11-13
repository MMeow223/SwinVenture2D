#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <SFML/Graphics.hpp>

using namespace std;
class BackgroundLayer
{
private:
	// images, texture and sprite
	string image_path;
	sf::Texture texture;
	sf::Sprite sprite;
	
	// background detail
	float speed;
	sf::Vector2f position;

public:
	BackgroundLayer();
	BackgroundLayer(string image_path, float speed, sf::Vector2f position = sf::Vector2f(0.f, 0.f));
	~BackgroundLayer();

	//getter
	sf::Sprite getSprite() { return this->sprite; }
	sf::Vector2f getPosition() { return this->position; }
	float getSpeed() { return this->speed; }
	string getImagePath() { return this->image_path; }
	
	
	//setter
	void setSpeed(float speed) { this->speed = speed; }
	void setPosition(sf::Vector2f position) { this->position = position; }
	void setImagePath(string image_path) { this->image_path = image_path; }
	
	// functions
	void update();
	void render(sf::RenderWindow* window);
};

