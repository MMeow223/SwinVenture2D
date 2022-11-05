#include "Entity.h"

Entity::Entity()
{
	image_path = "./res/images/player.png";
	//size = sf::Vector2f(2160, 153);
	size = sf::Vector2f(57, 189);
	position = sf::Vector2f(1080/2 - size.x/2,720-153-size.y);
	velocity = 1.5;

	texture.loadFromFile(image_path);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	//sprite.setScale(sf::Vector2f(0.1,0.1));

}

Entity::Entity(sf::RenderWindow* window, string image_path, sf::Vector2f position, sf::Vector2f size)
{
	this->window = window;
	this->image_path = image_path;
	this->size = size;
	this->position = position;
	velocity = 1.5;

	texture.loadFromFile(this->image_path);
	sprite.setTexture(texture);
	sprite.setPosition(this->position);
	//sprite.setScale(sf::Vector2f(0.1, 0.1));
}

Entity::~Entity()
{
}

void Entity::fall()
{
	
	if (velocity < terminalSpeed) {
		velocity *= gravity;
	}
	if (position.y < 567 - size.y) {
		position.y += velocity;
	}
	else {
		velocity = initVelocity;
		position.y = 567 - size.y;
		isJump = false;
	}
}

void Entity::jump()
{
	
	if (velocity < terminalSpeed) {
		velocity *= gravity;
	}
	else {
		velocity = initVelocity;
	}
	if (isJump) {
		if (position.y >= 567 - size.y - jump_height_limit) {
			position.y -= terminalSpeed - velocity;
		}
		else {
			isJump = false;
		}
	}
	
}

bool Entity::onGround()
{
	return position.y == 567 - size.y;
}

void Entity::update()
{
	if (isJump) {
		jump();
	}
	else {
		fall();
	}
	sprite.setPosition(position);
}

void Entity::render()
{
	window->draw(sprite);
}
