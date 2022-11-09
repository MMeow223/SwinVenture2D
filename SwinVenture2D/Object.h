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
	
	sf::Vector2f init_position;
	sf::Vector2f position;
	sf::Vector2f init_size;
	sf::Vector2f size;
	float initVelocity;
	float velocity;

public:
	Object();
	Object(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, string filepath);
	~Object();
	
	//getter
	virtual sf::RenderWindow* getWindow() { return window; }
	virtual sf::Sprite getSprite() { return sprite; }
	virtual sf::Texture getTexture() { return texture; }
	virtual sf::Vector2f getPosition() { return position; }
	virtual sf::Vector2f getSize() { return size; }
	virtual float getInitVelocity() { return initVelocity; }
	virtual float getVelocity() { return velocity; }

	//setter
	virtual void setWindow(sf::RenderWindow* window) { this->window = window; }
	virtual void setSprite(sf::Sprite sprite) { this->sprite = sprite; }
	virtual void setTexture(sf::Texture texture) { this->texture = texture; }
	virtual void setPosition(sf::Vector2f position) { this->position = position; }
	virtual void setSize(sf::Vector2f size) { this->size = size; }
	virtual void setInitVelocity(float initVelocity) { this->initVelocity = initVelocity; }
	virtual void setVelocity(float velocity) { this->velocity = velocity; }

	virtual void update();
	virtual void render();
};

