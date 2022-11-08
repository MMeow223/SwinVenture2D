#include "GameIntroScene.h"

GameIntroScene::GameIntroScene() : Scene()
{
	window = nullptr;
	sceneID = "scene_game_intro";
	book = new Book(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/bookcover-intro.png");

	texture.loadFromFile("./res/images/bookcover-intro.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(1080 / 2 - sprite.getLocalBounds().width / 2, 720 / 2 - sprite.getLocalBounds().height / 2));
}

GameIntroScene::GameIntroScene(sf::RenderWindow* window) : Scene()
{
	cout << "GameIntroScene init" << endl;
	sceneID = "scene_game_intro";
	this->window = window;


	book = new Book(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/bookcover-intro.png");
	
	cout << "START ADDING PAGES at book.cpp" << endl;
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/page1.png"));
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/page2.png"));
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/page3.png"));
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/page4.png"));
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/page5.png"));
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/page6.png"));
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/page7.png"));
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/page8.png"));
	book->resetToFirstPage();
	
	texture.loadFromFile("./res/images/bookcover-intro.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(1080 / 2 - sprite.getLocalBounds().width / 2, 720 / 2 - sprite.getLocalBounds().height / 2));

}

GameIntroScene::~GameIntroScene()
{
}

void GameIntroScene::update()
{
	book->update();
}

void GameIntroScene::render()
{
	window->draw(sprite);
	book->render();
}