#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
class Entity
{
protected:
	sf::RenderWindow* window;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Texture texture;
	sf::Sprite sprite;
	
	float damage;
	float hp_max;
	float hp;
	float jump_height_limit;
	float initVelocity;
	float velocity;
	float initJumpVelocity;
	float jumpVelocity;
	float gravity;
	float terminalSpeed;
	bool isFall;
	bool isJump;
	bool standOnEnemyHead;

public:
	Entity();
	Entity(sf::RenderWindow* window);
	~Entity();
	//getter
	sf::RenderWindow* getWindow() { return window; }
	sf::Vector2f getPosition() { return position; }
	
	float getInitVelocity() { return initVelocity; }
	float getVelocity() { return velocity; }
	float getInitJumpVelocity() { return initJumpVelocity; }
	float getJumpVelocity() { return jumpVelocity; }
	sf::Vector2f getSize() { return size; }
	sf::Texture getTexture() { return texture; }
	sf::Sprite getSprite() { return sprite; }
	bool getIsFall() { return isFall; }
	bool getIsJump() { return isJump; }
	float getGravity() { return gravity; }
	float getTerminalSpeed() { return terminalSpeed; }
	float getJumpHeightLimit() { return jump_height_limit; }
	float getHpMax() { return hp_max; }
	float getHp() { return hp; }
	float getDamage() { return damage; }
	bool getStandOnEnemyHead() { return standOnEnemyHead; }
	
	

	
	//setter
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void setPosition(sf::Vector2f position) { this->position = position; }
	void setInitVelocity(float initVelocity) { this->initVelocity = initVelocity; }
	void setVelocity(float velocity) { this->velocity = velocity; }
	void setInitJumpVelocity(float initJumpVelocity) { this->initJumpVelocity = initJumpVelocity; }
	void setJumpVelocity(float jumpVelocity) { this->jumpVelocity = jumpVelocity; }
	void setSize(sf::Vector2f size) { this->size = size; }
	void setTexture(sf::Texture texture) { this->texture = texture; }
	void setSprite(sf::Sprite sprite) { this->sprite = sprite; }
	void setIsFall(bool isFall) { this->isFall = isFall; }
	void setIsJump(bool isJump) { this->isJump = isJump; }
	void setGravity(float gravity) { this->gravity = gravity; }
	void setTerminalSpeed(float terminalSpeed) { this->terminalSpeed = terminalSpeed; }
	void setJumpHeightLimit(float jump_height_limit) { this->jump_height_limit = jump_height_limit; }
	void setHpMax(float hp_max) { this->hp_max = hp_max; }
	void setHp(float hp) { this->hp = hp; }
	void setDamage(float damage) { this->damage = damage; }
	void setStandOnEnemyHead(bool standOnEnemyHead) { this->standOnEnemyHead = standOnEnemyHead; }
	
	
	void fall();
	void jump();
	bool onGround();
	bool onEnemyHead();
	void update();
	void render();

};

