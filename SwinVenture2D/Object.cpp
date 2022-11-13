#include "Object.h"

Object::Object()
{
	cout << "Init Object" << endl;
	// nullptr because not use
	window = nullptr;

	// set object details
	position = sf::Vector2f(0, 0);
	size == sf::Vector2f(0, 0);
	init_velocity = 1;
	velocity = init_velocity;

	// load texture and sprite
	imageFilePath = "./res/images/poop.png";
	texture.loadFromFile(imageFilePath);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

Object::Object(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, float velocity, string filepath)
{
	cout << "Init Object" << endl;
	// nullptr because not use
	this->window = window;
	// set object details
	this->position = position;
	this->size = size;
	init_velocity = velocity;
	this->velocity = init_velocity;

	// load texture and sprite
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
