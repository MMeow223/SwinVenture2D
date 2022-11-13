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

	// loading achievement icon
	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	this->size = sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);
	
	// loading lock icon
	lockTexture.loadFromFile("./res/images/lock.png");
	lockSprite.setTexture(lockTexture);
	lockSprite.setPosition(sprite.getPosition().x + (sprite.getLocalBounds().width / 2) - (lockSprite.getLocalBounds().width / 2),
	sprite.getPosition().y + (sprite.getLocalBounds().height / 2) - (lockSprite.getLocalBounds().height / 2));
	
	// loading font and text
	font.loadFromFile("./res/font/Symtext.ttf");
	achievementDescriptionText.setFont(font);
	achievementDescriptionText.setString(description);
	achievementDescriptionText.setCharacterSize(20);
	achievementDescriptionText.setFillColor(sf::Color::White);
	achievementDescriptionText.setPosition(position.x + 100, position.y + 100);

	// loading shape
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

void Achievement::checkIsHover(sf::Vector2i& mousePosition)
{
	isHover = (mousePosition.x > position.x
		&& mousePosition.x < position.x + size.x
		&& mousePosition.y > position.y
		&& mousePosition.y < position.y + size.y);
}

void Achievement::update()
{
	// update text content
	achievementDescriptionText.setString(description);
	
	// update shape size
	achievementDescriptionBackground.setSize(sf::Vector2f(achievementDescriptionText.getLocalBounds().width + 20,
		achievementDescriptionText.getLocalBounds().height + 20));
	
	// get mouse position relative to the window
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
	
	// check hover
	checkIsHover(mousePosition);
	
	// update the achievement color based on it unlock state, if it is locked, it will be dimmer color
	if (isUnlocked) {
		sprite.setColor(sf::Color::White);
	}
	else {
		sprite.setColor(sf::Color(100, 100, 100, 255));
	}
	
	// the description text follow mouse positoin
	// if the description text exceed the window, it will be moved to the left to show it fully
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
	update();
	// render the achievement icon
	window->draw(sprite);
	
	// display the lock icon if the achievement is locked
	if (!isUnlocked) window->draw(lockSprite);

	// if the achievement is hovered, display the description
	if (isHover)
	{
		window->draw(achievementDescriptionBackground);
		window->draw(achievementDescriptionText);
	}
}
