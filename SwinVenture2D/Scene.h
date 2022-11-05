#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
//#include "Background.h"
//#include <queue>
//#include "CircularDoublyLinkedList.h"
using namespace std;
class Scene
{

protected:
	sf::RenderWindow* window;

public:
	Scene();
	Scene(sf::RenderWindow* window);
	~Scene();

	//getter
	sf::RenderWindow* getWindow() { return window; }

	void update();
	void render();

};

