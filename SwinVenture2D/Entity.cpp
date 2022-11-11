#include "Entity.h"

Entity::Entity()
{
	cout << "Init Entity" << endl;
	window = nullptr;

	// init the sprite and textuer
	texture.loadFromFile("./res/images/player.png");
	sprite.setTexture(texture);
	position = sf::Vector2f(1080/2 - size.x/2,720-153-size.y);
	sprite.setPosition(position);
	size = sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);

	damage = 20;
	hp_max = 100;
	hp = hp_max;
	jump_height_limit = 300;
	init_velocity = 3;
	velocity = init_velocity;
	initJumpVelocity = 1;
	jumpVelocity = initJumpVelocity;
	gravity = 1.08;
	terminalSpeed = 20;
	isFall = false;
	isJump = false;
	standOnEnemyHead = false;

}

Entity::Entity(sf::RenderWindow* window)
{
	this->window = window;
	
	// init sprite and texture
	texture.loadFromFile("./res/images/player.png");
	sprite.setTexture(texture);
	position = sf::Vector2f(520, -300);
	sprite.setPosition(this->position);
	size = sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

	damage = 20;
	hp_max = 100;
	hp = hp_max;
	jump_height_limit = 300;
	init_velocity = 3;
	velocity = init_velocity;
	initJumpVelocity = 1.7;
	jumpVelocity = initJumpVelocity;
	gravity = 1.08;
	terminalSpeed = 30;
	isFall = false;
	isJump = false;
	standOnEnemyHead = false;
}

Entity::~Entity()
{
}

void Entity::fall()
{
	
	if (jumpVelocity < terminalSpeed) {
		jumpVelocity *= gravity;
	}

	if (standOnEnemyHead) {
		if (position.y < 567 - (189 * 2)) {
			position.y += jumpVelocity;
			cout << "Check" << endl;
		}
		else {
			jumpVelocity = initJumpVelocity;
			position.y = 567 - (189 * 2);
			isJump = false;
		}
	}
	else {
		if (position.y < 567 - size.y) {
			position.y += jumpVelocity;
		}
		else {
			jumpVelocity = initJumpVelocity;
			position.y = 567 - size.y;
			isJump = false;
		}
	}
}

void Entity::jump()
{
	if (jumpVelocity < terminalSpeed * 2) {
	jumpVelocity *= gravity;
	}
	else {
		jumpVelocity = initJumpVelocity;
	}

	float prevPositionY = position.y;
	
	
	if (standOnEnemyHead) {
		if (isJump) {
			
			if (position.y >= 567 - (size.y * 2) - jump_height_limit) {
				position.y -= terminalSpeed - jumpVelocity;
			}
			else {
				isJump = false;
			}
		}
	}
	else {
		if (isJump) {
			if (position.y >= 567 - size.y - jump_height_limit) {
				position.y -= terminalSpeed - jumpVelocity;
			}
			else {
				isJump = false;
			}
		}
	}

	if (position.y > prevPositionY) {
		cout << position.y  << " : " << jumpVelocity << "<---- Problem" << endl;
	}
	else {
		cout << position.y << " : " << jumpVelocity <<  endl;

	}
	
	
}

bool Entity::onGround()
{
	return position.y == 567 - size.y;
}

bool Entity::onEnemyHead()
{
	return position.y == 567 - (size.y * 2);
}

void Entity::update()
{
	if (isJump) {
		jump();
	}
	else {
		fall();
	}
	/*if (isJump || isFall) {
		sprite.rotate(-50);
	}
	else {
		sprite.setRotation(0);
	}*/
	if (!onGround() && !onEnemyHead()) {
		sprite.rotate(10);

	}
	else {
		sprite.setRotation(0);

	}
	
	// need to add the offset of size.y/2 because the origin of the sprite is at the center
	sprite.setPosition(sf::Vector2f(position.x, position.y + size.y/2));
}

void Entity::render()
{
	window->draw(sprite);
}
