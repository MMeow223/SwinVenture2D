#include "PopUp.h"

PopUp::PopUp() : Object()
{
	cout << "Init PopUp" << endl;
	
	// init shapes
	popUpBackground = sf::RectangleShape();
	
	// load text and font
	text = "New Achievement Unlock!";
	popUpText = sf::Text();
	font.loadFromFile("./res/font/Symtext.ttf");
	
	// start clock
	clock.restart();
}

PopUp::PopUp(sf::RenderWindow* window, string filepath)
	: Object(window, sf::Vector2f(0,0), sf::Vector2f(0, 0), 0, filepath)
{
	// load text and font
	text = "New Achievement Unlock!";
	font.loadFromFile("./res/font/Symtext.ttf");
	popUpText.setFont(font);
	popUpText.setString(text);
	popUpText.setCharacterSize(20);
	popUpText.setFillColor(sf::Color::White);
	
	// set position
	position = sf::Vector2f(1080, 130);
	sprite.setPosition(position.x + 110, position.y + 130);
	
	// init shape
	popUpBackground = sf::RectangleShape();
	popUpBackground.setFillColor(sf::Color(255, 0, 0, 100));
	popUpBackground.setPosition(position.x + 100, position.y + 100);
	popUpBackground.setSize(sf::Vector2f(sprite.getLocalBounds().width + 20, popUpText.getLocalBounds().height + 20 + sprite.getLocalBounds().height));
	
	// set text position
	popUpText.setPosition(
		popUpBackground.getPosition().x + popUpBackground.getLocalBounds().width/2 - popUpText.getLocalBounds().width/2
		, popUpBackground.getPosition().y + 10);

	// start clock
	clock.restart();
}

PopUp::~PopUp()
{
}

void PopUp::update()
{
	// slide in the pop up and slide out
	if (startShow) {
		// when the pop up fullshown on screen
		if (!turnDirection && popUpBackground.getPosition().x <= 1080 - popUpBackground.getLocalBounds().width) {
			turnDirection = true;
		}

		// when the pop up fully stay on screen for more than 3 seconds,
		// start to slide out
		if (turnDirection && clock.getElapsedTime().asSeconds() >= 3) {
			count = -15;
		}
		else if (!turnDirection) {
			count = 15;
			clock.restart();
		}
		else {
			count = 0;
		}
		
		// finish after fully slide out
		if (popUpBackground.getPosition().x >= 1080 + 500) {
			isFinish = true;
		}

		// set positions
		sprite.setPosition(sprite.getPosition().x - count, sprite.getPosition().y);
		popUpBackground.setPosition(popUpBackground.getPosition().x - count, popUpBackground.getPosition().y);
		popUpText.setPosition(popUpText.getPosition().x - count, popUpText.getPosition().y);
	}
}

void PopUp::render()
{
	// start the slide in and out animation once it start to render
	startShow = true;
	update();
	window->draw(popUpBackground);
	window->draw(popUpText);
	window->draw(sprite);
}
