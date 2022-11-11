#include "WinGameScene.h"
WinGameScene::WinGameScene()
{
	cout << "LoseGameScene init" << endl;
	sceneID = "scene_lose_game";

	window = nullptr;
	list = new CircularDoublyLinkedList<Content>("->Play Again\nBack To Main Menu\nExit", 1);
	list->append("Play\nBack To Main Menu\n->Exit", 4);
	list->append("Play\n->Back To Main Menu\nExit", 2);

	font.loadFromFile("./res/font/Symtext.ttf");
	text.setFont(font);
	text.setString("->Play\nBack To Main Menu\nExit");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(540 - text.getLocalBounds().width / 2, 360 - text.getLocalBounds().height / 2 + 20);

	// sprite and texture
	texture.loadFromFile("./res/images/win-game.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	mainMenuQuoteText.setFont(font);
	mainMenuQuoteText.setString("Congratulation!");
	mainMenuQuoteText.setCharacterSize(40);
	mainMenuQuoteText.setFillColor(sf::Color(255, 255, 0, textBlink));
	mainMenuQuoteText.setOutlineColor(sf::Color(0, 0, 0, textBlink));

	mainMenuQuoteText.setOutlineThickness(1);
	mainMenuQuoteText.setPosition(100, 400);
	mainMenuQuoteText.rotate(-30);
}

WinGameScene::WinGameScene(sf::RenderWindow* window)
{
	cout << "LoseGameScene init" << endl;
	sceneID = "scene_lose_game";

	this->window = window;
	list = new CircularDoublyLinkedList<Content>("->Play Again\nBack To Main Menu\nExit", 1);
	list->append("Play Again\nBack To Main Menu\n->Exit", 4);
	list->append("Play Again\n->Back To Main Menu\nExit", 2);

	font.loadFromFile("./res/font/Symtext.ttf");
	text.setFont(font);
	text.setString("->Play Again\nBack To Main Menu\nExit");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(540 - text.getLocalBounds().width / 2, 360 - text.getLocalBounds().height / 2 + 80);

	scoreText.setFont(font);
	scoreText.setString("Score: 0");
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(540 - text.getLocalBounds().width / 2, 360 - text.getLocalBounds().height / 2 + 10);
	
	timeText.setFont(font);
	timeText.setString("Time Taken: 0");
	timeText.setCharacterSize(24);
	timeText.setFillColor(sf::Color::White);
	timeText.setPosition(540 - text.getLocalBounds().width / 2, 360 - text.getLocalBounds().height / 2 + 40);

	// sprite and texture
	texture.loadFromFile("./res/images/win-game.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	mainMenuQuoteText.setFont(font);
	mainMenuQuoteText.setString("Congratulation!");
	mainMenuQuoteText.setCharacterSize(40);
	mainMenuQuoteText.setFillColor(sf::Color(255, 255, 0, textBlink));
	mainMenuQuoteText.setOutlineColor(sf::Color(0, 0, 0, textBlink));

	mainMenuQuoteText.setOutlineThickness(1);
	mainMenuQuoteText.setPosition(100, 400);
	mainMenuQuoteText.rotate(-30);
}

WinGameScene::~WinGameScene()
{
}

void WinGameScene::reset()
{
	this->list = this->list->getStart();
}

void WinGameScene::update()
{

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

	text.setString(list->getValue().title);

}

void WinGameScene::clean()
{
}

void WinGameScene::render()
{
	update();
	
	window->draw(sprite);
	window->draw(scoreText);
	window->draw(timeText);
	window->draw(text);
	window->draw(mainMenuQuoteText);

}
