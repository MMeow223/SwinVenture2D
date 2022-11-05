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
	cout << velocity << endl;
	if (position.y < 567 - size.y) {
		position.y += velocity;
	}
	else {
		// when on the ground reset the velocity
		velocity = initVelocity;
		isJump = false;
		//isFall = false;
	}
	//}
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
		if (position.y >= 567 - size.y * 1.5) {
			position.y -= terminalSpeed - velocity;
			//cout << "Jumping" << endl;
		}
		else {
			isJump = false;
			//isFall = true;
		}
	}
	
}

void Entity::update()
{
	// gradually increase the gravity
	//if (velocity < 30) {
	//	velocity *= gravity;
	//}
	//else {
	//	velocity = initVelocity;
	//}
	//cout << velocity << endl;

	//if (position.y < 567 - 150) {
	//	position.y += velocity;
	//}

	//jump();
	if (isJump) {
		jump();
	}
	else {
		fall();
	}
	//if (!isJump) fall();
	//if (isJump) jump();
	//jump();
	sprite.setPosition(position);
}

void Entity::render()
{
	window->draw(sprite);
}
