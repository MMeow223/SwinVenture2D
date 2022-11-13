#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Entity.h"
class Enemy : public Entity
{

private:
	// sprite and texture
	sf::Sprite sprite;
	sf::Texture texture;

	// text and font
	sf::Text text;
	sf::Font font;
	string bubbleTextContent;

	// shapes
	sf::RectangleShape hpBar;
	sf::RectangleShape maxHpBar;
	sf::RectangleShape textBubble;
	
public:
	Enemy();
	Enemy(sf::RenderWindow* window, string bubbleTextContent = "...", sf::Vector2f position = sf::Vector2f(0, 0));
	~Enemy();
	
	void update();
	void render();

};

