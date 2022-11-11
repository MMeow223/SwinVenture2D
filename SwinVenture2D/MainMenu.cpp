#include "MainMenu.h"

MainMenu::MainMenu()
{
	cout << "MainMenu init" << endl;
	sceneID = "scene_main_menu";
	
	//window = new sf::RenderWindow(sf::VideoMode(1080, 720), "SwinVenture2D - Main Menu");
	//window->setFramerateLimit(60);
	//window->setKeyRepeatEnabled(false);
	list = new CircularDoublyLinkedList<Content>("->Start/Resume Game\nQuick Introduction\nAbout this game\nAchievement\nExit", 1);
	list->append("Start/Resume Game\nQuick Introduction\nAbout this game\nAchievement\n->Exit", 4);
	list->append("Start/Resume Game\nQuick Introduction\nAbout this game\n->Achievement\nExit", 5);
	list->append("Start/Resume Game\nQuick Introduction\n->About this game\nAchievement\nExit", 3);
	list->append("Start/Resume Game\n->Quick Introduction\nAbout this game\nAchievement\nExit", 2);

	font.loadFromFile("./res/font/Symtext.ttf");

	text->setFont(font);
	text->setString("->Start/Resume Game\nQuick Introduction\nAbout this game\nAchievement\nExit");
	text->setCharacterSize(24);
	text->setFillColor(sf::Color::White);
	text->setPosition(540 - text->getLocalBounds().width / 2, 360 - text->getLocalBounds().height / 2 + 20);

	// create a rectangle in the middle of the screen with 50% opacity (alpha)
	rectangle = sf::RectangleShape(sf::Vector2f(sizex, sizey));
	rectangle.setFillColor(sf::Color(0, 0, 0, 200));
	rectangle.setPosition(540 - sizex / 2, 360 - sizey / 2);

	// sprite and texture
	gameLogoTexture.loadFromFile("./res/images/game-logo.png");
	gameLogoSprite.setTexture(gameLogoTexture);
	gameLogoSprite.setPosition(0, 0);

	mainMenuQuoteText.setFont(font);
	mainMenuQuoteText.setString("Awesome!");
	mainMenuQuoteText.setCharacterSize(40);
	mainMenuQuoteText.setFillColor(sf::Color(255, 255, 0, textBlink));
	mainMenuQuoteText.setOutlineColor(sf::Color(0, 0, 0, textBlink));

	mainMenuQuoteText.setOutlineThickness(1);
	mainMenuQuoteText.setPosition(750, 300);
	mainMenuQuoteText.rotate(-30);
}

MainMenu::MainMenu(sf::RenderWindow* window)
{
	cout << "MainMenu init" << endl;
	sceneID = "scene_main_menu";
	this->window = window;
	list = new CircularDoublyLinkedList<Content>("->Start/Resume Game\nQuick Introduction\nAbout this game\nAchievement\nExit", 1);
	list->append("Start/Resume Game\nQuick Introduction\nAbout this game\nAchievement\n->Exit", 4);
	list->append("Start/Resume Game\nQuick Introduction\nAbout this game\n->Achievement\nExit", 5);
	list->append("Start/Resume Game\nQuick Introduction\n->About this game\nAchievement\nExit", 3);
	list->append("Start/Resume Game\n->Quick Introduction\nAbout this game\nAchievement\nExit", 2);

	font.loadFromFile("./res/font/Symtext.ttf");
	text = new sf::Text();
	text->setFont(font);
	text->setString("->Start/Resume Game\nQuick Introduction\nAbout this game\nAchievement\nExit");
	text->setCharacterSize(24);
	text->setFillColor(sf::Color::White);
	text->setPosition(540 - text->getLocalBounds().width / 2, 360 - text->getLocalBounds().height / 2 + 20);

	// create a rectangle in the middle of the screen with 50% opacity (alpha)
	rectangle = sf::RectangleShape(sf::Vector2f(sizex, sizey));
	rectangle.setFillColor(sf::Color(0, 0, 0, 200));
	rectangle.setPosition(540 - sizex / 2, 360 - sizey / 2);

	// sprite and texture
	gameLogoTexture.loadFromFile("./res/images/game-logo.png");
	gameLogoSprite.setTexture(gameLogoTexture);
	gameLogoSprite.setPosition(0, 0);

	mainMenuQuoteText.setFont(font);
	mainMenuQuoteText.setString("Awesome!");
	mainMenuQuoteText.setCharacterSize(40);
	mainMenuQuoteText.setFillColor(sf::Color(255, 255, 0, textBlink));
	mainMenuQuoteText.setOutlineColor(sf::Color(0, 0, 0, textBlink));

	mainMenuQuoteText.setOutlineThickness(1);
	mainMenuQuoteText.setPosition(750, 300);
	mainMenuQuoteText.rotate(-30);
}

MainMenu::~MainMenu()
{
}

void MainMenu::reset()
{
	this->list = this->list->getStart();
}

void MainMenu::update()
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
	
	text->setString(list->getValue().title);

}

void MainMenu::clean()
{
}

void MainMenu::render()
{
	window->draw(rectangle);
	window->draw(gameLogoSprite);
	window->draw(*text);
	window->draw(mainMenuQuoteText);
	
}
