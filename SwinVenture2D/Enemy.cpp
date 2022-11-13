#include "Enemy.h"

Enemy::Enemy()
{
	cout << "Init Enemy" << endl;

	// nullptr because not used
	window = nullptr;

	// load textures
	texture.loadFromFile("./res/images/enemy.png");
	sprite.setTexture(texture);
	this->position = sf::Vector2f(520, 467);
	sprite.setPosition(this->position);
	size = sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);

	// load font and text
	font.loadFromFile("./res/font/Symtext.ttf");
	text.setFont(font);
	text.setString("THIS IS EXAMPLE TEST");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(position);
	
	// set details
	hp_max = 100;
	hp = hp_max;
	jump_height_limit = 100;
	init_velocity = 1;
	velocity = 1.2;
	velocity = init_velocity;
	gravity = 1.08;
	terminalSpeed = 20;
	isFall = false;
	isJump = false;
	
	// set shape
	hpBar = sf::RectangleShape(sf::Vector2f(100, 10));
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setPosition(sf::Vector2f(position.x + 10, position.y - 20));

	maxHpBar = sf::RectangleShape(sf::Vector2f(100, 10));
	maxHpBar.setFillColor(sf::Color::White);
	maxHpBar.setPosition(sf::Vector2f(position.x + 10, position.y - 20));
	
}

Enemy::Enemy(sf::RenderWindow* window, string bubbleTextContent, sf::Vector2f position)
{
	cout << "Init Enemy" << endl;
	
	// set window
	this->window = window;
	
	// count the how many lines in the bubbleTextContent to be used in intialise the height of the shape
	int count = 1;
	for (int i = 0; i < bubbleTextContent.length(); i++)
	{
		if (i % 20 == 0 && i != 0)
		{
			bubbleTextContent.insert(i, "\n");
			count++;
		}
	}
	
	// set details
	this->bubbleTextContent = bubbleTextContent;

	// load textures
	texture.loadFromFile("./res/images/enemy.png");
	sprite.setTexture(texture);
	this->position = position;
	sprite.setPosition(this->position);
	size = sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);

	// load font and text
	font.loadFromFile("./res/font/Symtext.ttf");
	text.setFont(font);
	text.setString(this->bubbleTextContent);
	text.setCharacterSize(18);
	text.setFillColor(sf::Color::Red);
	text.setPosition(position.x, position.y - 60);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	
	// set details
	hp_max = 100;
	hp = hp_max;
	jump_height_limit = 100;
	init_velocity = 2;
	velocity = init_velocity;
	gravity = 1.08;
	terminalSpeed = 20;
	isFall = false;
	isJump = false;

	// set shape
	hpBar = sf::RectangleShape(sf::Vector2f(100, 10));
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setPosition(sf::Vector2f(position.x + 10, position.y - 20));

	maxHpBar = sf::RectangleShape(sf::Vector2f(100, 10));
	maxHpBar.setFillColor(sf::Color::White);
	maxHpBar.setPosition(sf::Vector2f(position.x + 10, position.y - 20));

	textBubble = sf::RectangleShape(sf::Vector2f(20 * (text.getCharacterSize() - 5), count * text.getCharacterSize() + 30));
	textBubble.setFillColor(sf::Color::White);
	textBubble.setOutlineColor(sf::Color::Black);
	textBubble.setOutlineThickness(2);
	textBubble.setOrigin(textBubble.getLocalBounds().width / 2, textBubble.getLocalBounds().height / 2);
	textBubble.setPosition(sf::Vector2f(text.getPosition()));
	
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	// update sprite position
	position.x -=velocity;
	sprite.setPosition(position);
	
	// update text position
	textBubble.setPosition(position.x, position.y - 60);
	text.setPosition(position.x, position.y - 60);
	
	// update hp bar position
	maxHpBar.setPosition(sf::Vector2f(position.x + 10, position.y - 20));
	hpBar.setPosition(sf::Vector2f(position.x + 10, position.y - 20));
	
	// update hp bar size
	hpBar.setSize(sf::Vector2f((hp / hp_max)*100, 10));
}

void Enemy::render()
{
	update();
	window->draw(textBubble);
	window->draw(text);
	window->draw(sprite);
	window->draw(maxHpBar);
	window->draw(hpBar);

}
