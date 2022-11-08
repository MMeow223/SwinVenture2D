#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
class Object
{
protected:
	sf::RenderWindow* window;
	string imageFilePath;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;
	sf::Vector2f size;
	float initVelocity;
	float velocity;

public:
	Object();
	Object(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, string filepath);
	~Object();
	
	//getter
	sf::RenderWindow* getWindow() { return window; }
	sf::Sprite getSprite() { return sprite; }
	sf::Texture getTexture() { return texture; }
	sf::Vector2f getPosition() { return position; }
	sf::Vector2f getSize() { return size; }
	float getInitVelocity() { return initVelocity; }
	float getVelocity() { return velocity; }

	//setter
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void setSprite(sf::Sprite sprite) { this->sprite = sprite; }
	void setTexture(sf::Texture texture) { this->texture = texture; }
	void setPosition(sf::Vector2f position) { this->position = position; }
	void setSize(sf::Vector2f size) { this->size = size; }
	void setInitVelocity(float initVelocity) { this->initVelocity = initVelocity; }
	void setVelocity(float velocity) { this->velocity = velocity; }

	void update();
	void render();
};

