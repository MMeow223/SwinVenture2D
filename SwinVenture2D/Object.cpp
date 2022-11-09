#include "Object.h"

Object::Object()
{
	cout << "Init Star" << endl;

	window = nullptr;
	position = sf::Vector2f(0, 0);
	size == sf::Vector2f(0, 0);
	initVelocity = 1;
	velocity = initVelocity;

	imageFilePath = "./res/images/poop.png";
	texture.loadFromFile(imageFilePath);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

Object::Object(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, string filepath)
{
	this->window = window;
	this->position = position;
	this->size = size;
	initVelocity = velocity;
	this->velocity = initVelocity;

	imageFilePath = filepath;
	texture.loadFromFile(imageFilePath);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

Object::~Object()
{
}

void Object::update()
{
	sprite.setPosition(position);
}

void Object::render()
{
	update();
	window->draw(sprite);
}
