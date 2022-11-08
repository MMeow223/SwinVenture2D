#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Book.h"

//#include "Background.h"
//#include <queue>
//#include "CircularDoublyLinkedList.h"
using namespace std;
class GameIntroScene : public Scene
{

private:
	sf::Sprite sprite;
	sf::Texture texture;

public:
	GameIntroScene();
	GameIntroScene(sf::RenderWindow* window);
	~GameIntroScene();

	//getter
	//sf::RenderWindow* getWindow() { return window; }
	//Book* getGameIntroBook() { return gameIntroBook; }
	

	void update();
	void render();

};

