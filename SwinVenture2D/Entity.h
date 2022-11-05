#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
class Entity
{
protected:
	sf::RenderWindow* window;
	string image_path;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Texture texture;
	sf::Sprite sprite;
	
	float initVelocity = 1;
	float velocity = initVelocity;
	float gravity = 1.08;
	float terminalSpeed = 20;
	bool isFall = false;
	bool isJump = false;

public:
	Entity();
	Entity(sf::RenderWindow* window, string image_path = "./res/images/player.png", sf::Vector2f position = sf::Vector2f(520 , 467), sf::Vector2f size = sf::Vector2f(57, 189));
	~Entity();
	//getter
	sf::RenderWindow* getWindow() { return window; }
	string getImagePath() { return image_path; }
	sf::Vector2f getPosition() { return position; }
	float getVelocity() { return velocity; }
	sf::Vector2f getSize() { return size; }
	sf::Texture getTexture() { return texture; }
	sf::Sprite getSprite() { return sprite; }
	bool getIsFall() { return isFall; }
	bool getIsJump() { return isJump; }
	float getGravity() { return gravity; }

	
	//setter
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void setImagePath(string image_path) { this->image_path = image_path; }
	void setPosition(sf::Vector2f position) { this->position = position; }
	void setVelocity(float velocity) { this->velocity = velocity; }
	void setSize(sf::Vector2f size) { this->size = size; }
	void setTexture(sf::Texture texture) { this->texture = texture; }
	void setSprite(sf::Sprite sprite) { this->sprite = sprite; }
	void setIsFall(bool isFall) { this->isFall = isFall; }
	void setIsJump(bool isJump) { this->isJump = isJump; }
	void setGravity(float gravity) { this->gravity = gravity; }
	
	void fall();
	
	void jump();

	void update();
	void render();

};

