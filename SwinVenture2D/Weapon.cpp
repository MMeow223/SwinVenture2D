#include "Weapon.h"

Weapon::Weapon() : Object()
{
	cout << "Init Weapon" << endl;
	
	// nullptr because not use
	window = nullptr;

	// load textures
	texture.loadFromFile("./res/images/poop.png");
	sprite.setTexture(texture);
	
	// set details
	size = sf::Vector2f(79, 143);
	init_position = sf::Vector2f(1080 / 2 - size.x / 2, 720 - 153 - size.y);
	position = init_position;
	max_distance = 3;
	damage = 30;
	sprite.setPosition(position);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

}

Weapon::Weapon(sf::RenderWindow* window,sf::Vector2f position,float max_distance)
{
	cout << "Init Weapon" << endl;
	
	// set window
	this->window = window;
	
	
	// set details
	this->init_position = position;
	this->position = init_position;
	size = sf::Vector2f(sprite.getLocalBounds().width,sprite.getLocalBounds().height);
	this->max_distance = max_distance;
	damage = 30;

	// load texture and sprites
	texture.loadFromFile("./res/images/poop.png");
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

}

Weapon::~Weapon()
{
}

void Weapon::update()
{
	// calculation for the throwing curve
	float x = count ;
	float y = -0.05 * (x * x) + (6.33 * x);
	if (count < 255) count+= 3;
	position = sf::Vector2f(count * max_distance + init_position.x, -y + init_position.y);
	
	// set the position of the sprite
	sprite.rotate(20);
	sprite.setPosition(position);

	// check if it drop on the ground and set the finish flag to true if so
	if (-y + init_position.y >= 567) isFinish = true;
}

