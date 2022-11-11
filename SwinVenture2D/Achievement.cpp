#include "Achievement.h"

Achievement::Achievement() : Object()
{
	cout << "Init Achievement" << endl;

	this->window = window;
	this->name = name;
	this->description = description;
	this->isUnlocked = isUnlocked;
	this->isHover = false;

}

Achievement::Achievement(sf::RenderWindow* window,
	sf::Vector2f position,
	string filename,
	string name,
	string description
	) : Object(window, position, sf::Vector2f(0, 0), 0, filename)
{
	cout << "Init Achievement" << endl;

	this->window = window;
	this->name = name;
	this->description = description;
	this->isUnlocked = false;
	this->isHover = false;

	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	this->size = sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);
	
	lockTexture.loadFromFile("./res/images/lock.png");
	lockSprite.setTexture(lockTexture);
	lockSprite.setPosition(sprite.getPosition().x + (sprite.getLocalBounds().width / 2) - (lockSprite.getLocalBounds().width / 2),
	sprite.getPosition().y + (sprite.getLocalBounds().height / 2) - (lockSprite.getLocalBounds().height / 2));
	

	font.loadFromFile("./res/font/Symtext.ttf");
	achievementDescriptionText.setFont(font);
	achievementDescriptionText.setString(description);
	achievementDescriptionText.setCharacterSize(20);
	achievementDescriptionText.setFillColor(sf::Color::White);
	achievementDescriptionText.setPosition(position.x + 100, position.y + 100);

	achievementDescriptionBackground = sf::RectangleShape(
		sf::Vector2f(achievementDescriptionText.getLocalBounds().width + 20,
			achievementDescriptionText.getLocalBounds().height + 20)
	);
	achievementDescriptionBackground.setFillColor(sf::Color(255,0,0,100));
	achievementDescriptionBackground.setPosition(achievementDescriptionText.getPosition());
}

Achievement::~Achievement()
{
}


void Achievement::update()
{
	achievementDescriptionText.setString(description);
	achievementDescriptionBackground.setSize(sf::Vector2f(achievementDescriptionText.getLocalBounds().width + 20,
		achievementDescriptionText.getLocalBounds().height + 20));
	
	// get mouse position relative to the window
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
	isHover = (mousePosition.x > position.x
		&& mousePosition.x < position.x + size.x
		&& mousePosition.y > position.y
		&& mousePosition.y < position.y + size.y);
	
	if (isUnlocked) {
		sprite.setColor(sf::Color::White);
	}
	else {
		sprite.setColor(sf::Color(100, 100, 100, 255));
	}
	float tempMouseX = mousePosition.x;
	// if the text description length go beyond the window, then resize the background
	if (mousePosition.x + achievementDescriptionBackground.getLocalBounds().width + 10 > 1080)
	{
		tempMouseX = 1080 - achievementDescriptionBackground.getLocalBounds().width - 10;
	}
	achievementDescriptionText.setPosition(tempMouseX + 10, mousePosition.y + 10);
	achievementDescriptionBackground.setPosition(tempMouseX, mousePosition.y);
}

void Achievement::render()
{
	//cout << "Memory address of texture: " << &texture << endl;
	//cout << "Memory address of sprite: " << &sprite << endl;
	update();
	window->draw(sprite);

	if (!isUnlocked) window->draw(lockSprite);
	
	if (isHover)
	{
		window->draw(achievementDescriptionBackground);
		window->draw(achievementDescriptionText);
	}
	
}
