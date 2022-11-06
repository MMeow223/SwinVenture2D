#include "Weapon.h"

Weapon::Weapon()
{
	window = nullptr;
	texture.loadFromFile("./res/images/poop.png");
	sprite.setTexture(texture);
	size = sf::Vector2f(79, 143);
	init_position = sf::Vector2f(1080 / 2 - size.x / 2, 720 - 153 - size.y);
	position = init_position;
	
	max_distance = 3;
	damage = 30;
	sprite.setPosition(position);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

	font.loadFromFile("./res/font/Symtext.ttf");
	text.setFont(font);
	text.setString("ATTACK!");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(100, 100);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

Weapon::Weapon(sf::RenderWindow* window,sf::Vector2f position,float max_distance)
{
	this->window = window;
	
	this->init_position = position;
	this->position = init_position;
	
	
	texture.loadFromFile("./res/images/poop.png");
	sprite.setTexture(texture);
	size = sf::Vector2f(sprite.getLocalBounds().width,sprite.getLocalBounds().height);
	//position = sf::Vector2f(1080 / 2 - size.x / 2, 720 - 153 - size.y);
	this->max_distance = max_distance;
	damage = 30;
	sprite.setPosition(position);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

	font.loadFromFile("./res/font/Symtext.ttf");
	text.setFont(font);
	text.setString("ATTACK!");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(100, 100);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

Weapon::~Weapon()
{
}

void Weapon::update()
{
	
	text.rotate(10);
	sprite.rotate(20);
	float x = count ;
	float y = -0.05 * (x * x) + (6.33 * x);
	if (count < 255) {
		count+= 3;
	}
	//if (y >= 0) {
		//cout << y << endl;

	cout << position.y << endl;
	position = sf::Vector2f(count * max_distance + init_position.x, -y + init_position.y);
		sprite.setPosition(position);
		text.setPosition(position);
		//sprite.move(sf::Vector2f(count * 3, -y + 1080 / 2));
	//}
	//else {
		if (-y + init_position.y >= 567) {
			isFinish = true;
		}
		//count = 0;
	//}
	//sprite.setColor(sf::Color(255, 255, 255, 255 - count));
	//text.setFillColor(sf::Color(255, 255, 255, 255-count));
	//y = -x ^ 2 + 20x
		

}

void Weapon::render()
{
	//count++;
	update();
	
	//window->draw(text);
	window->draw(sprite);
}
