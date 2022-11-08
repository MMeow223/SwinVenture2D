#include "GameBackgroundScene.h"


GameBackgroundScene::GameBackgroundScene() : Scene()
{
	window = nullptr;
	sceneID = "scene_game_intro";
	book = new Book(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/bookcover-background.png");

	texture.loadFromFile("./res/images/bookcover-background.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(1080 / 2 - sprite.getLocalBounds().width / 2, 720 / 2 - sprite.getLocalBounds().height / 2));
}

GameBackgroundScene::GameBackgroundScene(sf::RenderWindow* window) : Scene()
{
	cout << "GameIntroScene init" << endl;
	sceneID = "scene_game_intro";
	this->window = window;

	book = new Book(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/bookcover-background.png");

	cout << "START ADDING PAGES at book.cpp" << endl;
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/backgroundpage1.png"));
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/backgroundpage2.png"));
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/backgroundpage3.png"));
	book->addPageAtBack(new Page(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0, "./res/images/backgroundpage4.png"));
	book->resetToFirstPage();
	texture.loadFromFile("./res/images/bookcover-background.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(1080 / 2 - sprite.getLocalBounds().width / 2, 720 / 2 - sprite.getLocalBounds().height / 2));

}

GameBackgroundScene::~GameBackgroundScene()
{
}

void GameBackgroundScene::update()
{
	book->update();
}

void GameBackgroundScene::render()
{
	window->draw(sprite);
	book->render();
}