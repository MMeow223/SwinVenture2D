#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Entity.h"
class Enemy : public Entity
{

private:
	// need to create new sprite and texture, otherwise the getLocalBound() will take from base class
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Text text;
	sf::Font font;
	// two rectangle
	sf::RectangleShape hpBar;
	sf::RectangleShape maxHpBar;
	sf::RectangleShape textBubble;
	string bubbleTextContent;

public:
	Enemy();
	Enemy(sf::RenderWindow* window, string bubbleTextContent = "...", sf::Vector2f position = sf::Vector2f(0, 0));
	~Enemy();
	
	void update();
	void render();

};

