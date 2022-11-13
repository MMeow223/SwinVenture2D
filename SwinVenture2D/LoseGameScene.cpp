#include "LoseGameScene.h"

LoseGameScene::LoseGameScene()
{
	cout << "LoseGameScene init" << endl;
	sceneID = "scene_lose_game";

	// nullptr because not use
	window = nullptr;

	// init list of options
	list = new CircularDoublyLinkedList<Content>("->Try Again\nBack To Main Menu\nExit", 1);
	list->append("Try Again\nBack To Main Menu\n->Exit", 4);
	list->append("Try Again\n->Back To Main Menu\nExit", 2);

	// load font and text
	font.loadFromFile("./res/font/Symtext.ttf");
	text.setFont(font);
	text.setString("->Try Again\nBack To Main Menu\nExit");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(540 - text.getLocalBounds().width / 2, 360 - text.getLocalBounds().height / 2 + 20);

	mainMenuQuoteText.setFont(font);
	mainMenuQuoteText.setString("Never Gonna Give You Up!");
	mainMenuQuoteText.setCharacterSize(40);
	mainMenuQuoteText.setFillColor(sf::Color(255, 255, 0, textBlink));
	mainMenuQuoteText.setOutlineColor(sf::Color(0, 0, 0, textBlink));
	mainMenuQuoteText.setOutlineThickness(1);
	mainMenuQuoteText.setPosition(100, 400);
	mainMenuQuoteText.rotate(-30);
	
	// load sprite and texture
	texture.loadFromFile("./res/images/lose-game.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	
}

LoseGameScene::LoseGameScene(sf::RenderWindow* window)
{
	cout << "LoseGameScene init" << endl;
	sceneID = "scene_lose_game";
	
	// set window
	this->window = window;
	
	// init list of options
	list = new CircularDoublyLinkedList<Content>("->Try Again\nBack To Main Menu\nExit", 1);
	list->append("Try Again\nBack To Main Menu\n->Exit", 4);
	list->append("Try Again\n->Back To Main Menu\nExit", 2);

	// load text and font
	font.loadFromFile("./res/font/Symtext.ttf");
	text.setFont(font);
	text.setString("->Try Again\nBack To Main Menu\nExit");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(540 - text.getLocalBounds().width / 2, 360 - text.getLocalBounds().height / 2 + 20);

	mainMenuQuoteText.setFont(font);
	mainMenuQuoteText.setString("Never Gonna Give You Up!");
	mainMenuQuoteText.setCharacterSize(40);
	mainMenuQuoteText.setFillColor(sf::Color(255, 255, 0, textBlink));
	mainMenuQuoteText.setOutlineColor(sf::Color(0, 0, 0, textBlink));
	mainMenuQuoteText.setOutlineThickness(1);
	mainMenuQuoteText.setPosition(100, 400);
	mainMenuQuoteText.rotate(-30);
	
	// load sprite and texture
	texture.loadFromFile("./res/images/lose-game.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}

LoseGameScene::~LoseGameScene()
{
}

void LoseGameScene::reset()
{
	this->list = this->list->getStart();
}

void LoseGameScene::update()
{
	// let the quote fade in and fade out
	if (textBlinkUp) {
		textBlink -= blinkspeed;
	}
	else {
		textBlink += blinkspeed;
	}
	if (textBlink <= 0 || textBlink >= 255) {
		textBlinkUp = !textBlinkUp;
	}
	mainMenuQuoteText.setFillColor(sf::Color(255, 255, 0, textBlink));
	mainMenuQuoteText.setOutlineColor(sf::Color(0, 0, 0, textBlink));

	// update the text to the current option
	text.setString(list->getValue().title);
}

void LoseGameScene::clean()
{
}

void LoseGameScene::render()
{
	update();
	window->draw(sprite);
	window->draw(text);
	window->draw(mainMenuQuoteText);

}
